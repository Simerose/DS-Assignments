#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
       return -1;
    } else {
        return stack[top--];
    }
}


int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0;  
            }
        }
    }

    
    return (top == -1);
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    gets(expression); 

    if (isBalanced(expression))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression does not have balanced parentheses.\n");

    return 0;
}

