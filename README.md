# tree-sitter-botka-lang

Botka lang grammer for tree sitter

# Grammer

[File with all grammer structer](./docs/grammer.md)

# Usage & Install

## Requirements

- **npm** v11.10.0+
- **tree-sitter-cli**
- **.NET SDK** v10.0+
- **GCC** (for native parser)

## Install Ubuntu

```bash
sudo apt update
sudo apt install -y nodejs npm gcc

npm install -g tree-sitter-cli

sudo apt-get update && \
  sudo apt-get install -y dotnet-sdk-10.0
```

## Repo usage

- Clone repo:

```bash
git clone https://github.com/qFioofa/tree-sitter-botka-lang
cd tree-sitter-botka-lang
```

- Full build

```bash
chmod +x scripts/*
./scripts/build.sh
```

The result will in in `build` folder at root of the project.
