# Botka Language Grammar Specification

This document describes the complete grammar of the Botka programming language.

## Table of Contents

- [Overview](#overview)
- [Program Structure](#program-structure)
- [Lexical Elements](#lexical-elements)
  - [Keywords](#keywords)
  - [Identifiers](#identifiers)
  - [Numbers](#numbers)
  - [Comments](#comments)
- [Statements](#statements)
  - [Action Statements](#action-statements)
  - [Control Flow](#control-flow)
  - [Empty Statement](#empty-statement)
- [Expressions](#expressions)
  - [Conditions](#conditions)
  - [Instances](#instances)
- [Complete Examples](#complete-examples)
- [Grammar Reference Tables](#grammar-reference-tables)

---

## Overview

Botka is a simple imperative programming language designed for educational purposes. It features:

- **Block structure** with curly braces `{}`
- **Bilingual keywords** (English and Russian)
- **Strong typing** for numbers (integers only)
- **C-style comments**

---

## Program Structure

A valid Botka program must be wrapped between program markers:

```botka
@start
    // Statements go here
@end
```

### Program Markers

| Marker | English | Russian | Required |
|--------|---------|---------|----------|
| Start | `@start` | `@начало` | Optional |
| End | `@end` | `@конец` | Optional |

> **Note**: Program markers are optional. Code can exist without them, but using them is recommended for clarity.

### Valid Program Examples

```botka
// Minimal program (no markers)
forward 5;
```

```botka
// Full program with markers
@start
forward 5;
@end
```

```botka
// Russian version
@начало
вперед 5;
@конец
```

---

## Lexical Elements

### Keywords

Botka supports bilingual keywords. Both English and Russian forms are interchangeable.

#### Program Structure Keywords

| English | Russian | Purpose |
|---------|---------|---------|
| `@start` | `@начало` | Program start marker |
| `@end` | `@конец` | Program end marker |

#### Control Flow Keywords

| English | Russian | Purpose |
|---------|---------|---------|
| `if` | `если` | Conditional statement |
| `else` | `иначе` | Else clause |
| `while` | `пока` | While loop |
| `for` | `для` | For loop |
| `times` | `раз` | For loop counter |

#### Condition Modifier Keywords

| English | Russian | Purpose |
|---------|---------|---------|
| `not` | `не` | Negation modifier |

#### Instance Keywords

| English | Russian | Purpose |
|---------|---------|---------|
| `coin` | `монета` | Coin instance |
| `obj` | `объект` | Object instance |
| `space` | `пусто` | Empty space instance |

#### Action Keywords

| English | Russian | Purpose |
|---------|---------|---------|
| `forward` | `вперед` | Move forward |
| `backwards` | `назад` | Move backward |
| `right` | `вправо` | Turn right |
| `left` | `влево` | Turn left |

### Identifiers

Identifiers follow standard naming conventions:

```
identifier ::= [a-zA-Zа-яА-Я_][a-zA-Zа-яА-Я0-9_]*
```

**Rules:**
- Must start with a letter (Latin or Cyrillic) or underscore `_`
- Can contain letters, digits, and underscores
- Case-sensitive

**Valid identifiers:**
```
myVar
переменная
_test123
Botka_Robot
```

**Invalid identifiers:**
```
123abc     // Starts with digit
my-var     // Contains hyphen
bot!       // Contains special character
```

### Numbers

Botka supports **integer numbers only** (no floating-point).

#### Number Format

```
number ::= [+-]?[0-9]+
positive_number ::= [1-9][0-9]* | [+][1-9][0-9]*
```

#### Valid Numbers

| Number | Description |
|--------|-------------|
| `0` | Zero |
| `123` | Positive integer |
| `+456` | Explicitly positive |
| `-789` | Negative integer |

#### Invalid Numbers

| Number | Reason |
|--------|--------|
| `-0` | Negative zero not allowed |
| `+0` | Positive zero not allowed |
| `123.45` | Decimal point not allowed |
| `1e5` | Scientific notation not allowed |
| `900000000000000000000000` | Exceeds int32 range |

#### Number Range

| Type | Minimum | Maximum |
|------|---------|---------|
| int32 | -2,147,483,648 | +2,147,483,647 |

Values outside this range are considered **errors**.

### Comments

Botka supports C-style comments.

| Type | Syntax | Example |
|------|--------|---------|
| Single-line | `// ...` | `// This is a comment` |
| Multi-line | `/* ... */` | `/* Block comment */` |

**Examples:**

```botka
// Single-line comment
forward 5;

/*
 * Multi-line comment
 * Can span multiple lines
 */
backwards 3;

/* Inline comment */ right 90;
```

---

## Statements

Statements are the building blocks of Botka programs.

### Statement Types

| Type | Syntax | Description |
|------|--------|-------------|
| Action | `action number;` | Execute robot action |
| If | `if (...) { }` | Conditional execution |
| While | `while (...) { }` | Loop while condition is true |
| For | `for (... times) { }` | Loop fixed number of times |
| Empty | `;` | No-operation |

### Action Statements

Execute robot movement actions.

#### Syntax

```botka
action_type number;
```

#### Action Types

| Action | English | Russian | Description |
|--------|---------|---------|-------------|
| Forward | `forward` | `вперед` | Move forward N steps |
| Backward | `backwards` | `назад` | Move backward N steps |
| Right | `right` | `вправо` | Turn right N degrees |
| Left | `left` | `влево` | Turn left N degrees |

#### Examples

```botka
forward 5;
backwards 2;
right 90;
left 45;
вперед 10;
назад 3;
```

#### Special Cases

| Number | Behavior |
|--------|----------|
| `0` | No movement (no-op) |
| Negative | Opposite direction |

```botka
forward -5;    // Same as backwards 5
right -90;     // Same as left 90
```

---

### Control Flow

#### If Statement

Conditional execution based on sensor checks.

**Syntax:**

```botka
if (condition) {
    // statements
}

// With else
if (condition) {
    // statements
} else {
    // statements
}

// With else-if chain
if (condition) {
    // statements
} else if (condition) {
    // statements
} else {
    // statements
}
```

**Examples:**

```botka
// Simple if
if({} coin) {
    forward 1;
}

// If-else
if({not} coin) {
    forward 1;
} else {
    right 90;
}

// Else-if chain
if({} coin) {
    forward 1;
} else if({} obj) {
    right 90;
} else if({} space) {
    left 45;
} else {
    backwards 1;
}
```

#### While Loop

Execute block while condition is true.

**Syntax:**

```botka
while (condition) {
    // statements
}
```

**Example:**

```botka
// Move forward until coin is found
while({not} coin) {
    forward 1;
}
```

#### For Loop

Execute block a fixed number of times.

**Syntax:**

```botka
for (positive_number times) {
    // statements
}
```

**Important:** Only **positive numbers** are allowed (1, 2, 3, ...).

**Examples:**

```botka
for(3 times) {
    forward 1;
}

for(5 times) {
    right 90;
}

// Russian
для(10 раз) {
    вперед 1;
}
```

---

### Empty Statement

An empty statement does nothing.

**Syntax:**

```botka
;
```

**Use case:** Placeholder or intentional no-op.

---

## Expressions

### Conditions

Conditions check what's in front of the robot.

#### Syntax

```botka
(condition_modifier instance)
```

#### Condition Modifier

| Modifier | Meaning |
|----------|---------|
| `{}` | Check if instance exists |
| `{not}` | Check if instance does NOT exist |
| `{не}` | Russian: Check if instance does NOT exist |

#### Examples

```botka
// Check if coin exists
({} coin)

// Check if no coin
({not} coin)
({не} монета)

// Check for empty space
({} space)

// Check while no object
({not} obj)
```

---

### Instances

Instances represent objects in the robot's environment.

| Instance | English | Russian | Description |
|----------|---------|---------|-------------|
| Coin | `coin` | `монета` | A collectible coin |
| Object | `obj` | `объект` | An obstacle or object |
| Space | `space` | `пусто` | Empty space (nothing) |

---

## Complete Examples

### Example 1: Simple Movement

```botka
@start
// Move forward 4 steps
forward 4;
@end
```

### Example 2: Conditional Navigation

```botka
@start
// Check for coin and react
if({} coin) {
    forward 1;    // Pick up coin
} else {
    right 90;     // Turn if no coin
}
@end
```

### Example 3: Loop Until Goal

```botka
@start
// Move forward until coin is found
while({not} coin) {
    forward 1;
}

// Pick up coin
forward 1;
@end
```

### Example 4: For Loop Pattern

```botka
@start
// Draw a square
for(4 times) {
    forward 10;
    right 90;
}
@end
```

### Example 5: Complex If-Else Chain

```botka
@start
// Navigate based on what's in front
if({} coin) {
    forward 1;    // Collect coin
} else if({} obj) {
    right 90;     // Avoid object
} else if({} space) {
    forward 1;    // Move into empty space
} else {
    backwards 1;  // Default: step back
}
@end
```

### Example 6: Russian Keywords

```botka
@начало
// Программа на русском
если({не} монета) {
    вперед 1;
} иначе {
    вправо 90;
}
@конец
```

### Example 7: Nested Loops

```botka
@start
// Navigate in a grid pattern
for(3 times) {
    forward 5;
    for(2 times) {
        right 90;
    }
}
@end
```

---

## Grammar Reference Tables

### Quick Syntax Reference

| Construct | Syntax | Example |
|-----------|--------|---------|
| Program | `@start ... @end` | `@start forward 1; @end` |
| Comment (single) | `// ...` | `// comment` |
| Comment (multi) | `/* ... */` | `/* block */` |
| Action | `type N;` | `forward 5;` |
| If | `if(cond) { }` | `if({} coin) { }` |
| If-else | `if(c) { } else { }` | `if({} c) { } else { }` |
| While | `while(cond) { }` | `while({} c) { }` |
| For | `for(N times) { }` | `for(3 times) { }` |
| Empty | `;` | `;` |

### Keyword Translation Table

| English | Russian | Category |
|---------|---------|----------|
| `@start` | `@начало` | Program |
| `@end` | `@конец` | Program |
| `if` | `если` | Control |
| `else` | `иначе` | Control |
| `while` | `пока` | Control |
| `for` | `для` | Control |
| `times` | `раз` | Control |
| `not` | `не` | Modifier |
| `coin` | `монета` | Instance |
| `obj` | `объект` | Instance |
| `space` | `пусто` | Instance |
| `forward` | `вперед` | Action |
| `backwards` | `назад` | Action |
| `right` | `вправо` | Action |
| `left` | `влево` | Action |

### Operator Precedence

| Precedence | Construct | Associativity |
|------------|-----------|---------------|
| Highest | `number` | Left |
| | `action` | Left |
| | `block` | - |
| | `condition` | - |
| | `if/while/for` | Right |
| | `else-if chain` | Right |
| Lowest | `statement` | - |

### BNF Grammar Summary

```bnf
program         ::= [program_start] {statement} [program_end]
program_start   ::= "@start" | "@начало"
program_end     ::= "@end" | "@конец"

statement       ::= if_statement
                  | while_statement
                  | for_statement
                  | action_statement
                  | empty_statement

empty_statement ::= ";"

if_statement    ::= if_keyword condition block
                    {else_keyword if_keyword condition block}
                    [else_keyword block]

while_statement ::= while_keyword condition block

for_statement   ::= for_keyword for_condition block
for_condition   ::= "(" positive_number times_keyword ")"

action_statement ::= action_type number ";"

condition       ::= "(" condition_modifier instance ")"
condition_modifier ::= "{" ["not" | "не"] "}" | "{}"

instance        ::= "coin" | "монета"
                  | "obj" | "объект"
                  | "space" | "пусто"

block           ::= "{" {statement} "}"

action_type     ::= "forward" | "вперед"
                  | "backwards" | "назад"
                  | "right" | "вправо"
                  | "left" | "влево"

number          ::= [ "+" | "-" ] ( "0" | [1-9] {digit} )
positive_number ::= [1-9] {digit} | "+" [1-9] {digit}

comment         ::= "//" {character}
                  | "/*" {character} "*/"

identifier      ::= letter {letter | digit | "_"}
```

---

## See Also

- [Main README](../README.md) - General project documentation
- [Interpreter Documentation](interpreter.md) - Using the Botka interpreter
- [Examples](../examples/) - Working code examples
- [Contributing Guide](../CONTRIBUTING.md) - How to contribute
