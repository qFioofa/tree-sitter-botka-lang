using System;
using Plunt.Interpreter.Core;
using Plunt.Interpreter.Sensors;

namespace Plunt.Interpreter.Runner
{
    /// <summary>
    /// Interactive runner that allows step-by-step execution of Botka programs.
    /// User presses Enter to process the next move.
    /// </summary>
    public class InteractiveRunner
    {
        private readonly BotkaInterpreter _interpreter;
        private readonly ISensorProvider _sensorProvider;
        private readonly string[] _sourceLines;
        private int _highlightLine = -1;
        private bool _firstRender = true;

        public InteractiveRunner(BotkaInterpreter interpreter, ISensorProvider sensorProvider, string sourceCode)
        {
            _interpreter = interpreter;
            _sensorProvider = sensorProvider;
            _sourceLines = sourceCode.Split('\n');
        }

        /// <summary>
        /// Runs the interactive mode.
        /// </summary>
        public void Run()
        {
            _firstRender = true;
            _highlightLine = FindFirstCodeLine(); // Start at first code line
            RenderFull();

            while (!_interpreter.IsProgramEnded)
            {
                var input = ReadSafeInput();

                if (input == null) // Ctrl+C or EOF
                {
                    Console.Clear();
                    Console.WriteLine("\nExiting interactive mode...");
                    break;
                }

                input = input.Trim().ToLower();

                Console.Clear();

                if (string.IsNullOrEmpty(input))
                {
                    // Empty input (just Enter) = execute next step
                    ExecuteNextStep();
                }
                else if (input == "i" || input == "info")
                {
                    RenderFull();
                    PrintDetailedInfo();
                }
                else if (input == "s" || input == "sensor")
                {
                    RenderFull();
                    PrintSensorData();
                }
                else if (input == "e" || input == "exit" || input == "q" || input == "quit")
                {
                    Console.WriteLine("Exiting interactive mode...");
                    break;
                }
                else if (input == "h" || input == "help" || input == "?")
                {
                    RenderFull();
                    PrintHelp();
                }
                else if (input == "c" || input == "continue" || input == "run")
                {
                    RunToCompletion();
                    break;
                }
                else if (input == "n" || input == "next")
                {
                    ExecuteNextStep();
                }
                else if (input.StartsWith("goto ") || input.StartsWith("g "))
                {
                    var parts = input.Split(' ');
                    if (parts.Length > 1 && int.TryParse(parts[1], out int line))
                    {
                        _highlightLine = line - 1;
                        RenderFull();
                    }
                    else
                    {
                        RenderFull();
                        Console.WriteLine("[!] Usage: goto <line> or g <line>");
                    }
                }
                else
                {
                    RenderFull();
                    Console.WriteLine("[!] Unknown command. Type 'h' or '?' for help.");
                }
            }

            PrintFinalState();
        }

        /// <summary>
        /// Safely reads input, handling special characters that might cause issues.
        /// Returns null on Ctrl+C or EOF.
        /// </summary>
        private string? ReadSafeInput()
        {
            try
            {
                return Console.ReadLine();
            }
            catch (InvalidOperationException)
            {
                // Console input closed
                return null;
            }
            catch (Exception)
            {
                // Any other error reading input
                return null;
            }
        }

        /// <summary>
        /// Finds the first line that contains actual code (not @start, comments, or empty lines).
        /// </summary>
        private int FindFirstCodeLine()
        {
            for (int i = 0; i < _sourceLines.Length; i++)
            {
                var line = _sourceLines[i].Trim();
                // Skip empty lines, comments, @start, @end
                if (string.IsNullOrEmpty(line) ||
                    line.StartsWith("//") ||
                    line.StartsWith("/*") ||
                    line.StartsWith("*") ||
                    line.StartsWith("@start") ||
                    line.StartsWith("@начало") ||
                    line.StartsWith("@end") ||
                    line.StartsWith("@конец"))
                {
                    continue;
                }
                return i;
            }
            return 0; // Default to first line
        }

        private void RenderFull()
        {
            if (_firstRender)
            {
                PrintHeader();
                PrintProgramInfo();
                _firstRender = false;
            }

            PrintSourceCodeView();
            PrintCurrentState();
            PrintPrompt();
        }

        private void PrintHeader()
        {
            Console.WriteLine();
            Console.WriteLine("╔═══════════════════════════════════════════════════════════╗");
            Console.WriteLine("║           Botka Language Interactive Interpreter          ║");
            Console.WriteLine("╚═══════════════════════════════════════════════════════════╝");
            Console.WriteLine();
        }

        private void PrintProgramInfo()
        {
            Console.WriteLine($"Total actions: {_interpreter.TotalActions}");
            Console.WriteLine();
        }

