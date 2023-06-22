#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int num_values, value, i;

    printf("Enter the number of values: ");
    scanf("%d", &num_values);

    printf("Enter the values:\n");
    for (i = 0; i < num_values; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    int nodeCount = countNodes(root);

    printf("Number of nodes in the binary tree: %d\n", nodeCount);

    return 0;
}
