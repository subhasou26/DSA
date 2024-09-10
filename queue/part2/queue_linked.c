#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new queue node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element
void dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL)
        queue->rear = NULL;
}

// Function to display elements in the queue
void display(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Queue elements: ");
    display(queue);

    dequeue(queue);

    printf("Queue elements after dequeue: ");
    display(queue);

    return 0;
}
