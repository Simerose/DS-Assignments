#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL; 
struct Node* createNode(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    return t;
}


void insertBegin(int x) {
    struct Node* t = createNode(x);

    if (last == NULL) {
        last = t;
        last->next = last;
    } else {
        t->next = last->next;
        last->next = t;
    }
}


void insertEnd(int x) {
    struct Node* t = createNode(x);

    if (last == NULL) {
        last = t;
        last->next = last;
    } else {
        t->next = last->next;
        last->next = t;
        last = t;
    }
}


void insertAfter(int key, int x) {
    if (last == NULL) {
        printf("List empty!\n");
        return;
    }

    struct Node* p = last->next;
    do {
        if (p->data == key) {
            struct Node* t = createNode(x);
            t->next = p->next;
            p->next = t;
            if (p == last) last = t;
            return;
        }
        p = p->next;
    } while (p != last->next);

    printf("Node %d not found.\n", key);
}


void deleteNode(int key) {
    if (last == NULL) {
        printf("List empty!\n");
        return;
    }

    struct Node *curr = last->next, *prev = last;

  
    if (last == last->next && last->data == key) {
        free(last);
        last = NULL;
        return;
    }

    do {
        if (curr->data == key) {
            prev->next = curr->next;
            if (curr == last) last = prev;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);

    printf("Node %d not found.\n", key);
}

void search(int key) {
    if (last == NULL) {
        printf("List empty!\n");
        return;
    }

    struct Node* p = last->next;
    int pos = 1;

    do {
        if (p->data == key) {
            printf("Node %d found at position %d\n", key, pos);
            return;
        }
        pos++;
        p = p->next;
    } while (p != last->next);

    printf("Node %d not found.\n", key);
}

void display() {
    if (last == NULL) {
        printf("List empty!\n");
        return;
    }

    struct Node* p = last->next;
    printf("Circular List: ");

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);

    printf("\n");
}

int main() {
    int choice, x, key;

    while (1) {
      printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Delete a node\n");
        printf("5. Search a node\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &x); insertBegin(x); break;
            case 2: printf("Enter value: "); scanf("%d", &x); insertEnd(x); break;
            case 3: printf("Enter key and value: "); scanf("%d%d", &key, &x); insertAfter(key,x); break;
            case 4: printf("Enter node to delete: "); scanf("%d",&key); deleteNode(key); break;
            case 5: printf("Enter value to search: "); scanf("%d",&key); search(key); break;
            case 6: display(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

