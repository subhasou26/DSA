#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node with the given data
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height of a binary tree
int calculateHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to check if a binary tree is balanced
bool isBalanced(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    
    return (abs(leftHeight - rightHeight) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

// Function to check if a binary tree is a valid Binary Search Tree
bool isBSTUtil(TreeNode* root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    
    if (root->data <= min || root->data >= max) {
        return false;
    }
    
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBinarySearchTree(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Function to find the diameter (longest path between any two nodes) of the binary tree
int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculateDiameter(TreeNode* root, int* height) {
    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = 0, rightDiameter = 0;

    if (root == NULL) {
        *height = 0;
        return 0;
    }

    leftDiameter = calculateDiameter(root->left, &leftHeight);
    rightDiameter = calculateDiameter(root->right, &rightHeight);

    *height = max(leftHeight, rightHeight) + 1;

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

int findDiameter(TreeNode* root) {
    int height = 0;
    return calculateDiameter(root, &height);
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6);

    printf("Is the tree balanced? %s\n", isBalanced(root) ? "Yes" : "No");
    printf("Is the tree a Binary Search Tree? %s\n", isBinarySearchTree(root) ? "Yes" : "No");
    printf("Diameter of the tree: %d\n", findDiameter(root));

    return 0;
}
