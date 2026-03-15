# Botka Interpreter Documentation

The Botka Interpreter is a C#-based interactive interpreter for executing Botka language programs with step-by-step debugging capabilities.

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Quick Start](#quick-start)
- [Usage Modes](#usage-modes)
  - [Command Line](#command-line)
  - [Interactive Mode](#interactive-mode)
  - [As a Library](#as-a-library)
- [Architecture](#architecture)
- [API Reference](#api-reference)
- [Customization](#customization)
- [Advanced Usage](#advanced-usage)
- [Troubleshooting](#troubleshooting)

---

## Overview

The Botka Interpreter provides:

| Feature | Description |
|---------|-------------|
| **Step-by-step execution** | Execute programs one action at a time |
| **Interactive debugging** | Inspect state at each step |
| **Sensor simulation** | Mock sensor data for testing |
| **Extensible architecture** | Plug in custom sensor providers |
| **Bilingual support** | English and Russian keywords |

### System Requirements

| Component | Version | Required |
|-----------|---------|----------|
| .NET SDK | 8.0+ | Yes |
| Tree-sitter DLL | Latest | Yes |
| GCC (for build) | Latest | For compilation |

---

## Installation

### Build from Source

```bash
# Clone repository
git clone https://github.com/qFioofa/tree-sitter-botka-lang
cd tree-sitter-botka-lang

# Make scripts executable
chmod +x scripts/*.sh

# Build everything
./scripts/build.sh

# Or build interpreter only
./scripts/build_interpreter.sh
```

### Build Output

```
build/
├── BotkaInterpreter.dll    # Main interpreter
├── BotkaInterpreter.exe    # Windows executable
└── [dependencies]
```

---

## Quick Start

### Run with Code String

```bash
cd build
dotnet BotkaInterpreter.dll '@start forward 5; @end'
```

### Run from File

```bash
cd build
dotnet BotkaInterpreter.dll '../examples/forward_4.botka'
```

### Interactive Mode

```bash
cd build
dotnet BotkaInterpreter.dll
```

---

## Usage Modes

### Command Line

#### Execute Complete Program

```bash
# Run and execute all actions immediately
cd build
dotnet BotkaInterpreter.dll '../examples/all_in.botka'
```

#### Run with Code Argument

```bash
# Pass code directly as argument
dotnet BotkaInterpreter.dll '@start
if({} coin) {
    forward 1;
} else {
    right 90;
}
@end'
```

### Interactive Mode

Start without arguments to enter interactive mode:

```bash
cd build
dotnet BotkaInterpreter.dll
```

#### Interactive Commands

| Command | Aliases | Description |
|---------|---------|-------------|
| `next` | `space`, `n` | Execute next action |
| `info` | — | Show detailed execution info |
| `sensor` | — | Show current sensor data |
| `continue` | `c` | Run all remaining actions |
| `help` | `h` | Show help menu |
| `quit` | `exit`, `q` | Exit interpreter |

#### Example Session

```
╔═══════════════════════════════════════════════════════════╗
║           Botka Language Interactive Interpreter          ║
╚═══════════════════════════════════════════════════════════╝

Total actions: 4

────────────────────────────────────────────────────────────
Step: 1 / 4
Line: 2

[Step 1] Next: Forward(1) | Press 'space' to execute: space

  ▶ Executing: Move forward 1 step(s)
    Source: Line 2
  ✓ Completed

────────────────────────────────────────────────────────────
Step: 2 / 4
Line: 2

[Step 2] Next: Right(90) | Press 'space' to execute: info

Execution Info:
  - Total Actions: 4
  - Current Step: 2
  - Line: 2
  - Column: 5
  - Remaining: 2 actions
```

### As a Library

Embed the interpreter in your C# applications.

#### Basic Usage

```csharp
using BotkaInterpreter;

// Create interpreter with mock sensor
var sensorProvider = new MockSensorProvider();
var interpreter = new BotkaInterpreter(sensorProvider);

// Load code
interpreter.LoadCode(@"
    @start
    forward 5;
    right 90;
    @end
");

// Execute step by step
while (interpreter.HasNext())
{
    var result = interpreter.Next();
    Console.WriteLine($"Executed: {result}");
}
```

#### Custom Sensor Provider

```csharp
using BotkaInterpreter;

public class MySensorProvider : ISensorProvider
{
    private readonly Func<bool> _coinChecker;
    private readonly Func<bool> _objectChecker;
    private readonly Func<bool> _spaceChecker;

    public MySensorProvider(
        Func<bool> coinChecker,
        Func<bool> objectChecker,
        Func<bool> spaceChecker)
    {
        _coinChecker = coinChecker;
        _objectChecker = objectChecker;
        _spaceChecker = spaceChecker;
    }

    public bool IsCoinInFront() => _coinChecker();
    public bool IsObjectInFront() => _objectChecker();
    public bool IsSpaceInFront() => _spaceChecker();

    public InstanceType GetInstanceInFront()
    {
        if (IsCoinInFront()) return InstanceType.Coin;
        if (IsObjectInFront()) return InstanceType.Obj;
        if (IsSpaceInFront()) return InstanceType.Space;
        return InstanceType.None;
    }
}

// Usage
var mySensor = new MySensorProvider(
    () => true,   // Coin detected
    () => false,  // No object
    () => false   // Not empty
);

var interpreter = new BotkaInterpreter(mySensor);
```

---

## Architecture

### Component Diagram

```
┌─────────────────────────────────────────────────────────┐
│                   BotkaInterpreter                       │
├─────────────────────────────────────────────────────────┤
│  ┌─────────────────┐    ┌────────────────────────────┐  │
│  │  TreeSitter     │    │   BotActions               │  │
│  │  Bindings       │───▶│   - ActionType             │  │
│  │                 │    │   - BotActionResult        │  │
│  └─────────────────┘    └────────────────────────────┘  │
│           │                        │                     │
│           ▼                        ▼                     │
│  ┌─────────────────┐    ┌────────────────────────────┐  │
│  │  Syntax Tree    │    │   BotkaInterpreter         │  │
│  │  (Parsed Code)  │    │   - LoadCode()             │  │
│  └─────────────────┘    │   - Next()                 │  │
│                         │   - HasNext()              │  │
│                         │   - GetInfo()              │  │
│                         └────────────────────────────┘  │
│                                          │              │
│                                          ▼              │
│                         ┌────────────────────────────┐  │
│                         │   ISensorProvider          │  │
│                         │   - IsCoinInFront()        │  │
│                         │   - IsObjectInFront()      │  │
│                         │   - IsSpaceInFront()       │  │
│                         └────────────────────────────┘  │
│                                          ▲              │
│                         ┌────────────────┴──────┐      │
│                         │  MockSensorProvider   │      │
│                         │  (Default impl)       │      │
│                         └───────────────────────┘      │
└─────────────────────────────────────────────────────────┘
```

### Core Components

| Component | File | Purpose |
|-----------|------|---------|
| `BotkaInterpreter` | `BotkaInterpreter.cs` | Main execution engine |
| `BotActions` | `BotActions.cs` | Action types and results |
| `TreeSitterBindings` | `TreeSitterBindings.cs` | Parser integration |
| `ISensorProvider` | `ISensorProvider.cs` | Sensor interface |
| `MockSensorProvider` | `MockSensorProvider.cs` | Default sensor implementation |
| `InteractiveRunner` | `InteractiveRunner.cs` | Interactive mode handler |
| `Main` | `Main.cs` | Entry point and CLI |

---

## API Reference

### BotkaInterpreter Class

#### Constructor

```csharp
public BotkaInterpreter(ISensorProvider sensorProvider)
```

**Parameters:**
- `sensorProvider` - Implementation of sensor interface

**Example:**
```csharp
var interpreter = new BotkaInterpreter(new MockSensorProvider());
```

---

#### LoadCode

```csharp
public void LoadCode(string code)
```

Load Botka code for execution.

**Parameters:**
- `code` - Botka source code string

**Example:**
```csharp
interpreter.LoadCode("@start forward 5; @end");
```

---

#### LoadFile

```csharp
public void LoadFile(string path)
```

Load Botka code from file.

**Parameters:**
- `path` - Path to `.botka` file

**Example:**
```csharp
interpreter.LoadFile("examples/forward_4.botka");
```

---

#### HasNext

```csharp
public bool HasNext()
```

Check if there are more actions to execute.

**Returns:** `true` if more actions exist

**Example:**
```csharp
while (interpreter.HasNext())
{
    // Execute next action
}
```

---

#### Next

```csharp
public BotActionResult Next()
```

Execute the next action.

**Returns:** `BotActionResult` with execution details

**Example:**
```csharp
var result = interpreter.Next();
Console.WriteLine($"Action: {result.ActionType}, Value: {result.Value}");
```

---

#### GetInfo

```csharp
public ExecutionInfo GetInfo()
```

Get current execution state information.

**Returns:** `ExecutionInfo` object with:
- `TotalActions` - Total actions in program
- `CurrentStep` - Current step number
- `LineNumber` - Current line in source
- `Column` - Current column in source
- `RemainingActions` - Actions left to execute

**Example:**
```csharp
var info = interpreter.GetInfo();
Console.WriteLine($"Step {info.CurrentStep}/{info.TotalActions}");
```

---

#### GetSensorData

```csharp
public SensorData GetSensorData()
```

Get current sensor readings.

**Returns:** `SensorData` object with:
- `IsCoinInFront` - Coin detected
- `IsObjectInFront` - Object detected
- `IsSpaceInFront` - Empty space detected
- `InstanceType` - Type of instance detected

**Example:**
```csharp
var sensor = interpreter.GetSensorData();
if (sensor.IsCoinInFront)
{
    Console.WriteLine("Coin detected!");
}
```

---

### BotActions Types

#### ActionType Enum

```csharp
public enum ActionType
{
    Forward,
    Backwards,
    Right,
    Left
}
```

---

#### BotActionResult Class

```csharp
public class BotActionResult
{
    public ActionType ActionType { get; set; }
    public int Value { get; set; }
    public bool Success { get; set; }
    public string Message { get; set; }
    public int LineNumber { get; set; }
    public int Column { get; set; }
}
```

---

#### InstanceType Enum

```csharp
public enum InstanceType
{
    None,
    Coin,
    Obj,
    Space
}
```

---

## Customization

### Custom Sensor Provider

Create a class implementing `ISensorProvider`:

```csharp
using BotkaInterpreter;

public class GameSensorProvider : ISensorProvider
{
    private readonly GameWorld _world;
    private readonly Robot _robot;

    public GameSensorProvider(GameWorld world, Robot robot)
    {
        _world = world;
        _robot = robot;
    }

    public bool IsCoinInFront()
    {
        var position = _robot.GetPositionInFront();
        return _world.HasCoinAt(position);
    }

    public bool IsObjectInFront()
    {
        var position = _robot.GetPositionInFront();
        return _world.HasObjectAt(position);
    }

    public bool IsSpaceInFront()
    {
        var position = _robot.GetPositionInFront();
        return _world.IsEmptyAt(position);
    }

    public InstanceType GetInstanceInFront()
    {
        if (IsCoinInFront()) return InstanceType.Coin;
        if (IsObjectInFront()) return InstanceType.Obj;
        if (IsSpaceInFront()) return InstanceType.Space;
        return InstanceType.None;
    }
}
```

### Custom Action Handler

Extend action handling:

```csharp
public class CustomBotkaInterpreter : BotkaInterpreter
{
    public CustomBotkaInterpreter(ISensorProvider sensorProvider)
        : base(sensorProvider) { }

    protected override BotActionResult OnActionExecuted(BotActionResult result)
    {
        // Custom logic after each action
        Console.WriteLine($"Custom handler: {result.ActionType}");
        return result;
    }
}
```

---

## Advanced Usage

### Batch Processing

Execute multiple files:

```bash
#!/bin/bash
cd build

for file in ../examples/*.botka; do
    echo "Running: $file"
    dotnet BotkaInterpreter.dll "$file" --quiet
done
```

### Integration with Testing Framework

```csharp
using Xunit;
using BotkaInterpreter;

public class BotkaTests
{
    [Fact]
    public void TestForwardMovement()
    {
        var interpreter = new BotkaInterpreter(new MockSensorProvider());
        interpreter.LoadCode("@start forward 5; @end");

        int steps = 0;
        while (interpreter.HasNext())
        {
            var result = interpreter.Next();
            Assert.Equal(ActionType.Forward, result.ActionType);
            Assert.Equal(5, result.Value);
            steps++;
        }

        Assert.Equal(1, steps); // One action statement
    }

    [Fact]
    public void TestConditionals()
    {
        var sensorProvider = new MockSensorProvider
        {
            CoinDetected = true
        };

        var interpreter = new BotkaInterpreter(sensorProvider);
        interpreter.LoadCode(@"
            @start
            if({} coin) {
                forward 1;
            } else {
                right 90;
            }
            @end
        ");

        var result = interpreter.Next();
        Assert.Equal(ActionType.Forward, result.ActionType);
    }
}
```

### Logging and Debugging

```csharp
public class LoggingSensorProvider : ISensorProvider
{
    private readonly ISensorProvider _inner;
    private readonly ILogger _logger;

    public LoggingSensorProvider(ISensorProvider inner, ILogger logger)
    {
        _inner = inner;
        _logger = logger;
    }

    public bool IsCoinInFront()
    {
        var result = _inner.IsCoinInFront();
        _logger.Log($"Coin check: {result}");
        return result;
    }

    // ... implement other methods similarly
}
```

---

## Troubleshooting

### Common Issues

| Problem | Cause | Solution |
|---------|-------|----------|
| `DLL not found` | Tree-sitter not built | Run `./scripts/build_tree_sitter_dll.sh` |
| `Parse error` | Invalid syntax | Check grammar in [grammer.md](grammer.md) |
| `No actions found` | Empty program | Add action statements |
| `Sensor error` | Missing provider | Use `MockSensorProvider` or implement custom |

### Debug Mode

```bash
# Run with verbose output
dotnet BotkaInterpreter.dll 'code' --verbose

# Debug specific file
dotnet BotkaInterpreter.dll file.botka --debug
```

### Error Messages

| Error | Meaning | Fix |
|-------|---------|-----|
| `Expected ';'` | Missing semicolon | Add `;` after action |
| `Invalid number` | Number format error | Use valid integer |
| `Unknown keyword` | Typo in keyword | Check spelling (EN/RU) |
| `Unmatched braces` | Missing `}` | Close all blocks |

---

## See Also

- [Main README](../README.md) - Project overview
- [Grammar Specification](grammer.md) - Language syntax
- [Examples](../examples/) - Usage examples
- [Contributing Guide](../CONTRIBUTING.md) - Development guide

---

**Happy Interpreting! 🤖**
