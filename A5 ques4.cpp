#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head= NULL;

void insertEnd(int val) {
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data= val;
    newNode->next= NULL;

    if (head== NULL)
        head= newNode;
    else {
        struct Node *temp= head;
        while (temp->next!= NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;         
    }

    head = prev; 
}

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(val);
    }

    printf("Original Linked List: ");
    display();

    reverseList();

    printf("Reversed Linked List: ");
    display();

    return 0;
}

