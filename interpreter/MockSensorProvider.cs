namespace Plunt.Interpreter.Sensors
{
    /// <summary>
    /// Mock implementation of ISensorProvider for testing purposes.
    /// Allows setting predefined sensor states.
    /// </summary>
    public class MockSensorProvider : ISensorProvider
    {
        private InstanceType _currentInstance = InstanceType.Space;
        private Queue<InstanceType>? _instanceSequence;

        /// <summary>
        /// Sets the current instance type in front of the robot.
        /// </summary>
        public void SetInstanceInFront(InstanceType instanceType)
        {
            _currentInstance = instanceType;
        }

        /// <summary>
        /// Sets a sequence of instances to simulate movement through the environment.
        /// </summary>
        public void SetInstanceSequence(IEnumerable<InstanceType> sequence)
        {
            _instanceSequence = new Queue<InstanceType>(sequence);
        }

        public bool IsCoinInFront()
        {
            if (_instanceSequence != null && _instanceSequence.Count > 0)
            {
                _currentInstance = _instanceSequence.Dequeue();
            }
            return _currentInstance == InstanceType.Coin;
        }

        public bool IsObjectInFront()
        {
            if (_instanceSequence != null && _instanceSequence.Count > 0)
            {
                _currentInstance = _instanceSequence.Dequeue();
            }
            return _currentInstance == InstanceType.Object;
        }

        public bool IsSpaceInFront()
        {
            if (_instanceSequence != null && _instanceSequence.Count > 0)
            {
                _currentInstance = _instanceSequence.Dequeue();
            }
            else
            {
                // After sequence is exhausted, return false to stop while loops
                _currentInstance = InstanceType.Object;
            }
            return _currentInstance == InstanceType.Space;
        }

        public InstanceType GetInstanceInFront()
        {
            if (_instanceSequence != null && _instanceSequence.Count > 0)
            {
                _currentInstance = _instanceSequence.Dequeue();
            }
            else
            {
                // After sequence is exhausted, return Object to stop while loops
                _currentInstance = InstanceType.Object;
            }
            return _currentInstance;
        }
    }
}
