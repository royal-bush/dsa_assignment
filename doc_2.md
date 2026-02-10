Program 2: Infix to Postfix Conversion and Evaluation

Overview
This program converts mathematical expressions from infix notation (standard form like 5+3*2) to postfix notation (Reverse Polish Notation like 5 3 2 * +), and then evaluates the postfix expression to compute the result.

Data Structures

-Character Stack
typedef struct {
char items[MAX_SIZE];
int top;
} CharStack;

Used to store operators during infix to postfix conversion
MAX_SIZE is set to 100

-Number Stack
typedef struct {
double items[MAX_SIZE];
int top;
} NumStack;

Used to store operands during postfix evaluation
Stores double values to handle division results

Functions Implemented

1.Stack Operations
initCharStack() and initNumStack()
Initialize character and number stacks

2.pushChar() and pushNum()
Push elements onto stacks

3.popChar() and popNum()
Pop elements from stacks

4.isEmptyChar() and isEmptyNum()
Check if stacks are empty

5.peekChar()
View top element without removal

6.precedence(char op)
Purpose :Return operator precedence for proper conversion

Returns
1 for + and -
2 for * and /
3 for ^ (exponentiation)

Higher value indicates higher precedence

7.isRightAssociative(char op)
Purpose :Check if operator is right associative

Returns
1 for ^
0 for other operators

Used to handle exponentiation correctly, which is evaluated right to left

8.infixToPostfix(char *infix, char *postfix)
Purpose :Convert infix expression to postfix using the Shunting Yard algorithm

Algorithm

Scan infix expression from left to right. If operand is found, add it to postfix output.If opening parenthesis is found,we push it to operator stack.If closing parenthesis is foundthen the pop operators to output until opening parenthesis is encountered.
If operator is found. Pop operators with higher or equal precedence based on associativity.Push the current operator onto the stack. After scanning the entire expression, we pop all remaining operators to postfix output.

Supported operations
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exponentiation

Sample Output

Infix to Postfix Conversion and Evaluation

Expression 1
Infix: 5+3
Postfix: 5 3 +
Result: 8.00

Expression 2
Infix: (5+3)*2
Postfix: 5 3 + 2 *
Result: 16.00

Expression 3
Infix: 5+3*2
Postfix: 5 3 2 * +
Result: 11.00

Expression 4
Infix: ((15/(7-(1+1)))*3)-2+(2+(1+1))
Postfix: 15 7 1 1 + - / 3 * 2 - 2 1 1 + + +
Result: 9.50

Algorithm Explanation

Shunting Yard Algorithm
The algorithm uses a stack to manage operator precedence and associativity
Operators with higher precedence are processed first
Parentheses are used to override precedence rules
Left associative operators use higher precedence to pop
Right associative operators such as exponentiation use strict higher precedence

Postfix Evaluation
A stack-based evaluation method
Operands are pushed onto the stack
When an operator is encountered, two operands are popped, evaluated, and the result is pushed back
At the end, a single value remains as the final result

Compilation and Execution

gcc -o prog_2 prog_2.c -lm
./prog_2

The -lm flag is required to link the math library for the pow function

