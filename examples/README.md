# Botka Language Examples

This directory contains example Botka programs demonstrating various language features.

## Table of Contents

- [Basic Examples](#basic-examples)
- [Intermediate Examples](#intermediate-examples)
- [Advanced Examples](#advanced-examples)
- [Running Examples](#running-examples)

---

## Example Overview

| File | Difficulty | Features Demonstrated |
|------|------------|----------------------|
| `forward_4.botka` | ⭐ Beginner | Basic action, comments |
| `comment.botka` | ⭐ Beginner | Single & multi-line comments |
| `if_else_chain.botka` | ⭐⭐ Intermediate | If-else chains, multiple conditions |
| `russian_example.botka` | ⭐⭐ Intermediate | Russian keywords |
| `navigation.botka` | ⭐⭐ Intermediate | Complex logic, mixed constructs |
| `nested_loops.botka` | ⭐⭐⭐ Advanced | Nested loops, complex conditions |
| `all_in.botka` | ⭐⭐⭐ Advanced | All language features combined |

---

## Basic Examples

### forward_4.botka

**File:** [`forward_4.botka`](forward_4.botka)

**Description:** Simplest example - move the robot forward 4 steps.

**Code:**
```botka
@start
// Simple forward movement
forward 4;
@end
```

**Concepts:**
- Program structure (`@start` / `@end`)
- Single-line comments
- Basic action statement

**Output:**
```
Robot moves forward 4 steps
```

**Try it:**
```bash
cd build
dotnet BotkaInterpreter.dll '../examples/forward_4.botka'
```

---

### comment.botka

**File:** [`comment.botka`](comment.botka)

**Description:** Demonstrates both types of comments in Botka.

**Code:**
```botka
@start
// Example with comments
// This is a single line comment

/*
 * This is a multi-line comment
 * spanning multiple lines
 */

forward 1;
@end
```

**Concepts:**
- Single-line comments: `// ...`
- Multi-line comments: `/* ... */`
- Comments are ignored during execution

**Tip:** Use comments to explain your code's purpose!

---

## Intermediate Examples

### if_else_chain.botka

**File:** [`if_else_chain.botka`](if_else_chain.botka)

**Description:** Shows how to use if-else chains with different sensor conditions.

**Code:**
```botka
@start
// If-else chain with different instances
if({} coin) {
    forward 1;
} else if({} obj) {
    right 90;
} else if({} space) {
    left 45;
} else {
    backwards 1;
};
@end
```

**Concepts:**
- If-else statements
- Multiple conditions (`else if`)
- Instance detection (`coin`, `obj`, `space`)
- Default case (`else`)

**Execution Flow:**
```
┌─────────────────┐
│ Check: coin?    │──Yes──> forward 1
└────────┬────────┘
         │ No
         ▼
┌─────────────────┐
│ Check: obj?     │──Yes──> right 90
└────────┬────────┘
         │ No
         ▼
┌─────────────────┐
│ Check: space?   │──Yes──> left 45
└────────┬────────┘
         │ No
         ▼
    backwards 1
```

**Try it:**
```bash
cd build
dotnet BotkaInterpreter.dll '../examples/if_else_chain.botka'
```

---

### russian_example.botka

**File:** [`russian_example.botka`](russian_example.botka)

**Description:** Complete program using Russian keywords.

**Code:**
```botka
@начало
// Пример с русскими ключевыми словами

// Если есть монета - идем вперед
если({} монета) {
    вперед 1;
} иначе {
    вперед 5;
};

// Пока пусто - идем
пока({} пусто) {
    вперед 1;
};

// Цикл for - поворот 3 раза
для(3 раз) {
    вправо 90;
};

// Базовые действия
вперед 5;
назад 2;
вправо 90;
влево 45;

@конец
```

**Concepts:**
- Russian program markers: `@начало` / `@конец`
- Russian control flow: `если`, `иначе`, `пока`, `для`
- Russian actions: `вперед`, `назад`, `вправо`, `влево`
- Russian instances: `монета`, `объект`, `пусто`

**Keyword Translation:**

| English | Russian |
|---------|---------|
| `@start` | `@начало` |
| `@end` | `@конец` |
| `if` | `если` |
| `else` | `иначе` |
| `while` | `пока` |
| `for` | `для` |
| `times` | `раз` |
| `forward` | `вперед` |
| `backwards` | `назад` |
| `right` | `вправо` |
| `left` | `влево` |
| `coin` | `монета` |
| `obj` | `объект` |
| `space` | `пусто` |

---

### navigation.botka

**File:** [`navigation.botka`](navigation.botka)

**Description:** Complex navigation logic with multiple conditions and loops.

**Code:**
```botka
@start
// Complex navigation with conditions

// Check for coin first
if({not} coin) {
    // No coin, move forward to find it
    forward 3;
} else {
    // Coin detected, collect it
    forward 1;
};

// Turn right and check for obstacles
right 90;

// While path is clear, keep moving
while({} space) {
    forward 1;
};

// Turn around
right 90;
right 90;

// Return back
for(3 times) {
    forward 1;
};

// Final positioning
if({} obj) {
    left 90;
} else {
    right 90;
};

@end
```

**Concepts:**
- Conditional navigation
- While loop for continuous movement
- For loop for repeated actions
- Multiple if statements
- Negative condition modifier (`{not}`)

**Strategy:**
1. Check for coin → approach or collect
2. Turn right
3. Move while path is clear
4. Turn 180° (two right turns)
5. Return 3 steps
6. Final adjustment based on obstacles

---

## Advanced Examples

### nested_loops.botka

**File:** [`nested_loops.botka`](nested_loops.botka)

**Description:** Demonstrates nested loop structures with conditions inside.

**Code:**
```botka
@start
// Nested loops example
// Outer while loop
while({} coin) {
    // Inner for loop
    for(3 times) {
        if({} obj) {
            forward 1;
        } else {
            backwards 1;
        };
    };
    left 90;
};
@end
```

**Concepts:**
- Nested loops (while containing for)
- If-else inside loops
- Complex execution flow

**Execution Flow:**
```
while(coin exists) {
    for(i = 0; i < 3; i++) {
        if(obj exists) {
            forward 1
        } else {
            backwards 1
        }
    }
    left 90
}
```

**Note:** The while loop continues as long as a coin is detected. The inner for loop always executes exactly 3 times per while iteration.

---

### all_in.botka

**File:** [`all_in.botka`](all_in.botka)

**Description:** Comprehensive example using all Botka language features.

**Code:**
```botka
@start
// Complete example with all features

// If-else with coin detection
if({} coin) {
    forward 1;
} else {
    forward 5;
};

// While loop - move while there's space
while({} space) {
    forward 1;
};

// For loop - turn 3 times
for(3 times) {
    right 90;
};

// Basic actions
forward 5;
backwards 2;
right 90;
left 45;

// Nested if with not modifier
if({not} obj) {
    forward 1;
} else if({} coin) {
    right 90;
} else {
    left 90;
};

@end
```

**Features Summary:**

| Feature | Example Line |
|---------|--------------|
| Program markers | `@start`, `@end` |
| Comments | `// Complete example...` |
| If-else | `if({} coin) { } else { }` |
| Else-if chain | `else if({} coin)` |
| While loop | `while({} space)` |
| For loop | `for(3 times)` |
| All actions | `forward`, `backwards`, `right`, `left` |
| Condition modifier | `{not}` |
| All instances | `coin`, `obj`, `space` |

**This is the best example to test full language support!**

---

## Running Examples

### Using the Interpreter

```bash
# Navigate to build directory
cd build

# Run any example
dotnet BotkaInterpreter.dll '../examples/<filename>'
```

### Interactive Mode

```bash
cd build
dotnet BotkaInterpreter.dll '../examples/all_in.botka'
```

Then use interactive commands:
- Press `space` to execute next step
- Type `info` for detailed information
- Type `sensor` to see sensor data
- Type `c` to run to completion

### Parse Without Executing

```bash
# Verify syntax with tree-sitter
tree-sitter parse examples/forward_4.botka

# With debug output
tree-sitter parse examples/all_in.botka --debug
```

---

## Creating Your Own Examples

### Example Template

```botka
@start
// [Description of what this example does]

// [Your code here]

@end
```

### Example Naming Convention

| Pattern | Example | Purpose |
|---------|---------|---------|
| `<feature>.botka` | `loop.botka` | Single feature demo |
| `<action>_<count>.botka` | `forward_4.botka` | Specific action |
| `<language>_example.botka` | `russian_example.botka` | Language variant |
| `test_<feature>.botka` | `test_nested.botka` | Test files |

### Tips for Good Examples

1. **Keep it simple** - Focus on one concept
2. **Add comments** - Explain what each part does
3. **Use descriptive names** - Make purpose clear
4. **Test thoroughly** - Ensure it runs correctly
5. **Show edge cases** - Demonstrate limits

---

## Practice Exercises

Try modifying these examples to:

### Exercise 1: Square Pattern
```botka
@start
// Make the robot move in a square pattern
// Hint: 4 sides, turn 90° after each
@end
```

<details>
<summary>Solution</summary>

```botka
@start
for(4 times) {
    forward 10;
    right 90;
}
@end
```
</details>

### Exercise 2: Find Coin
```botka
@start
// Move forward until you find a coin
// Then move 1 more step to collect it
@end
```

<details>
<summary>Solution</summary>

```botka
@start
while({not} coin) {
    forward 1;
}
forward 1;
@end
```
</details>

### Exercise 3: Avoid Obstacles
```botka
@start
// If there's an object, turn right
// Otherwise, move forward
// Repeat 5 times
@end
```

<details>
<summary>Solution</summary>

```botka
@start
for(5 times) {
    if({} obj) {
        right 90;
    } else {
        forward 1;
    }
}
@end
```
</details>

---

## See Also

- [Grammar Specification](../docs/grammer.md)
- [Main README](../README.md)
- [Interpreter Documentation](../docs/interpreter.md)
- [Contributing Guide](../CONTRIBUTING.md)
