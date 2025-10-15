#include <stdio.h>
#define MAX 5   

int stack[MAX];
int top = -1;
int main(){
	int choice,item;
	
	while(1){
		printf("1. Push\n");
		printf("2. Pop\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. Display\n");
        printf("6. Peek\n");
       
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	//Push
        	case 1:
        		if(top==MAX-1)
        		printf("Stack is full");
        		else{
        			printf("Enter element into push");
        			scanf("%d",&item);
        			top++;
        			stack[top]=item;
        			printf("%d pushed into stack\n",item);
				}
				break;
				
				case 2:
					if(top==-1)
					printf("stack is empty");
					else{
					printf("element popped",stack[top]);
					top--;}
					break;
					
				case 3:
					if(top==-1)
					printf("Stack is empty");
					else
					printf("stack is not empty");
					break;
					
				case 4:
					if(top==MAX-1)
					printf("Stack is full");
					else
					printf("Stack is not full");
					break;
					
				case 5:
					if(top==-1)
					printf("Stack is empty");
					else{
						printf("stack elements are:");
						for(int i=top;i>=0;i--)
						printf("%d",stack[i]);
						printf("\n");
					}
					break;
					case 6:
						if(top==-1)
						printf("Stack is empty");
						else
						printf("Top element:%d",stack[top]);
						break;
					
					default:
					printf("Invalid choice");	
					
		}
	}
	return 0;
}
