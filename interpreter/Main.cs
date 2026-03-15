using System;
using System.IO;
using Plunt.Interpreter.Core;
using Plunt.Interpreter.Runner;
using Plunt.Interpreter.Sensors;

namespace Plunt.Interpreter
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.InputEncoding = System.Text.Encoding.UTF8;

            string inputCode = GetInputCode(args);

            if (string.IsNullOrWhiteSpace(inputCode))
            {
                PrintUsage();
                return;
            }

            try
            {
                // Create sensor provider (mock for now, can be replaced with real implementation)
                var sensorProvider = new MockSensorProvider();

                // Create interpreter
                using var interpreter = new BotkaInterpreter(sensorProvider);

                // Load and parse the source code
                interpreter.LoadSourceCode(inputCode);

                // Start interactive runner (pass source code for display)
                var runner = new InteractiveRunner(interpreter, sensorProvider, inputCode);
                runner.Run();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[ERROR] {ex.Message}");
                Console.WriteLine();
                Console.WriteLine("Stack trace:");
                Console.WriteLine(ex.StackTrace);
            }
        }

        private static void PrintUsage()
        {
            Console.WriteLine("╔═══════════════════════════════════════════════════════════╗");
            Console.WriteLine("║              Botka Language Interpreter                   ║");
            Console.WriteLine("╚═══════════════════════════════════════════════════════════╝");
            Console.WriteLine();
            Console.WriteLine("Usage:");
            Console.WriteLine("  dotnet BotkaInterpreter.dll [code]           - Run code directly");
            Console.WriteLine("  dotnet BotkaInterpreter.dll < file.botka     - Run from file (stdin)");
            Console.WriteLine("  dotnet BotkaInterpreter.dll                  - Run default example");
            Console.WriteLine();
            Console.WriteLine("Interactive mode commands:");
            Console.WriteLine("  Enter       - Execute next step");
            Console.WriteLine("  n, next     - Execute next step");
            Console.WriteLine("  i, info     - Show detailed information");
            Console.WriteLine("  s, sensor   - Show sensor data");
            Console.WriteLine("  c, run      - Run to completion");
            Console.WriteLine("  g <line>    - Go to line (view only)");
            Console.WriteLine("  h, ?, help  - Show this help");
            Console.WriteLine("  e, exit, q  - Exit interactive mode");
            Console.WriteLine();
            Console.WriteLine("Example files in 'examples/' folder:");
            Console.WriteLine("  forward_4.botka       - Simple forward movement");
            Console.WriteLine("  if_else_chain.botka   - If-else chain example");
            Console.WriteLine("  nested_loops.botka    - Nested loops example");
            Console.WriteLine("  navigation.botka      - Complex navigation");
            Console.WriteLine("  russian_example.botka - Russian keywords example");
            Console.WriteLine();
        }

        private static string GetInputCode(string[] args)
        {
            // Check if first argument is a file path
            if (args.Length > 0)
            {
                string arg = args[0];

                // If it's a file path, read the file
                if (File.Exists(arg))
                {
                    return File.ReadAllText(arg);
                }

                // Otherwise treat as inline code
                return string.Join(" ", args);
            }

            // Default example code for testing
            return @"@start
// Navigate to collect coin
if({} coin) {
    forward 1;
} else {
    forward 5;
};

// Turn right
right 90;

// Move while path is clear
while({} space) {
    forward 1;
};

// For loop - turn 3 times
for(3 times) {
    right 90;
};
@end
";
        }
    }
}
