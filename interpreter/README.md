# Botka Interpreter

Interactive interpreter for Botka language with step-by-step execution.

## Building

```bash
# Build everything
bash scripts/build.sh

# Build clean
bash scripts/build.sh clean
```

## Running

### Interactive Mode

```bash
cd build
dotnet BotkaInterpreter.dll '@start if({} coin) { forward 1; } @end'
```

Or with default example code (no arguments):
```bash
cd build
dotnet BotkaInterpreter.dll
```

### Interactive Commands

| Command | Description |
|---------|-------------|
| `space`, `n`, `next` | Execute next step |
| `info` | Show detailed information (step, line, column, remaining actions) |
| `sensor` | Show sensor data (coin/object/space in front) |
| `continue`, `c` | Run to completion |
| `help`, `h` | Show help |
| `quit`, `exit`, `q` | Exit |

## Example Session

```
╔═══════════════════════════════════════════════════════════╗
║           Botka Language Interactive Interpreter          ║
╚═══════════════════════════════════════════════════════════╝

Total actions: 4

────────────────────────────────────────────────────────────
Step: 1 / 4
Line: 2

[Step 1] Next: Forward(1) | Press 'space' to execute: 
space

  ▶ Executing: Move forward 1 step(s)
    Source: Line 2
  ✓ Completed
```

## Grammar Syntax

```botka
@start
// Condition with modifier: {} or {not}
if({} coin) {
    forward 1;
} else {
    forward 5;
};

// While loop
while({} space) {
    forward 1;
};

// For loop (positive number only)
for(3 times) {
    right 90;
};

// Actions
forward 5;
backwards 2;
right 90;
left 45;
@end
```

## Architecture

### Core Components

- **`BotkaInterpreter.cs`** - Main interpreter with `Next()` method
- **`BotActions.cs`** - Action types and result classes
- **`ISensorProvider.cs`** - Interface for external sensor data
- **`MockSensorProvider.cs`** - Mock implementation for testing
- **`InteractiveRunner.cs`** - Interactive mode handler
- **`TreeSitterBindings.cs`** - Tree-sitter parser bindings

### Using Custom Sensor Provider

Implement `ISensorProvider` interface:

```csharp
public class MySensorProvider : ISensorProvider
{
    public bool IsCoinInFront() { /* Your implementation */ }
    public bool IsObjectInFront() { /* Your implementation */ }
    public bool IsSpaceInFront() { /* Your implementation */ }
    public InstanceType GetInstanceInFront() { /* Your implementation */ }
}

// Use with interpreter
var sensorProvider = new MySensorProvider();
var interpreter = new BotkaInterpreter(sensorProvider);
```

## Display Information

The interpreter shows:
- **Step number** - Current action index
- **Total actions** - Total actions in program
- **Line number** - Current line in source code
- **Column** - Current column in source code
- **Sensor data** - What's detected in front (coin/object/space)
- **Next action preview** - What action will be executed next
