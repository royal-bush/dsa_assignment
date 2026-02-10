#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Stack for operators and operands
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;

typedef struct {
    double items[MAX_SIZE];
    int top;
} NumStack;

// Initialize character stack
void initCharStack(CharStack *s) {
    s->top = -1;
}

// Initialize number stack
void initNumStack(NumStack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmptyChar(CharStack *s) {
    return s->top == -1;
}

int isEmptyNum(NumStack *s) {
    return s->top == -1;
}

// Push to character stack
void pushChar(CharStack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = c;
    }
}

// Push to number stack
void pushNum(NumStack *s, double num) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = num;
    }
}

// Pop from character stack
char popChar(CharStack *s) {
    if (!isEmptyChar(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

// Pop from number stack
double popNum(NumStack *s) {
    if (!isEmptyNum(s)) {
        return s->items[s->top--];
    }
    return 0.0;
}

// Peek character stack
char peekChar(CharStack *s) {
    if (!isEmptyChar(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Return precedence of operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Check if operator is right associative
int isRightAssociative(char op) {
    return op == '^';
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
            postfix[j++] = ' ';
        }
        // If opening bracket, push to stack
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        // If closing bracket, pop until opening bracket
        else if (ch == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            if (!isEmptyChar(&s)) {
                popChar(&s); // Remove the opening bracket
            }
        }
        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!isEmptyChar(&s) && 
                   peekChar(&s) != '(' &&
                   precedence(peekChar(&s)) > precedence(ch)) {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            // Handle right associativity
            if (!isEmptyChar(&s) && 
                peekChar(&s) != '(' &&
                precedence(peekChar(&s)) == precedence(ch) &&
                !isRightAssociative(ch)) {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            pushChar(&s, ch);
        }
    }
    
    // Pop remaining operators
    while (!isEmptyChar(&s)) {
        postfix[j++] = popChar(&s);
        postfix[j++] = ' ';
    }
    
    postfix[j] = '\0';
}

// Perform arithmetic operation
double performOperation(double num1, double num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 != 0) return num1 / num2;
            else {
                printf("Error: Division by zero\n");
                return 0;
            }
        case '^': return pow(num1, num2);
        default: return 0;
    }
}

// Evaluate postfix expression
double evaluatePostfix(char *postfix) {
    NumStack s;
    initNumStack(&s);
    
    char *token = strtok(postfix, " ");
    
    while (token != NULL) {
        if (strlen(token) == 1 && isalnum(token[0])) {
            // It's an operand
            double num = atof(token);
            pushNum(&s, num);
        }
        else if (strlen(token) == 1 && 
                (token[0] == '+' || token[0] == '-' || 
                 token[0] == '*' || token[0] == '/' || 
                 token[0] == '^')) {
            // It's an operator
            if (s.top >= 1) {
                double num2 = popNum(&s);
                double num1 = popNum(&s);
                double result = performOperation(num1, num2, token[0]);
                pushNum(&s, result);
            }
        }
        token = strtok(NULL, " ");
    }
    
    return !isEmptyNum(&s) ? s.items[s.top] : 0;
}

int main() {
    printf("=== Infix to Postfix Conversion and Evaluation ===\n\n");
    
    // Test expressions
    char expressions[4][50] = {
        "5+3",
        "(5+3)*2",
        "5+3*2",
        "((15/(7-(1+1)))*3)-2+(2+(1+1))"
    };
    
    for (int i = 0; i < 4; i++) {
        char postfix[MAX_SIZE];
        char temp[MAX_SIZE];
        
        strcpy(temp, expressions[i]);
        
        // Convert infix to postfix
        infixToPostfix(expressions[i], postfix);
        
        // Evaluate postfix
        strcpy(temp, postfix);
        double result = evaluatePostfix(temp);
        
        printf("Expression %d:\n", i + 1);
        printf("  Infix:   %s\n", expressions[i]);
        printf("  Postfix: %s\n", postfix);
        printf("  Result:  %.2f\n\n", result);
    }
    
    return 0;
}
