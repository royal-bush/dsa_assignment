#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push operation
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++s->top] = c;
    }
}

// Pop operation
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

// Peek operation
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Check if parentheses are balanced
bool areParenthesesBalanced(char *expression) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        
        // If opening bracket, push it
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        }
        // If closing bracket, check if it matches
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) {
                return false;
            }
            
            char top = pop(&s);
            
            // Check if brackets match
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    // Stack should be empty if all parentheses are balanced
    return isEmpty(&s);
}

int main() {
    // Test expressions
    char expressions[3][100] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    
    printf("=== Parentheses Balancing Checker ===\n\n");
    
    for (int i = 0; i < 3; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i]);
        
        if (areParenthesesBalanced(expressions[i])) {
            printf("Status: BALANCED ✓\n\n");
        } else {
            printf("Status: NOT BALANCED ✗\n\n");
        }
    }
    
    return 0;
}
