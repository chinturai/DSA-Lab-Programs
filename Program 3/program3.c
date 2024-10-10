#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Global stack and control variables
char stack[MAX];
int top = -1;  // Stack pointer

// Global array for result (postfix expression)
char postfix[MAX];

// Stack operation functions

// Push to the stack
void push(char value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Peek at the top of the stack
char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

// Check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

// Get precedence of the operator
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Convert infix to postfix using globally declared stack and postfix array
void infixToPostfix(char* infix) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {  // If operand, add to postfix
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop '('
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Function to evaluate postfix expression using globally declared stack
int evaluatePostfix() {
    int i = 0;
    char ch;
    int op1, op2;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int and push to stack
        } else if (isOperator(ch)) {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
                case '^': push((int)pow(op1, op2)); break;
            }
        }
    }

    return pop();  // Return the final result
}

// Main function
int main() {
    char infix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);

    // Evaluate postfix expression
    int result = evaluatePostfix();
    printf("Evaluation result: %d\n", result);

    return 0;
}
