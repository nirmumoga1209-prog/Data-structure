#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

        // 1. If character is an operand, add it to output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // 2. If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // 3. If ')', pop until '(' is found
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // 4. If operator
        else if (isOperator(c)) {
            if (c == '^') {
                // '^' is right-associative: pop only if stack top has STRICTLY higher precedence
                while (top != -1 && precedence(peek()) > precedence(c)) {
                    postfix[j++] = pop();
                }
            } else {
                // '+,-,*,/' are left-associative: pop if stack top has higher OR equal precedence
                while (top != -1 && precedence(peek()) >= precedence(c)) {
                    postfix[j++] = pop();
                }
            }
            push(c);
        }
        i++;
    }

    // 5. Pop remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}