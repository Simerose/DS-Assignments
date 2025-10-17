#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert at end
void insertEnd(int val) {
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data= val;
    newNode->next= NULL;

    if (head== NULL)
        head= newNode;
    else {
        struct Node *temp= head;
        while (temp->next!= NULL)
            temp= temp->next;
        temp->next= newNode;
    }
}

// Function to display list
void display() {
    struct Node *temp= head;
    if (temp== NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

// Function to count and delete all occurrences of a key
void deleteOccurrences(int key) {
    struct Node *temp= head, *prev = NULL;
    int count = 0;

    // Count occurrences first
    while (temp!= NULL) {
        if (temp->data== key)
            count++;
        temp= temp->next;
    }

    // Delete all occurrences
    temp= head;
    while (temp!= NULL) {
        if (temp->data== key) {
            if (temp== head) {
                head= head->next;
                free(temp);
                temp= head;
            } else {
                prev->next= temp->next;
                free(temp);
                temp= prev->next;
            }
        } else {
            prev= temp;
            temp= temp->next;
        }
    }

    printf("Count: %d\n", count);
}

int main() {
    // Example input: 1 -> 2 -> 1 -> 2 -> 1 -> 3 -> 1
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(3);
    insertEnd(1);

    printf("Original Linked List: ");
    display();

    int key= 1;
    deleteOccurrences(key);

    printf("Updated Linked List: ");
    display();

    return 0;
}

