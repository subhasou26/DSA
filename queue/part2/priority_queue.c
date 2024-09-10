#include <stdio.h>
#include <stdlib.h>

// Define the structure of a priority queue node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Define the priority queue structure
struct PriorityQueue {
    struct Node* front;
};

// Function to create a new priority queue node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->front = NULL;
    return queue;
}

// Function to enqueue an element with priority
void enqueue(struct PriorityQueue* queue, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (queue->front == NULL || priority > queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        struct Node* current = queue->front;
        while (current->next != NULL && priority <= current->next->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to dequeue the element with the highest priority
void dequeue(struct PriorityQueue* queue) {
    if (queue->front == NULL)
        return;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
}

// Function to display elements in the priority queue
void display(struct PriorityQueue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct PriorityQueue* priorityQueue = createPriorityQueue();

    enqueue(priorityQueue, 10, 3);
    enqueue(priorityQueue, 20, 1);
    enqueue(priorityQueue, 30, 2);

    printf("Priority Queue elements: ");
    display(priorityQueue);

    //dequeue(priorityQueue);

    printf("Priority Queue elements after dequeue: ");
    display(priorityQueue);

    return 0;
}
