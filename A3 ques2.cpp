#include<stdio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
	if(top==MAX-1)
	{
		printf("Stack is full");
	}
	else 
	{
		++top;
		stack[top]=c;
	}
}

char pop(){
	if(top==-1)
	printf("Stack is empty");
	else{return stack[top--];
		
	}
}
int main(){
	char str[MAX];
	int i;
	
	printf("Enter a string:");
	gets(str);
	
	for(i=0;i<strlen(str);i++){
		push(str[i]);
	}
	printf("Reversed string:");
	while(top!=-1){
		printf("%c",pop());
	}
	printf("\n");
	return 0;
}
