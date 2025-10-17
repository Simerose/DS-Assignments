#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBegin(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data= val;
    newNode->next= head;
    head= newNode;
}

// Insert at end
void insertEnd(int val) {
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data= val;
    newNode->next= NULL;
    if (head== NULL)
        head= newNode;
    else {
        struct Node *temp = head;
        while (temp->next!= NULL)
            temp= temp->next;
        temp->next= newNode;
    }
}

// Insert before a specific node
void insertBefore(int val, int beforeVal) {
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head== NULL) return;
    if (head->data== beforeVal) {
        newNode->next= head;
        head= newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next!= NULL && temp->next->data != beforeVal)
        temp= temp->next;

    if (temp->next== NULL)
        printf("Node %d not found.\n", beforeVal);
    else {
        newNode->next= temp->next;
        temp->next= newNode;
    }
}

// Insert after a specific node
void insertAfter(int val, int afterVal) {
    struct Node *temp= head;
    while (temp!= NULL && temp->data!= afterVal)
        temp= temp->next;
    if (temp== NULL)
        printf("Node %d not found.\n", afterVal);
    else {
        struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
        newNode->data= val;
        newNode->next= temp->next;
        temp->next= newNode;
    }
}

// Delete from beginning
void deleteBegin() {
    if (head== NULL)
        printf("List is empty.\n");
    else {
        struct Node *temp= head;
        head= head->next;
        free(temp);
    }
}

// Delete from end
void deleteEnd() {
    if (head== NULL)
        printf("List is empty.\n");
    else if (head->next== NULL) {
        free(head);
        head= NULL;
    } else {
        struct Node *temp= head;
        while (temp->next->next!= NULL)
            temp= temp->next;
        free(temp->next);
        temp->next= NULL;
    }
}

// Delete specific node
void deleteNode(int val) {
    if (head== NULL)
        printf("List is empty.\n");
    else if (head->data== val) {
        struct Node *temp= head;
        head= head->next;
        free(temp);
    } else {
        struct Node *temp= head;
        while (temp->next!= NULL && temp->next->data != val)
            temp= temp->next;
        if (temp->next== NULL)
            printf("Node %d not found.\n", val);
        else {
            struct Node *del= temp->next;
            temp->next= del->next;
            free(del);
        }
    }
}

// Search for a node
void searchNode(int val) {
    struct Node *temp = head;
    int pos = 1;
    while (temp!= NULL) {
        if (temp->data== val) {
            printf("Node %d found at position %d\n", val, pos);
            return;
        }
        temp= temp->next;
        pos++;
    }
    printf("Node %d not found.\n", val);
}

// Display all nodes
void display() {
    if (head== NULL)
        printf("List is empty.\n");
    else {
        struct Node *temp= head;
        printf("List: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp= temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, val, key;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before Node\n");
        printf("4. Insert After Node\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete Specific Node\n");
        printf("8. Search Node\n");
        printf("9. Display List\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBegin(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Insert before value: ");
                scanf("%d", &key);
                insertBefore(val, key);
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Insert after value: ");
                scanf("%d", &key);
                insertAfter(val, key);
                break;
            case 5:
                deleteBegin();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &val);
                searchNode(val);
                break;
            case 9:
                display();
                break;
            
            default:
                printf("Invalid choice");
        }
    }
}

