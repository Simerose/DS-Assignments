#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i;
    printf("Enter Postfix Expression: ");
    gets(exp);

    for (i = 0; exp[i]!='\0'; i++) {
        char ch = exp[i];

        
        if (ch>= '0' && ch<='9') {
            push(ch - '0');  
        }
        else {
            int b= pop();
            int a= pop();

            switch(ch){
                case '+':push(a + b); break;
                case '-':push(a - b); break;
                case '*':push(a * b); break;
                case '/':push(a / b); break;
                default: 
                    printf("Invalid operator: %c\n", ch);
                    return 1;
            }
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}


