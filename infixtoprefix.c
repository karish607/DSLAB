#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c;
    }
}
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
void reverse(char* str) {
    int len = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char ch;
    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}
void infixToPrefix(char* infix, char* prefix) {
    char reversedInfix[MAX], postfix[MAX];
    int i;
    strcpy(reversedInfix, infix);
    reverse(reversedInfix);
    for (i = 0; i < strlen(reversedInfix); i++) {
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
    }
    top = -1; 
    infixToPostfix(reversedInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}
int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}

