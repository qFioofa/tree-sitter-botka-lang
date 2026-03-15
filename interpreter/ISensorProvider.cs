namespace Plunt.Interpreter.Sensors
{
    /// <summary>
    /// Represents the type of instance that can be detected in front of the robot.
    /// </summary>
    public enum InstanceType
    {
        None,
        Coin,
        Object,
        Space
    }

    /// <summary>
    /// Interface for providing sensor data to the interpreter.
    /// Implement this interface to provide real-world sensor data.
    /// </summary>
    public interface ISensorProvider
    {
        /// <summary>
        /// Checks if there is a coin in front of the robot.
        /// </summary>
        bool IsCoinInFront();

        /// <summary>
        /// Checks if there is an object in front of the robot.
        /// </summary>
        bool IsObjectInFront();

        /// <summary>
        /// Checks if there is empty space in front of the robot.
        /// </summary>
        bool IsSpaceInFront();

        /// <summary>
        /// Gets the current instance type in front of the robot.
        /// </summary>
        InstanceType GetInstanceInFront();
    }
}
