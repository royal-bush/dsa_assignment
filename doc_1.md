# Program 1: Balanced Parentheses Checker

## Overview
This program checks whether a given mathematical expression has balanced parentheses, brackets, and braces. It uses a stack data structure to efficiently validate the balance of different types of brackets.

## Data Structures

### Stack Structure

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

: `items[]`: Array to store the opening brackets, `top`: Index pointing to the top of the stack (-1 when empty),  `MAX_SIZE`: Maximum capacity set to 100

Functions Implemented

1.initStack(Stack *s)
Purpose: Initialize the stack with top = -1
Parameters: Pointer to Stack structure
Returns: void

2.isEmpty(Stack *s)
Purpose: Check if stack is empty
Parameters: Pointer to Stack structure
Returns: true if empty, false otherwise

3.isFull(Stack *s)
Purpose: Check if stack is full
Parameters: Pointer to Stack structure
Returns: true if full, false otherwise

4.push(Stack *s, char c)
Purpose: Insert an opening bracket onto the stack
Parameters: Pointer to Stack, character to push
Returns: void

5.pop(Stack *s)
Purpose: Remove and return the top element from stack
Parameters: Pointer to Stack
Returns: Character from top of stack, '\0' if empty

6.peek(Stack *s)
Purpose: View the top element without removing it
Parameters: Pointer to Stack
Returns: Top element or '\0' if empty

7.areParenthesesBalanced(char *expression)
Purpose: Main logic to check if brackets are balanced

Algorithm:

Iterate through each character in the expression. If an opening bracket (, [,or { is found, push it onto the stack. If a closing bracket ), ], or } is found:
Check if the stack is empty (unmatched closing bracket).Pop from the stack and verify it matches the closing bracket.If it does not match, return false.After processing all characters, the stack should be empty for a balanced expression.
Parameters: String containing the expression
Returns: true if balanced, false otherwise

## Main Function Organization

The main() function:
1. Defines an array of 3 test expressions
2. For each expression:
   - Displays the expression
   - Calls areParenthesesBalanced() to check validity
   - Displays the result (BALANCED or NOT BALANCED)

## Sample Output

=== Parentheses Balancing Checker ===

Expression 1: a + (b - c) * (d
Status: NOT BALANCED ✗

Expression 2: m + [a - b * (c + d * {m)]
Status: NOT BALANCED ✗

Expression 3: a + (b - c)
Status: BALANCED ✓


## Testing

The program tests three different expressions:
1. a + (b - c) * (d - Missing closing parenthesis (NOT BALANCED)
2. m + [a - b * (c + d * {m)] - Brackets don't match properly (NOT BALANCED)
3. a + (b - c) - All brackets properly balanced (BALANCED)

## Compilation and Execution


gcc -o prog_1 prog_1.c
./prog_1


