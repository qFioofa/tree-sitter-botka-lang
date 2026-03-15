# Tree-sitter Botka Language

A tree-sitter grammar and interpreter for the **Botka Language** - a simple educational programming language for controlling robots on a grid.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Overview

Botka is a block-structured programming language with support for:
- **Conditional statements** (if/else)
- **Loops** (while, for)
- **Robot actions** (move forward/backward, turn left/right)
- **Sensor checks** (detect coins, objects, empty spaces)
- **Bilingual keywords** (English and Russian)

## Quick Start

```bash
# Clone the repository
git clone https://github.com/qFioofa/tree-sitter-botka-lang
cd tree-sitter-botka-lang

# Build everything
chmod +x scripts/*.sh
./scripts/build.sh

# Run the interpreter
cd build
dotnet BotkaInterpreter.dll '@start forward 5; @end'
```

## Table of Contents

- [Features](#features)
- [Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [Ubuntu/Debian](#ubuntudebian)
  - [Windows](#windows)
  - [macOS](#macos)
- [Usage](#usage)
  - [Interpreter](#interpreter)
  - [Tree-sitter CLI](#tree-sitter-cli)
  - [As a Library](#as-a-library)
- [Language Syntax](#language-syntax)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Development](#development)
- [Documentation](#documentation)
- [License](#license)

## Features

| Feature | Description |
|---------|-------------|
| 🌐 **Bilingual** | Keywords in English and Russian |
| 🔀 **Control Flow** | if/else chains, while loops, for loops |
| 🤖 **Robot Actions** | Move forward/backward, turn left/right |
| 👁️ **Sensors** | Detect coins, objects, and empty spaces |
| 📝 **Comments** | Single-line (`//`) and multi-line (`/* */`) |
| 🧩 **Tree-sitter** | Fast incremental parsing |
| 🎮 **Interactive Interpreter** | Step-by-step execution with debug info |

## Installation

### Prerequisites

| Tool | Version | Purpose |
|------|---------|---------|
| Node.js | v18+ | Tree-sitter grammar generation |
| npm | v10+ | Package management |
| tree-sitter-cli | v0.22+ | Parser generation |
| .NET SDK | v8.0+ | Interpreter build |
| GCC/Clang | Latest | Native parser compilation |

### Ubuntu/Debian

```bash
# Update package list
sudo apt update

# Install Node.js and npm
sudo apt install -y nodejs npm

# Install tree-sitter CLI globally
sudo npm install -g tree-sitter-cli

# Install .NET SDK
wget https://packages.microsoft.com/config/debian/12/packages-prod.dotnet8_gcc.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
sudo rm packages-microsoft-prod.deb
sudo apt update
sudo apt install -y dotnet-sdk-8.0

# Install build tools
sudo apt install -y build-essential gcc
```

### Windows

```powershell
# Install Node.js (via winget or download from nodejs.org)
winget install OpenJS.NodeJS.LTS

# Install tree-sitter CLI
npm install -g tree-sitter-cli

# Install .NET SDK (via winget or download from dotnet.microsoft.com)
winget install Microsoft.DotNet.SDK.8

# Install Visual Studio Build Tools (for C++ compiler)
winget install Microsoft.VisualStudio.2022.BuildTools
```

### macOS

```bash
# Install Homebrew if not installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install Node.js
brew install node

# Install tree-sitter CLI
npm install -g tree-sitter-cli

# Install .NET SDK
brew install --cask dotnet-sdk

# Install Xcode Command Line Tools
xcode-select --install
```

## Usage

### Interpreter

The Botka Interpreter provides an interactive environment for running Botka programs.

#### Run with code argument

```bash
cd build
dotnet BotkaInterpreter.dll '@start
if({} coin) {
    forward 1;
} else {
    right 90;
}
@end'
```

#### Interactive mode

```bash
cd build
dotnet BotkaInterpreter.dll
```

#### Interactive commands

| Command | Aliases | Description |
|---------|---------|-------------|
| `next` | `space`, `n` | Execute next step |
| `info` | — | Show detailed execution info |
| `sensor` | — | Show sensor data |
| `continue` | `c` | Run to completion |
| `help` | `h` | Show help menu |
| `quit` | `exit`, `q` | Exit interpreter |

### Tree-sitter CLI

#### Parse a file

```bash
tree-sitter parse examples/forward_4.botka
```

#### Run tests

```bash
tree-sitter test
```

#### Build WASM module

```bash
tree-sitter build --wasm
```

### As a Library

#### Node.js

```javascript
const Parser = require("tree-sitter");
const BotkaLang = require("tree-sitter-botka-lang");

const parser = new Parser();
parser.setLanguage(BotkaLang);

const code = "@start forward 5; @end";
const tree = parser.parse(code);

console.log(tree.rootNode.toString());
```

#### Python

```python
import tree_sitter
import tree_sitter_botka_lang

parser = tree_sitter.Parser()
parser.set_language(tree_sitter_botka_lang.language())

code = b"@start forward 5; @end"
tree = parser.parse(code)

print(tree.root_node)
```

#### Rust

```rust
use tree_sitter_botka_lang::LANGUAGE;

let mut parser = tree_sitter::Parser::new();
parser.set_language(LANGUAGE)?;

let tree = parser.parse("@start forward 5; @end", None)?;
println!("{:#?}", tree.root_node());
```

## Language Syntax

### Program Structure

```botka
@start
// Your code here
@end
```

Or in Russian:
```botka
@начало
// Ваш код здесь
@конец
```

### Comments

| Type | Syntax | Example |
|------|--------|---------|
| Single-line | `// ...` | `// This is a comment` |
| Multi-line | `/* ... */` | `/* Block comment */` |

### Numbers

- **Type**: Integers only (no decimals)
- **Range**: -2,147,483,648 to +2,147,483,647
- **Format**: Optional `+` or `-` sign, followed by digits

```botka
// Valid numbers
123
+456
-789
0

// Invalid numbers
123.45    // Decimal
-0        // Negative zero
+0        // Positive zero
900000000000000000000000  // Out of range
```

### Robot Actions

| Action | English | Russian | Description |
|--------|---------|---------|-------------|
| Move forward | `forward N;` | `вперед N;` | Move N steps forward |
| Move backward | `backwards N;` | `назад N;` | Move N steps backward |
| Turn right | `right N;` | `вправо N;` | Turn N degrees right |
| Turn left | `left N;` | `влево N;` | Turn N degrees left |

```botka
forward 5;
backwards 2;
right 90;
left 45;
```

### Conditions

Check what's in front of the robot:

| Instance | English | Russian |
|----------|---------|---------|
| Coin | `coin` | `монета` |
| Object | `obj` | `объект` |
| Empty space | `space` | `пусто` |

Use `{not}` modifier to invert the check:

```botka
if({} coin) { }      // If there IS a coin
if({not} coin) { }   // If there is NO coin
```

### Control Flow

#### If Statement

```botka
if({} coin) {
    forward 1;
}

// With else
if({} coin) {
    forward 1;
} else {
    right 90;
}

// With else-if chain
if({} coin) {
    forward 1;
} else if({} obj) {
    right 90;
} else {
    left 45;
}
```

#### While Loop

```botka
while({} space) {
    forward 1;
}
```

#### For Loop

```botka
for(5 times) {
    forward 1;
}
```

### Complete Example

```botka
@start
// Navigate to the coin
while({not} coin) {
    forward 1;
}

// Pick up the coin (if action exists)
// forward 1;

// Return to start
for(3 times) {
    right 90;
}

// Turn back
right 180;
@end
```

## Examples

See the [`examples/`](examples/) directory for complete examples:

| File | Description |
|------|-------------|
| `forward_4.botka` | Simple forward movement |
| `if_else_chain.botka` | If-else chain with different conditions |
| `nested_loops.botka` | Nested loop structures |
| `navigation.botka` | Complex navigation logic |
| `comment.botka` | Comment usage examples |
| `russian_example.botka` | Russian keywords example |

## Project Structure

```
tree-sitter-botka-lang/
├── grammar.js              # Tree-sitter grammar definition
├── src/                    # Generated parser source code
├── bindings/               # Language bindings
│   ├── node/              # Node.js binding
│   ├── python/            # Python binding
│   ├── rust/              # Rust binding
│   ├── go/                # Go binding
│   ├── c/                 # C binding
│   └── swift/             # Swift binding
├── interpreter/            # C# interpreter
│   ├── BotkaInterpreter.cs
│   ├── BotActions.cs
│   ├── InteractiveRunner.cs
│   └── ISensorProvider.cs
├── examples/               # Example Botka programs
├── scripts/                # Build scripts
│   ├── build.sh
│   ├── build_interpreter.sh
│   └── build_tree_sitter_dll.sh
├── docs/                   # Documentation
│   └── grammer.md
├── tests/                  # Test files (if any)
├── package.json            # Node.js package config
├── Cargo.toml              # Rust package config
├── pyproject.toml          # Python package config
└── README.md               # This file
```

## Development

### Build from Source

```bash
# Clone repository
git clone https://github.com/qFioofa/tree-sitter-botka-lang
cd tree-sitter-botka-lang

# Make scripts executable
chmod +x scripts/*.sh

# Build everything
./scripts/build.sh

# Or build components separately
./scripts/build_tree_sitter_dll.sh      # Build parser
./scripts/build_interpreter.sh          # Build interpreter
```

### Clean Build

```bash
./scripts/build.sh clean
```

### Modify Grammar

1. Edit [`grammar.js`](grammar.js)
2. Regenerate parser: `tree-sitter generate`
3. Test: `tree-sitter test`
4. Rebuild: `./scripts/build.sh`

### Testing

```bash
# Run tree-sitter tests
tree-sitter test

# Parse specific file
tree-sitter parse examples/forward_4.botka

# Debug parser
tree-sitter parse examples/forward_4.botka --debug
```

## Documentation

| Document | Description |
|----------|-------------|
| [README.md](README.md) | Main project documentation (this file) |
| [docs/grammer.md](docs/grammer.md) | Detailed grammar specification |
| [docs/interpreter.md](docs/interpreter.md) | Interpreter API documentation |
| [interpreter/README.md](interpreter/README.md) | Interpreter usage guide |
| [examples/README.md](examples/README.md) | Examples walkthrough |
| [CONTRIBUTING.md](CONTRIBUTING.md) | Contribution guidelines |

## License

This project is licensed under the [MIT License](LICENSE).

---

**Happy Coding with Botka! 🤖**
