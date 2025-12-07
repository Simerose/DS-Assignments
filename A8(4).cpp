#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


int isBSTUtil(struct Node* root, int *prev) {
    if (root == NULL)
        return 1;

    // Left subtree
    if (!isBSTUtil(root->left, prev))
        return 0;

    // Current node
    if (root->data <= *prev)
        return 0;

    *prev = root->data;

    return isBSTUtil(root->right, prev);
}

int isBST(struct Node* root) {
    int prev = -1000000; 
    return isBSTUtil(root, &prev);
}

int main() {
    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    if (isBST(root))
        printf("The given tree IS a BST.\n");
    else
        printf("The given tree is NOT a BST.\n");

    return 0;
}

