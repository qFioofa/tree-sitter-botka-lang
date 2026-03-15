using System;
using System.Collections.Generic;
using Plunt.Interpreter.Actions;
using Plunt.Interpreter.Bindings;
using Plunt.Interpreter.Sensors;

namespace Plunt.Interpreter.Core
{
    /// <summary>
    /// Main interpreter class that parses Botka language and executes commands step by step.
    /// </summary>
    public class BotkaInterpreter : IDisposable
    {
        private readonly TreeSitterBinding _binding;
        private readonly ISensorProvider _sensorProvider;
        private readonly List<BotAction> _actionQueue;
        private readonly Stack<LoopContext> _loopStack;
        private int _currentActionIndex;
        private bool _isProgramEnded;
        private int _currentLineNumber;
        private int _currentColumn;
        private string _sourceCode;

        private TreeSitterNode? _currentStatementNode;

        public BotkaInterpreter(ISensorProvider? sensorProvider = null)
        {
            _binding = new TreeSitterBinding();
            _sensorProvider = sensorProvider ?? new MockSensorProvider();
            _actionQueue = new List<BotAction>();
            _loopStack = new Stack<LoopContext>();
            _currentActionIndex = 0;
            _isProgramEnded = false;
            _currentLineNumber = 0;
            _currentColumn = 0;
            _sourceCode = string.Empty;
        }

        /// <summary>
        /// Gets the current line number in the source code.
        /// </summary>
        public int CurrentLineNumber => _currentLineNumber + 1;

        /// <summary>
        /// Gets the current column in the source code.
        /// </summary>
        public int CurrentColumn => _currentColumn + 1;

        /// <summary>
        /// Gets the current statement node being processed.
        /// </summary>
        public TreeSitterNode? CurrentStatementNode => _currentStatementNode;

        /// <summary>
        /// Gets whether the program has ended.
        /// </summary>
        public bool IsProgramEnded => _isProgramEnded;

        /// <summary>
        /// Gets the current action index (step number).
        /// </summary>
        public int CurrentStep => _currentActionIndex;

        /// <summary>
        /// Loads and parses the source code.
        /// </summary>
        public void LoadSourceCode(string sourceCode)
        {
            _sourceCode = sourceCode;
            var tree = _binding.Parse(sourceCode);

            if (tree.HasErrors)
            {
                throw new InvalidOperationException($"Syntax errors in source code: {tree.GetError()}");
            }

            _actionQueue.Clear();
            ProcessProgramNode(tree.RootNode);
            _currentActionIndex = 0;
            _isProgramEnded = false;
        }

        /// <summary>
        /// Gets the next action to execute.
        /// Returns None action if program is ended or no more actions.
        /// </summary>
        public BotAction Next()
        {
            if (_isProgramEnded || _currentActionIndex >= _actionQueue.Count)
            {
                _isProgramEnded = true;
                return BotAction.EndProgram(_currentLineNumber, _currentColumn);
            }

            var action = _actionQueue[_currentActionIndex];
            _currentActionIndex++;

            // Update current line/column to match the action being executed
            _currentLineNumber = action.SourceLineNumber;
            _currentColumn = action.SourceColumn;

            return action;
        }

        /// <summary>
        /// Peeks at the next action without advancing the counter.
        /// </summary>
        public BotAction PeekNext()
        {
            if (_isProgramEnded || _currentActionIndex >= _actionQueue.Count)
            {
                return BotAction.EndProgram(_currentLineNumber, _currentColumn);
            }

            return _actionQueue[_currentActionIndex];
        }

        /// <summary>
        /// Gets the total number of actions in the program.
        /// </summary>
        public int TotalActions => _actionQueue.Count;

        /// <summary>
        /// Gets the remaining number of actions.
        /// </summary>
        public int RemainingActions => _actionQueue.Count - _currentActionIndex;

        private void ProcessProgramNode(TreeSitterNode node)
        {
            if (node.Type == "program" || node.Type == "source_file")
            {
                foreach (var child in node.Children)
                {
                    ProcessNode(child);
                }
            }
            else
            {
                ProcessNode(node);
            }
        }

        private void ProcessNode(TreeSitterNode node)
        {
            _currentLineNumber = node.StartLine;
            _currentStatementNode = node;

            switch (node.Type)
            {
                case "start_directive":
                    // @start - just skip
                    break;

                case "end_directive":
                    // @end - mark program end
                    _isProgramEnded = true;
                    break;

                case "if_statement":
                    ProcessIfStatement(node);
                    break;

                case "while_statement":
                    ProcessWhileStatement(node);
                    break;

                case "for_statement":
                    ProcessForStatement(node);
                    break;

                case "action_statement":
                    ProcessActionStatement(node);
                    break;

                case "comment":
                    // Skip comments
                    break;
            }
        }

