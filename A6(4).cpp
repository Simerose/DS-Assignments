#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* createNode(char x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = t->next = NULL;
    return t;
}

void insertEnd(char x) {
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

int isPalindrome() {
    if (head == NULL) return 1;

    struct Node *left = head, *right = head;

    
    while (right->next != NULL)
        right = right->next;


    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return 0;

        left = left->next;
        right = right->prev;
    }

    return 1;
}

int main() {
    int n;
    char ch;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters one by one:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ch); 
        insertEnd(ch);
    }

    if (isPalindrome())
        printf("The doubly linked list is a PALINDROME.\n");
    else
        printf("The doubly linked list is NOT a palindrome.\n");

    return 0;
}

