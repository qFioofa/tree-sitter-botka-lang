# Gammer

This is a grammer for botka lang.

> NOTE: [the ru translation of keywords is in the end](#Ru-version)

## Define the programm

Anything outside will be ignored

```
@start
...
@end
```

## Comments

Comments in C style

```
// Comment

/*
Big comment
*/
```

## Numbers

Positive or negetive `int` numbers.
Anything that not in range of `int` type is considered as `error`

> int range: -2,147,483,648 to +2,147,483,647

```
+123

123

-123

0

-0 <- error!

+0 <- error!

900000000000000000000000 <- error!

123.0 <- error! int only
```

# Keywords

## Instances

Words that represents what is going on the map. It is used in [if](#if-statement), [for](#for-loop) or in [while](#while-loop) blocks

```
coin

obj

space
```

## if statement

Checks if the `instance` exists infont of the `robot` or not.
The `not` infront reverses the result

```
if({not} {Instance}) {
    ...
};
```

Also supports the else block!

```
if({not} {Instance}) {
    ...
} else {
    ...
};
```

Need to check for other `instance`? Use `else if` block!

```
if({not} {Instance}) {
    ...
} else if({} {Instance}) {
    ...
};
```

Big `if-else` block example:

```
if({not} {Instance}) {
    ...
} else if({} {Instance}) {
    ...
} else if({} {Instance}) {
    ...
} else {

};
```

The brackes - `{}` is a part of the syntex. You can leave empty `{}` if you dont need `not` operator.
Example:

```
if({} {Instance}) {
    ...
};
```

## Actions

Here is the list of robot movement operators presented.

> NOTE: negetive numbers are allowed. It just means the opposite action of that's required to do!
> if the 0, then it does nothing

```
forward {number};
backwards {number};
```

The following actions just turning it in reletive diraction.

```
right {number};
left {number};
```

## while loop

While block. Runs inner block until statement in `()` is `true`

```
while({not} {Instance}) {
    ...
};
```

## for loop

To specify how much `times` inner block should be running.

```
for({+number} times){
    ...
};
```

# Notes

- `...` - means other logic
- `+number` means `positive number only`
- the `{}`, `;`, `(...)` are required where it is specifeid in syntex

# Ru version

List of duplication of keywords in `ru`

```
@start -> @начало

@end -> @конец

coin -> монета

obj -> объект

space -> пусто

if -> если

not -> не

else -> иначе

forward -> вперед

backwards -> назад

right -> вправо

left -> влево

while -> пока

for -> для

times -> раз
```
