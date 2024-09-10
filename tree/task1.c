#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
void insertNode(struct Node* root, int data, char choice) {
    struct Node* newNode = createNode(data);
    if (choice == 'L' || choice == 'l') {
        if (root->left == NULL) {
            root->left = newNode;
        } else {
            insertNode(root->left, data, choice);
        }
    } else if (choice == 'R' || choice == 'r') {
        if (root->right == NULL) {
            root->right = newNode;
        } else {
            insertNode(root->right, data, choice);
        }
    } else {
        printf("Invalid choice, use 'L' for left and 'R' for right\n");
    }
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to find the height of the binary tree
int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Function to count the number of leaf nodes in the binary tree
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    char position;

    while (1) {
        printf("Enter data to insert into the tree: ");
        scanf("%d", &data);
        printf("Enter the position (L for left, R for right): ");
        scanf(" %c", &position);
        if (root == NULL) {
            root = createNode(data);
        } else {
            insertNode(root, data, position);
        }
        printf("Binary tree (inorder traversal): ");
        inorderTraversal(root);
        printf("\n");

        printf("Do you want to insert more nodes? (1/0): ");
        scanf("%d", &choice);
        if (choice != 1) {
            break;
        }
    }

    printf("Binary tree (inorder traversal): ");
    inorderTraversal(root);
    printf("\n");

    printf("Binary tree (postorder traversal): ");
    postorderTraversal(root);
    printf("\n");

    printf("Binary tree (preorder traversal): ");
    preorderTraversal(root);
    printf("\n");

    int height = findHeight(root);
    printf("Height of the binary tree: %d\n", height);

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes in the binary tree: %d\n", leafCount);

    return 0;
}

