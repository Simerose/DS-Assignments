void displayCircular(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* head = last->next;
    struct Node* p = head;
    printf("Output: ");
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);

    printf("%d", head->data);

    printf("\n");
}