        private void PrintSourceCodeView()
        {
            // Update highlight line based on current execution (only after first step)
            if (!_firstRender && _interpreter.CurrentStep > 0)
            {
                var currentLine = _interpreter.CurrentLineNumber - 1; // 0-indexed
                if (currentLine >= 0 && currentLine < _sourceLines.Length)
                {
                    _highlightLine = currentLine;
                }
            }

            Console.WriteLine("═══ Source Code ═══");

            int windowSize = 7; // Show 7 lines at a time
            int startLine, endLine;

            if (_highlightLine < 0)
            {
                // No highlight yet, show first lines
                startLine = 0;
                endLine = Math.Min(_sourceLines.Length, windowSize);
            }
            else
            {
                // Center the highlight line in the window
                int halfWindow = windowSize / 2;
                startLine = Math.Max(0, _highlightLine - halfWindow);
                endLine = Math.Min(_sourceLines.Length, startLine + windowSize);

                // Adjust if we're near the end
                if (endLine - startLine < windowSize)
                {
                    startLine = Math.Max(0, endLine - windowSize);
                }
            }

            for (int i = startLine; i < endLine; i++)
            {
                var line = _sourceLines[i];
                var lineNum = i + 1;

                if (i == _highlightLine)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write($"> {lineNum,3} │ ");
                    // Remove trailing whitespace for cleaner display
                    Console.WriteLine(line.TrimEnd());
                    Console.ResetColor();
                }
                else
                {
                    Console.WriteLine($"  {lineNum,3} │ {line.TrimEnd()}");
                }
            }

            if (endLine < _sourceLines.Length)
            {
                Console.WriteLine("  ... │ ...");
            }
            Console.WriteLine();
        }

        private void PrintCurrentState()
        {
            Console.WriteLine("─".PadRight(60, '─'));
            Console.WriteLine($"Step: {_interpreter.CurrentStep + 1} / {_interpreter.TotalActions}");
            Console.WriteLine($"Line: {_interpreter.CurrentLineNumber}");
            Console.WriteLine();
        }

        private void PrintPrompt()
        {
            var nextAction = _interpreter.PeekNext();
            Console.Write($"[Step {_interpreter.CurrentStep + 1}] Next: {nextAction.Type}");
            if (nextAction.Magnitude != 0)
            {
                Console.Write($"({nextAction.Magnitude})");
            }
            Console.WriteLine(" | Press Enter to execute: ");
        }

        private void ExecuteNextStep()
        {
            var action = _interpreter.Next();

            Console.WriteLine($"  ▶ Executing: {action.Description}");
            Console.WriteLine($"    Source: Line {action.SourceLineNumber + 1}");

            // Update sensor state based on action (for simulation purposes)
            UpdateSensorState(action);

            Console.WriteLine($"  ✓ Completed");
            Console.WriteLine();

            RenderFull();
        }

        private void UpdateSensorState(Actions.BotAction action)
        {
            // This is a simple simulation - in real use, the sensor provider
            // would be updated by the actual environment
            if (action.Type == Actions.ActionType.Forward &&
                _sensorProvider is MockSensorProvider mock)
            {
                // Simulate moving through different instances
                mock.GetInstanceInFront();
            }
        }

        private void PrintDetailedInfo()
        {
            Console.WriteLine("═══ Detailed Information ═══");
            Console.WriteLine($"Current Step: {_interpreter.CurrentStep}");
            Console.WriteLine($"Total Actions: {_interpreter.TotalActions}");
            Console.WriteLine($"Remaining Actions: {_interpreter.RemainingActions}");
            Console.WriteLine($"Current Line: {_interpreter.CurrentLineNumber}");
            Console.WriteLine($"Current Column: {_interpreter.CurrentColumn}");
            Console.WriteLine($"Program Ended: {_interpreter.IsProgramEnded}");

            var nextAction = _interpreter.PeekNext();
            Console.WriteLine($"Next Action: {nextAction.Type} ({nextAction.Magnitude})");
            Console.WriteLine($"Next Action Source: Line {nextAction.SourceLineNumber + 1}, Column {nextAction.SourceColumn + 1}");
            Console.WriteLine();
        }

        private void PrintSensorData()
        {
            Console.WriteLine("═══ Sensor Data ═══");
            Console.WriteLine($"Coin in front: {_sensorProvider.IsCoinInFront()}");
            Console.WriteLine($"Object in front: {_sensorProvider.IsObjectInFront()}");
            Console.WriteLine($"Space in front: {_sensorProvider.IsSpaceInFront()}");
            Console.WriteLine();
        }

        private void PrintHelp()
        {
            Console.WriteLine("═══ Available Commands ═══");
            Console.WriteLine("  Enter       - Execute next step");
            Console.WriteLine("  n, next     - Execute next step");
            Console.WriteLine("  i, info     - Show detailed information");
            Console.WriteLine("  s, sensor   - Show sensor data");
            Console.WriteLine("  c, run      - Run to completion");
            Console.WriteLine("  g <line>    - Go to line (view only)");
            Console.WriteLine("  h, ?, help  - Show this help");
            Console.WriteLine("  e, exit, q  - Exit interactive mode");
            Console.WriteLine();
        }

        private void RunToCompletion()
        {
            Console.WriteLine("Running to completion...");
            Console.WriteLine();

            while (!_interpreter.IsProgramEnded)
            {
                var action = _interpreter.Next();
                Console.WriteLine($"  [{_interpreter.CurrentStep}] {action.Description} (Line {action.SourceLineNumber + 1})");
                UpdateSensorState(action);
            }
        }

        private void PrintFinalState()
        {
            Console.Clear();
            Console.WriteLine();
            Console.WriteLine("╔═══════════════════════════════════════════════════════════╗");
            Console.WriteLine("║                   Execution Complete                      ║");
            Console.WriteLine("╚═══════════════════════════════════════════════════════════╝");
            Console.WriteLine();
            Console.WriteLine($"Total steps executed: {_interpreter.TotalActions}");
            Console.WriteLine();
        }
    }
}
