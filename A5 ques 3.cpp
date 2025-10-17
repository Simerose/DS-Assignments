#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert node at end
void insertEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to find the middle element
void findMiddle() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    // Move fast by 2 steps and slow by 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
}

// Function to display the list
void display() {
    struct Node *temp = head;
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

    printf("Linked List: ");
    display();

    findMiddle();

    return 0;
}

