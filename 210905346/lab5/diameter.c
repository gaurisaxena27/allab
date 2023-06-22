#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the height of a binary tree
int calculateHeight(Node* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

// Function to calculate the diameter of a binary tree
int calculateDiameter(Node* root) {
    if (root == NULL)
        return 0;

    // Calculate the height of the left subtree
    int leftHeight = calculateHeight(root->left);

    // Calculate the height of the right subtree
    int rightHeight = calculateHeight(root->right);

    // Calculate the diameter recursively for the left and right subtrees
    int leftDiameter = calculateDiameter(root->left);
    int rightDiameter = calculateDiameter(root->right);

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

Node* buildBinaryTree() {
    int data;
    printf("Enter the data (or -1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    Node* newNode = createNode(data);

    printf("Enter the left child of %d:\n", data);
    newNode->left = buildBinaryTree();

    printf("Enter the right child of %d:\n", data);
    newNode->right = buildBinaryTree();

    return newNode;
}

int main() {
    Node* root = buildBinaryTree();
    int diameter = calculateDiameter(root);
    printf("The diameter of the binary tree is: %d\n", diameter);
    return 0;
}