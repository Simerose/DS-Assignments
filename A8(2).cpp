#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Recursive Search
struct Node* searchRecursive(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// Non-recursive search
struct Node* searchNonRecursive(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

struct Node* findMax(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node* inorderSuccessor(struct Node* root, struct Node* node) {
    if (node == NULL)
        return NULL;


    if (node->right != NULL)
        return findMin(node->right);

    struct Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else
            break;
    }
    return succ;
}

struct Node* inorderPredecessor(struct Node* root, struct Node* node) {
    if (node == NULL)
        return NULL;

    if (node->left != NULL)
        return findMax(node->left);


    struct Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else
            break;
    }
    return pred;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 40;

    if (searchRecursive(root, key))
        printf("Recursive Search: %d Found\n", key);
    else
        printf("Recursive Search: %d Not Found\n", key);

    if (searchNonRecursive(root, key))
        printf("Non-Recursive Search: %d Found\n", key);
    else
        printf("Non-Recursive Search: %d Not Found\n", key);

   
    printf("Minimum = %d\n", findMin(root)->data);
    printf("Maximum = %d\n", findMax(root)->data);

    
    struct Node* node = searchRecursive(root, key);
    struct Node* succ = inorderSuccessor(root, node);
    if (succ)
        printf("Inorder Successor of %d is %d\n", key, succ->data);
    else
        printf("No Inorder Successor for %d\n", key);


    struct Node* pred = inorderPredecessor(root, node);
    if (pred)
        printf("Inorder Predecessor of %d is %d\n", key, pred->data);
    else
        printf("No Inorder Predecessor for %d\n", key);

    return 0;
}

