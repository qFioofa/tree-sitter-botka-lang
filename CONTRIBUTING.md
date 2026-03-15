# Contributing to Tree-sitter Botka Language

Thank you for your interest in contributing to the Botka Language project! This guide will help you understand the project structure and how to make contributions.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Development Setup](#development-setup)
- [Making Changes](#making-changes)
  - [Modifying the Grammar](#modifying-the-grammar)
  - [Adding Features](#adding-features)
  - [Fixing Bugs](#fixing-bugs)
- [Testing](#testing)
- [Documentation](#documentation)
- [Submitting Changes](#submitting-changes)
- [Extending Botka](#extending-botka)
  - [Adding New Actions](#adding-new-actions)
  - [Adding New Instances](#adding-new-instances)
  - [Adding New Control Flow](#adding-new-control-flow)
- [Integration with Other Projects](#integration-with-other-projects)
- [Questions?](#questions)

---

## Code of Conduct

- Be respectful and inclusive
- Welcome newcomers and help them learn
- Focus on constructive feedback
- Keep discussions professional and on-topic

---

## Getting Started

### 1. Fork the Repository

```bash
# Clone your fork
git clone https://github.com/YOUR_USERNAME/tree-sitter-botka-lang
cd tree-sitter-botka-lang
```

### 2. Set Up Development Environment

```bash
# Install dependencies
npm install

# Install tree-sitter CLI globally
npm install -g tree-sitter-cli

# Make build scripts executable
chmod +x scripts/*.sh
```

### 3. Verify Setup

```bash
# Build the project
./scripts/build.sh

# Run tests
tree-sitter test
```

---

## Project Structure

```
tree-sitter-botka-lang/
├── grammar.js              # 🎯 Main grammar definition (Tree-sitter)
├── src/                    # Generated parser C code
├── bindings/               # Language bindings
│   ├── node/              # Node.js binding
│   ├── python/            # Python binding
│   ├── rust/              # Rust binding
│   ├── go/                # Go binding
│   ├── c/                 # C binding
│   └── swift/             # Swift binding
├── interpreter/            # 🎯 C# interpreter
│   ├── BotkaInterpreter.cs    # Main interpreter logic
│   ├── BotActions.cs          # Action definitions
│   ├── InteractiveRunner.cs   # Interactive mode
│   ├── ISensorProvider.cs     # Sensor interface
│   └── MockSensorProvider.cs  # Mock sensor for testing
├── examples/               # Example programs
├── scripts/                # Build scripts
├── docs/                   # Documentation
├── tests/                  # Test files
├── package.json            # Node.js config
├── Cargo.toml              # Rust config
└── pyproject.toml          # Python config
```

### Key Files

| File | Purpose | When to Edit |
|------|---------|--------------|
| `grammar.js` | Tree-sitter grammar rules | Adding language features |
| `interpreter/BotkaInterpreter.cs` | Interpreter execution logic | Changing execution behavior |
| `interpreter/BotActions.cs` | Action types | Adding new robot actions |
| `examples/*.botka` | Example programs | Adding usage examples |

---

## Development Setup

### Required Tools

| Tool | Version | Install Command |
|------|---------|-----------------|
| Node.js | v18+ | `nvm install 18` |
| npm | v10+ | `npm install -g npm@latest` |
| tree-sitter-cli | v0.22+ | `npm install -g tree-sitter-cli` |
| .NET SDK | v8.0+ | See [Installation Guide](README.md#installation) |
| GCC/Clang | Latest | `sudo apt install build-essential` |

### Build Commands

```bash
# Full build
./scripts/build.sh

# Build tree-sitter parser only
./scripts/build_tree_sitter_dll.sh

# Build interpreter only
./scripts/build_interpreter.sh

# Clean build
./scripts/build.sh clean

# Test parser
tree-sitter test

# Parse a file
tree-sitter parse examples/forward_4.botka
```

---

## Making Changes

### Modifying the Grammar

The grammar is defined in [`grammar.js`](grammar.js) using Tree-sitter's JavaScript DSL.

#### Grammar Structure

```javascript
module.exports = grammar({
  name: "botka",
  
  word: ($) => $.identifier,
  
  extras: ($) => [/\s+/, $.single_line_comment, $.multi_line_comment],
  
  supertypes: ($) => [$.statement],
  
  rules: {
    // Grammar rules here
  },
});
```

#### Common Changes

| Change | File to Edit | Steps |
|--------|--------------|-------|
| Add keyword | `grammar.js` | Add to appropriate rule |
| Add statement type | `grammar.js` | Add to `statement` choice |
| Change syntax | `grammar.js` | Modify rule definition |
| Add bilingual support | `grammar.js` | Add Russian equivalent with `choice()` |

#### Example: Adding a New Keyword

```javascript
// In grammar.js
program_start: ($) => choice("@start", "@начало", "@begin"),
```

#### After Modifying Grammar

```bash
# Regenerate parser
tree-sitter generate

# Test changes
tree-sitter test

# Rebuild
./scripts/build.sh
```

---

### Adding Features

#### Feature Checklist

- [ ] Update `grammar.js` if syntax changes
- [ ] Update interpreter if execution changes
- [ ] Add tests
- [ ] Add examples
- [ ] Update documentation

#### Feature Template

1. **Create a new branch**

```bash
git checkout -b feature/your-feature-name
```

2. **Make changes** (see sections below)

3. **Test thoroughly**

4. **Update documentation**

5. **Submit pull request**

---

### Fixing Bugs

#### Bug Fix Process

1. **Create a test case** that reproduces the bug
2. **Fix the bug** in the appropriate file
3. **Verify the fix** with your test case
4. **Run all existing tests** to ensure no regressions
5. **Document the fix** in commit message

#### Common Bug Locations

| Bug Type | Check These Files |
|----------|-------------------|
| Parse error | `grammar.js`, `src/` |
| Interpreter crash | `interpreter/BotkaInterpreter.cs` |
| Wrong execution | `interpreter/BotActions.cs` |
| Binding error | `bindings/*/` |

---

## Testing

### Parser Tests

```bash
# Run all tests
tree-sitter test

# Parse specific file
tree-sitter parse examples/forward_4.botka

# Debug parsing
tree-sitter parse examples/forward_4.botka --debug
```

### Interpreter Tests

```bash
# Build and run interpreter
cd build
dotnet BotkaInterpreter.dll '@start forward 5; @end'
```

### Test File Format

Create test files in `examples/` directory:

```botka
// examples/test_new_feature.botka
@start
// Test description
forward 5;
@end
```

---

## Documentation

### Documentation Files

| File | Purpose |
|------|---------|
| `README.md` | Main project documentation |
| `docs/grammer.md` | Grammar specification |
| `docs/interpreter.md` | Interpreter API |
| `CONTRIBUTING.md` | This file |
| `examples/README.md` | Examples guide |

### Documentation Guidelines

- Use clear, simple language
- Include code examples
- Use tables for comparisons
- Add both English and Russian examples where applicable
- Keep syntax examples consistent

---

## Submitting Changes

### Commit Message Format

```
<type>(<scope>): <subject>

<body>

<footer>
```

#### Types

| Type | Description |
|------|-------------|
| `feat` | New feature |
| `fix` | Bug fix |
| `docs` | Documentation changes |
| `style` | Code style changes (formatting) |
| `refactor` | Code refactoring |
| `test` | Test additions/changes |
| `chore` | Build/config changes |

#### Example Commit Messages

```
feat(grammar): add support for nested if statements

- Added recursive if_statement rule
- Updated precedence levels
- Added test cases

Fixes #42
```

```
fix(interpreter): correct negative number handling

- Fixed edge case with -0
- Added validation for number range

Closes #38
```

```
docs: update installation instructions for Windows

- Added winget commands
- Updated .NET SDK version
```

### Pull Request Template

```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Test addition
- [ ] Refactoring

## Testing
- [ ] Tests pass
- [ ] Examples updated
- [ ] Documentation updated

## Related Issues
Fixes #<issue-number>
```

---

## Extending Botka

### Adding New Actions

#### Step 1: Update Grammar

Edit `grammar.js`:

```javascript
action_type: ($) =>
  choice(
    $.forward_action,
    $.backwards_action,
    $.right_action,
    $.left_action,
    $.jump_action,  // New action
  ),

jump_action: ($) => choice("jump", "прыжок"),
```

#### Step 2: Update Interpreter

Edit `interpreter/BotActions.cs`:

```csharp
public enum ActionType
{
    Forward,
    Backwards,
    Right,
    Left,
    Jump,  // New action
}
```

Edit `interpreter/BotkaInterpreter.cs`:

```csharp
private BotActionResult ExecuteJump(int amount)
{
    // Implementation
    return new BotActionResult 
    { 
        Success = true, 
        Action = $"Jump {amount} steps" 
    };
}
```

#### Step 3: Add Examples

Create `examples/jump_example.botka`:

```botka
@start
jump 5;
@end
```

#### Step 4: Update Documentation

- Add to [grammer.md](docs/grammer.md)
- Add to [README.md](README.md)

---

### Adding New Instances

#### Step 1: Update Grammar

Edit `grammar.js`:

```javascript
instance: ($) => choice(
  $.coin_instance, 
  $.obj_instance, 
  $.space_instance,
  $.wall_instance,  // New instance
),

wall_instance: ($) => choice("wall", "стена"),
```

#### Step 2: Update Sensor Provider

Edit `interpreter/ISensorProvider.cs`:

```csharp
public interface ISensorProvider
{
    bool IsCoinInFront();
    bool IsObjectInFront();
    bool IsSpaceInFront();
    bool IsWallInFront();  // New method
    InstanceType GetInstanceInFront();
}
```

#### Step 3: Update Condition Checking

Edit `interpreter/BotkaInterpreter.cs`:

```csharp
private bool CheckCondition(InstanceType instance)
{
    return instance switch
    {
        InstanceType.Coin => _sensorProvider.IsCoinInFront(),
        InstanceType.Obj => _sensorProvider.IsObjectInFront(),
        InstanceType.Space => _sensorProvider.IsSpaceInFront(),
        InstanceType.Wall => _sensorProvider.IsWallInFront(),  // New
        _ => throw new ArgumentException($"Unknown instance: {instance}")
    };
}
```

---

### Adding New Control Flow

#### Example: Adding `until` Loop

#### Step 1: Grammar

```javascript
statement: ($) => choice(
  // ... existing statements
  prec.right(PREC.STATEMENT, $.until_statement),
),

until_statement: ($) =>
  prec.right(PREC.STATEMENT, seq($.until_keyword, $.condition, $.block)),

until_keyword: ($) => choice("until", "до"),
```

#### Step 2: Interpreter

```csharp
// In BotkaInterpreter.cs
case NodeType.UntilStatement:
    result = ExecuteUntil(node);
    break;

private BotActionResult ExecuteUntil(SyntaxNode node)
{
    // Execute until condition becomes true
    // Implementation
}
```

---

## Integration with Other Projects

### Using as a Dependency

#### Node.js Package

```json
// package.json
{
  "dependencies": {
    "tree-sitter-botka-lang": "github:qFioofa/tree-sitter-botka-lang"
  }
}
```

#### Rust Crate

```toml
# Cargo.toml
[dependencies]
tree-sitter-botka-lang = { git = "https://github.com/qFioofa/tree-sitter-botka-lang" }
```

#### Python Package

```python
# pyproject.toml
[project]
dependencies = [
    "tree-sitter-botka-lang @ git+https://github.com/qFioofa/tree-sitter-botka-lang"
]
```

### Embedding the Interpreter

#### Option 1: Use as DLL

```bash
# Build the interpreter
./scripts/build.sh

# Copy to your project
cp build/BotkaInterpreter.dll your-project/
```

#### Option 2: Use as Library

```csharp
// Your C# project
using BotkaInterpreter;

var interpreter = new BotkaInterpreter(new MockSensorProvider());
interpreter.LoadCode("@start forward 5; @end");

while (interpreter.HasNext())
{
    var result = interpreter.Next();
    Console.WriteLine(result);
}
```

### Creating Language Bindings

See `bindings/` directory for examples:

| Binding | Location |
|---------|----------|
| Node.js | `bindings/node/` |
| Python | `bindings/python/` |
| Rust | `bindings/rust/` |
| Go | `bindings/go/` |
| Swift | `bindings/swift/` |
| C | `bindings/c/` |

---

## Questions?

### Getting Help

- 📖 Read the [documentation](docs/)
- 💬 Check existing [issues](https://github.com/qFioofa/tree-sitter-botka-lang/issues)
- 📧 Contact maintainers

### Common Issues

| Problem | Solution |
|---------|----------|
| Parser won't regenerate | Run `tree-sitter generate` |
| Build fails | Check .NET SDK version |
| Tests fail | Run `tree-sitter test` for details |
| Interpreter crashes | Check sensor provider implementation |

### Resources

- [Tree-sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [Tree-sitter Grammar Guide](https://tree-sitter.github.io/tree-sitter/creating-parsers)
- [.NET Documentation](https://docs.microsoft.com/dotnet/)

---

**Thank you for contributing to Botka Language! 🎉**
