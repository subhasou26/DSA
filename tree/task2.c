#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
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
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
// Function to insert a node into the BST
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the BST
TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) { // one child at right
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) { // ine child at left
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findMin(root->right); // both side has child
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to find the Lowest Common Ancestor (LCA) of two nodes in the BST
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    } else if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }
    return root;
}

// Structure for a queue node in level-order traversal
typedef struct QueueNode {
    TreeNode* data;
    struct QueueNode* next;
} QueueNode;

// Structure for a queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to create a new queue node
QueueNode* createQueueNode(TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = node;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a node in the queue
void enqueue(Queue* queue, TreeNode* node) {
    QueueNode* newNode = createQueueNode(node);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue a node from the queue
TreeNode* dequeue(Queue* queue) {
    if (queue->front == NULL) return NULL;
    QueueNode* temp = queue->front;
    TreeNode* node = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}

// Function to perform level-order traversal of a binary tree
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front) {
        TreeNode* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left) {
            enqueue(queue, current->left);
        }
        if (current->right) {
            enqueue(queue, current->right);
        }
    }
}

int main() {
    TreeNode* root = NULL;
    int values[] = {4, 2, 6, 1, 3, 5, 7};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    printf("BST in-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    int keyToSearch = 2;
    TreeNode* searchResult = search(root, keyToSearch);
    if (searchResult != NULL) {
        printf("%d found in the BST.\n", keyToSearch);
    } else {
        printf("%d not found in the BST.\n", keyToSearch);
    }

    int keyToDelete = 4;
    root = deleteNode(root, keyToDelete);
    printf("BST after deleting %d: in-order traversal: ", keyToDelete);
    inOrderTraversal(root);
    printf("\n");

    int n1 = 3, n2 = 6;
    TreeNode* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("Lowest Common Ancestor of %d and %d is %d.\n", n1, n2, lca->data);
    } else {
        printf("Lowest Common Ancestor not found.\n");
    }

    printf("Level-order traversal of the BST: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
