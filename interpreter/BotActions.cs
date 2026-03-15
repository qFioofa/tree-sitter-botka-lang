namespace Plunt.Interpreter.Actions
{
    /// <summary>
    /// Represents the type of action the bot can perform.
    /// </summary>
    public enum ActionType
    {
        None,
        Forward,
        Backwards,
        Right,
        Left,
        EndProgram
    }

    /// <summary>
    /// Represents an action to be executed by the bot.
    /// </summary>
    public class BotAction
    {
        public ActionType Type { get; }
        public int Magnitude { get; }
        public string? Description { get; }
        public int SourceLineNumber { get; }
        public int SourceColumn { get; }

        public BotAction(ActionType type, int magnitude = 0, string? description = null, 
                        int sourceLineNumber = -1, int sourceColumn = -1)
        {
            Type = type;
            Magnitude = magnitude;
            Description = description ?? type.ToString();
            SourceLineNumber = sourceLineNumber;
            SourceColumn = sourceColumn;
        }

        public static BotAction None(int lineNumber = -1, int column = -1) =>
            new BotAction(ActionType.None, 0, "No operation", lineNumber, column);

        public static BotAction Forward(int steps, int lineNumber = -1, int column = -1) =>
            new BotAction(ActionType.Forward, steps, $"Move forward {steps} step(s)", lineNumber, column);

        public static BotAction Backwards(int steps, int lineNumber = -1, int column = -1) =>
            new BotAction(ActionType.Backwards, steps, $"Move backwards {steps} step(s)", lineNumber, column);

        public static BotAction Right(int degrees, int lineNumber = -1, int column = -1) =>
            new BotAction(ActionType.Right, degrees, $"Turn right {degrees} degree(s)", lineNumber, column);

        public static BotAction Left(int degrees, int lineNumber = -1, int column = -1) =>
            new BotAction(ActionType.Left, degrees, $"Turn left {degrees} degree(s)", lineNumber, column);

        public static BotAction EndProgram(int lineNumber = -1, int column = -1) =>
            new BotAction(ActionType.EndProgram, 0, "Program ended", lineNumber, column);

        public override string ToString() => Description ?? Type.ToString();
    }

    /// <summary>
    /// Result of executing a bot action.
    /// </summary>
    public class ActionResult
    {
        public bool Success { get; }
        public string? Message { get; }

        public ActionResult(bool success, string? message = null)
        {
            Success = success;
            Message = message;
        }

        public static ActionResult Ok(string? message = null) => new ActionResult(true, message);
        public static ActionResult Fail(string? message = null) => new ActionResult(false, message);
    }
}
