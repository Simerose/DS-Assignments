#include <stdio.h>
#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;

int main() {
    int choice, item;

    while (1) {
        
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. Display\n");
        printf("6. Peek\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // ENQUEUE
            case 1:
                if (rear== MAX-1)
                    printf("Queue is Full\n");
                else {
                    printf("Enter element to enqueue: ");
                    scanf("%d", &item);
                    if (front == -1) front = 0;  
                    rear++;
                    queue[rear] = item;
                    printf("%d enqueued to queue\n", item);
                }
                break;

            // DEQUEUE
            case 2:
                if (front== -1 || front>rear) {
                    printf("Queue is Empty\n");
                    front= -1;rear= -1;
                } else {
                    printf("Dequeued element: %d\n", queue[front]);
                    front++;
                }
                break;

            // isEmpty
            case 3:
                if (front== -1 || front>rear)
                    printf("Queue is Empty.\n");
                else
                    printf("Queue is not Empty.\n");
                break;

            // isFull
            case 4:
            	if (rear== MAX - 1)
                    printf("Queue is Full\n");
                else
                    printf("Queue is notFull.\n");
                break;

            // DISPLAY
            case 5:
                if (front== -1 || front>rear)
                    printf("Queue is Empty\n");
                else {
                    printf("Queue elements: ");
                    for (int i= front; i<= rear; i++)
                        printf("%d ",queue[i]);
                    
                }
                break;

            // PEEK
            case 6:
                if (front== -1 || front>rear)
                    printf("Queue is Empty\n");
                else
                    printf("Front element is: %d\n",queue[front]);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


