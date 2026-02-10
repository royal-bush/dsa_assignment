# Program 2: Infix to Postfix Conversion and Evaluation

## Overview
This program converts mathematical expressions from infix notation (standard form like `5+3*2`) to postfix notation (Reverse Polish Notation like `5 3 2 * +`), and then evaluates the postfix expression to compute the result.

## Data Structures

### Character Stack
```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;
```
- Used to store operators during infix to postfix conversion
- `MAX_SIZE = 100`

### Number Stack
```c
typedef struct {
    double items[MAX_SIZE];
    int top;
} NumStack;
```
- Used to store operands during postfix evaluation
- Stores double values to handle division results

## Functions Implemented

### Stack Operations
- **`initCharStack()` / `initNumStack()`**: Initialize stacks
- **`pushChar()` / `pushNum()`**: Push elements onto stacks
- **`popChar()` / `popNum()`**: Pop elements from stacks
- **`isEmptyChar()` / `isEmptyNum()`**: Check if stacks are empty
- **`peekChar()`**: View top element without removal

### Conversion and Evaluation Functions

#### 1. `precedence(char op)`
- **Purpose**: Return operator precedence for proper conversion
- **Returns**: 
  - 1 for + and -
  - 2 for * and /
  - 3 for ^ (exponentiation)
- **Key**: Higher value = higher precedence

#### 2. `isRightAssociative(char op)`
- **Purpose**: Check if operator is right associative
- **Returns**: 1 for ^, 0 for others
- **Note**: Used to handle exponentiation correctly (right to left)

#### 3. `infixToPostfix(char *infix, char *postfix)`
- **Purpose**: Convert infix expression to postfix using Shunting Yard algorithm
- **Algorithm**:
  1. Scan infix expression left to right
  2. If operand: add to postfix output
  3. If `(`: push to operator stack
  4. If `)`: pop operators to output until `(` found
  5. If operator: 
     - Pop operators with higher/equal precedence (considering associativity)
     - Push current operator
  6. After scanning: pop all remaining operators to output
- **Parameters**: Input infix string, output postfix string

#### 4. `performOperation(double num1, double num2, char op)`
- **Purpose**: Perform arithmetic operation on two operands
- **Supported Operations**: +, -, *, /, ^
- **Returns**: Result of operation
- **Handles**: Division by zero check

#### 5. `evaluatePostfix(char *postfix)`
- **Purpose**: Evaluate postfix expression
- **Algorithm**:
  1. Parse postfix expression token by token
  2. If operand: push to stack
  3. If operator: pop two operands, perform operation, push result
  4. Final result is the only element in stack
- **Parameters**: Postfix expression string
- **Returns**: Numerical result of evaluation

## Main Function Organization

The `main()` function:
1. Defines array of test infix expressions
2. For each expression:
   - Converts infix to postfix using `infixToPostfix()`
   - Evaluates postfix using `evaluatePostfix()`
   - Displays infix, postfix, and result

## Sample Output

```
=== Infix to Postfix Conversion and Evaluation ===

Expression 1:
  Infix:   5+3
  Postfix: 5 3 + 
  Result:  8.00

Expression 2:
  Infix:   (5+3)*2
  Postfix: 5 3 + 2 * 
  Result:  16.00

Expression 3:
  Infix:   5+3*2
  Postfix: 5 3 2 * + 
  Result:  11.00

Expression 4:
  Infix:   ((15/(7-(1+1)))*3)-2+(2+(1+1))
  Postfix: 15 7 1 1 + - / 3 * 2 - 2 1 1 + + + 
  Result:  9.50
```

## Algorithm Explanation

### Shunting Yard Algorithm
The algorithm uses a stack to handle operator precedence and associativity:
- Operators with higher precedence are processed first
- Parentheses are used to override precedence
- Left-associative operators (most): use higher precedence to pop
- Right-associative operators (^): use higher precedence to pop

### Postfix Evaluation
Simple stack-based evaluation:
- Operands are pushed onto stack
- When operator found, pop two operands, compute, and push result
- Single value remains when complete

## Complexity Analysis
- **Time Complexity**: O(n) for both conversion and evaluation where n is expression length
- **Space Complexity**: O(m) where m is the maximum depth of nested expressions

## Supported Operations
- `+` Addition
- `-` Subtraction
- `*` Multiplication
- `/` Division (with zero check)
- `^` Exponentiation (right associative)

## Compilation and Execution

```bash
gcc -o prog_2 prog_2.c -lm
./prog_2
```
Note: `-lm` flag required to link math library for `pow()` function

## Limitations
- Single digit/character operands (can be extended for multi-digit numbers)
- No support for trigonometric or logarithmic functions
- No support for unary operators (-, +)
