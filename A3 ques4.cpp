#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX-1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}


int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) { 
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop(); 
        }
        else { 
            while (precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0'; 
    printf("Postfix Expression: %s\n", postfix);
}


int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    gets(infix); 

    infixToPostfix(infix);
    return 0;
}

