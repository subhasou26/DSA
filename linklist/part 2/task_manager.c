#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 100

struct Task {
    int taskId;
    char description[MAX_DESCRIPTION_LENGTH];
    int priority;
    struct Task* next;
};

void addTask(struct Task** head, int taskId, char description[], int priority);
void deleteTask(struct Task** head, int taskId);
void displayTasks(struct Task* head);
void prioritizeTasks(struct Task** head);
int searchTask(struct Task* head, int taskId);

int main() {
    struct Task* head = NULL;
    int choice, taskId, priority;
    char description[MAX_DESCRIPTION_LENGTH];

    do {
        printf("\nMenu:\n");
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Display all tasks\n");
        printf("4. Prioritize tasks\n");
        printf("5. Search for a task\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the task ID: ");
                scanf("%d", &taskId);
                printf("Enter the task description: ");
                getchar(); // Clear the newline character from the input buffer
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove the newline character
                printf("Enter the task priority: ");
                scanf("%d", &priority);
                addTask(&head, taskId, description, priority);
                break;

            case 2:
                printf("Enter the task ID to delete: ");
                scanf("%d", &taskId);
                deleteTask(&head, taskId);
                break;

            case 3:
                displayTasks(head);
                break;

            case 4:
                prioritizeTasks(&head);
                printf("Tasks prioritized successfully.\n");
                break;

            case 5:
                printf("Enter the task ID to search for: ");
                scanf("%d", &taskId);
                int index = searchTask(head, taskId);
                if (index != -1) {
                    printf("Task found at position %d in the list.\n", index + 1);
                } else {
                    printf("Task not found in the list.\n");
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free allocated memory before exiting the program
    struct Task* current = head;
    while (current != NULL) {
        struct Task* nextTask = current->next;
        free(current);
        current = nextTask;
    }

    return 0;
}

void addTask(struct Task** head, int taskId, char description[], int priority) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    if (newTask == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newTask->taskId = taskId;
    strncpy(newTask->description, description, MAX_DESCRIPTION_LENGTH - 1);
    newTask->description[MAX_DESCRIPTION_LENGTH - 1] = '\0'; // Ensure null-terminated string
    newTask->priority = priority;

    newTask->next = *head;
    *head = newTask;

    printf("Task added successfully.\n");
}

void deleteTask(struct Task** head, int taskId) { // for delete task
    struct Task* current = *head;
    struct Task* prev = NULL;

    while (current != NULL) {
        if (current->taskId == taskId) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Task deleted successfully.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Task not found.\n");
}

void displayTasks(struct Task* head) {
    if (head == NULL) {
        printf("The task list is empty.\n");
        return;
    }

    struct Task* current = head;
    int index = 1;

    printf("Task List:\n");
    while (current != NULL) {
        printf("%d. ID: %d | Description: %s | Priority: %d\n", index, current->taskId, current->description, current->priority);
        current = current->next;
        index++;
    }
}

void prioritizeTasks(struct Task** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Nothing to prioritize
    }

    struct Task* prev = *head;
    struct Task* current = (*head)->next;

    while (current != NULL) {
        if (current->priority > prev->priority) {
            // Move the current task to the beginning of the list
            prev->next = current->next;
            current->next = *head;
            *head = current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int searchTask(struct Task* head, int taskId) {
    struct Task* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->taskId == taskId) {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}
