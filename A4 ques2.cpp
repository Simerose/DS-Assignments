#include <stdio.h>
#define MAX 5  

int queue[MAX];
int front= -1, rear= -1;

int main(){
    int choice,item;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. Display\n");
        printf("6. Peek\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            // ENQUEUE
            case 1:
                if ((front== 0 && rear== MAX-1) || (rear+1) %MAX== front)
                    printf("Circular Queue is full\n");
                else {
                    printf("Enter element to enqueue: ");
                    scanf("%d",&item);
                    if (front== -1) front = 0;  
                    rear= (rear + 1) % MAX;
                    queue[rear]= item;
                    printf("%d enqueued to circular queue\n",item);
                }
                break;

            // DEQUEUE
            case 2:
                if (front== -1) {
                    printf("Circular Queue is Empty\n");
                } else {
                    printf("Dequeued element: %d\n",queue[front]);
                    if (front== rear) {  
                        front= rear= -1;
                    } else {
                        front= (front + 1)% MAX;
                    }
                }
                break;

            // isEmpty
            case 3:
                if (front== -1)
                    printf("Circular Queue is Empty.\n");
                else
                    printf("Circular Queue is not Empty.\n");
                break;

            // isFull
            case 4:
                if ((front == 0 && rear== MAX - 1) || (rear+1)% MAX== front)
                    printf("Circular Queue is Full.\n");
                else
                    printf("Circular Queue is NOT Full.\n");
                break;

            // DISPLAY
            case 5:
                if (front== -1)
                    printf("Circular Queue is Empty.\n");
                else {
                    printf("Circular Queue elements: ");
                    int i= front;
                    while (1) {
                        printf("%d ",queue[i]);
                        if (i== rear) break;
                        i= (i + 1) % MAX;
                    }
                    printf("\n");
                }
                break;

            // PEEK
            case 6:
                if (front == -1)
                    printf("Circular Queue is Empty\n");
                else
                    printf("Front element is: %d\n", queue[front]);
                break;

            

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