        private void ProcessIfStatement(TreeSitterNode node)
        {
            var conditionNode = GetChildByType(node, "condition");
            var thenBlockNode = GetChildByType(node, "block");
            var elseBlockNode = GetChildByType(node, "else_clause");

            if (conditionNode == null)
            {
                return;
            }

            bool conditionResult = EvaluateCondition(conditionNode);

            if (conditionResult)
            {
                if (thenBlockNode != null)
                {
                    ProcessBlock(thenBlockNode);
                }
            }
            else
            {
                if (elseBlockNode != null)
                {
                    // Check if it's else-if or just else
                    var elseIfNode = GetChildByType(elseBlockNode, "if_statement");
                    if (elseIfNode != null)
                    {
                        ProcessIfStatement(elseIfNode);
                    }
                    else
                    {
                        var elseBlock = GetChildByType(elseBlockNode, "block");
                        if (elseBlock != null)
                        {
                            ProcessBlock(elseBlock);
                        }
                    }
                }
            }
        }

        private void ProcessWhileStatement(TreeSitterNode node)
        {
            var conditionNode = GetChildByType(node, "condition");
            var bodyNode = GetChildByType(node, "block");

            if (conditionNode == null || bodyNode == null)
            {
                return;
            }

            // Create a loop context for while
            var loopContext = new LoopContext
            {
                ConditionNode = conditionNode,
                BodyNode = bodyNode,
                IsWhileLoop = true
            };

            // Execute while condition is true
            int maxIterations = 1000; // Prevent infinite loops
            int iterations = 0;

            while (EvaluateCondition(conditionNode) && iterations < maxIterations)
            {
                ProcessBlock(bodyNode);
                iterations++;
            }
        }

        private void ProcessForStatement(TreeSitterNode node)
        {
            var countNode = GetChildByType(node, "number");
            var bodyNode = GetChildByType(node, "block");

            if (countNode == null || bodyNode == null)
            {
                return;
            }

            if (int.TryParse(countNode.Text, out int count) && count > 0)
            {
                for (int i = 0; i < count; i++)
                {
                    ProcessBlock(bodyNode);
                }
            }
        }

        private void ProcessBlock(TreeSitterNode blockNode)
        {
            foreach (var child in blockNode.Children)
            {
                if (child.Type != "{" && child.Type != "}")
                {
                    ProcessNode(child);
                }
            }
        }

        private void ProcessActionStatement(TreeSitterNode node)
        {
            var actionType = GetChildByType(node, "action_type");
            var numberNode = GetChildByType(node, "number");

            if (actionType == null)
            {
                return;
            }

            int magnitude = 0;
            if (numberNode != null && int.TryParse(numberNode.Text, out int parsedNumber))
            {
                magnitude = parsedNumber;
            }

            _currentLineNumber = node.StartLine;
            _currentColumn = node.StartColumn;

            // Get the action type text (could be English or Russian)
            var actionText = actionType.Text.ToLower().Trim();

            BotAction action = actionText switch
            {
                "forward" or "вперед" => BotAction.Forward(magnitude, _currentLineNumber, _currentColumn),
                "backwards" or "назад" => BotAction.Backwards(magnitude, _currentLineNumber, _currentColumn),
                "right" or "вправо" => BotAction.Right(magnitude, _currentLineNumber, _currentColumn),
                "left" or "влево" => BotAction.Left(magnitude, _currentLineNumber, _currentColumn),
                _ => BotAction.None(_currentLineNumber, _currentColumn)
            };

            _actionQueue.Add(action);
        }

        private bool EvaluateCondition(TreeSitterNode conditionNode)
        {
            var notNode = GetChildByType(conditionNode, "not_modifier");
            var instanceNode = GetChildByType(conditionNode, "instance");

            if (instanceNode == null)
            {
                return false;
            }

            // Get the actual instance text (could be English or Russian)
            var instanceText = instanceNode.Text.ToLower().Trim();
            
            // Map both English and Russian keywords to the same check
            bool result = instanceText switch
            {
                "coin" or "монета" => _sensorProvider.IsCoinInFront(),
                "obj" or "объект" => _sensorProvider.IsObjectInFront(),
                "space" or "пусто" => _sensorProvider.IsSpaceInFront(),
                _ => false
            };

            return notNode != null ? !result : result;
        }

        private TreeSitterNode? GetChildByType(TreeSitterNode node, string type)
        {
            foreach (var child in node.Children)
            {
                if (child.Type == type)
                {
                    return child;
                }

                // Recursively search in children
                var found = GetChildByType(child, type);
                if (found != null)
                {
                    return found;
                }
            }
            return null;
        }

        public void Dispose()
        {
            _binding.Dispose();
        }

        private class LoopContext
        {
            public TreeSitterNode? ConditionNode { get; set; }
            public TreeSitterNode? BodyNode { get; set; }
            public bool IsWhileLoop { get; set; }
            public int RemainingIterations { get; set; }
        }
    }
}
