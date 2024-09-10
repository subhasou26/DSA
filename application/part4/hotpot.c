#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define a structure for QueueNode
struct QueueNode {
    char name[50];
    struct QueueNode* next;
};

// Function to create an empty queue and return its address
struct QueueNode* createQueue() {
    return NULL;
}

// Function to check if the queue is empty
bool isEmpty(struct QueueNode* queue) {
    return queue == NULL;
}

// Function to add a new player (name) to the queue
struct QueueNode* enqueuePlayer(struct QueueNode* rear, const char* name) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (isEmpty(rear)) {
        newNode->next = newNode; // Circular reference for the first node
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
    }

    return newNode;
}

// Function to remove and return the front player from the queue
struct QueueNode* dequeuePlayer(struct QueueNode* rear) {
    if (isEmpty(rear)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct QueueNode* front = rear->next;
    if (front == rear) {
        rear = NULL; // Last player in the queue
    } else {
        rear->next = front->next;
    }

    free(front);
    return rear;
}

// Function to simulate the "Hot Potato" game
struct QueueNode* playHotPotato(struct QueueNode* rear, int passCount) {
    if (isEmpty(rear)) {
        printf("No players in the game.\n");
        exit(EXIT_FAILURE);
    }

    while (rear->next != rear) {
        for (int i = 1; i < passCount; i++) {
            rear = rear->next; // Pass the potato
        }
        struct QueueNode* eliminated = rear->next;
        printf("%s has been eliminated.\n", eliminated->name);

        rear->next = eliminated->next; // Remove the eliminated player
        free(eliminated);
    }

    return rear; // Return the final player
}

int main() {
    struct QueueNode* rear = createQueue();
    int numPlayers, passCount;
    char playerName[50];

    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    getchar(); // Consume the newline character

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(playerName, sizeof(playerName), stdin);
        playerName[strcspn(playerName, "\n")] = '\0'; // Remove the newline character
        rear = enqueuePlayer(rear, playerName);
    }

    printf("Enter the pass count: ");
    scanf("%d", &passCount);

    struct QueueNode* winner = playHotPotato(rear, passCount);

    printf("The winner is %s!\n", winner->name);

    return 0;
}
