#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* createNode(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = t->next = NULL;
    return t;
}

void insertEnd(int x) {
    struct Node* t = createNode(x);
    if (head == NULL) {
        head = t;
        return;
    }
    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = t;
    t->prev = p;
}

int sizeDoubly() {

    int count = 0;
    struct Node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("Size of Doubly Linked List= %d\n", sizeDoubly());
    return 0;
}

