#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

struct Student {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

void addStudent(char name[], int rollNumber, float marks); // for adding student
void deleteStudent(int rollNumber); // delet student
void displayStudents();// display all student
int searchStudent(int rollNumber);// search student

int main() {
    int choice, rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;

    do {
        printf("\nMenu:\n");
        printf("1. Add a student record\n");
        printf("2. Delete a student record\n");
        printf("3. Display all student records\n");
        printf("4. Search for a student record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the student's name: ");
                getchar(); // Clear the newline character from the input buffer
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove the newline character
                printf("Enter the student's roll number: ");
                scanf("%d", &rollNumber);
                printf("Enter the student's marks: ");
                scanf("%f", &marks);
                addStudent(name, rollNumber, marks);
                break;

            case 2:
                printf("Enter the student's roll number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(rollNumber);
                break;

            case 3:
                displayStudents();
                break;

            case 4:
                printf("Enter the student's roll number to search for: ");
                scanf("%d", &rollNumber);
                int index = searchStudent(rollNumber);
                if (index != -1) {
                    printf("Student found at position %d in the list.\n", index + 1);
                } else {
                    printf("Student not found in the list.\n");
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory before exiting the program
    struct Student* current = head;
    while (current != NULL) {
        struct Student* nextStudent = current->next;
        free(current);
        current = nextStudent;
    }

    return 0;
}

void addStudent(char name[], int rollNumber, float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strncpy(newStudent->name, name, MAX_NAME_LENGTH - 1);
    newStudent->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-terminated string
    newStudent->rollNumber = rollNumber;
    newStudent->marks = marks;

    newStudent->next = head;
    head = newStudent;

    printf("Student record added successfully.\n");
}

void deleteStudent(int rollNumber) {
    struct Student* current = head;
    struct Student* prev = NULL;

    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Student record deleted successfully.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Student record not found.\n");
}

void displayStudents() {
    if (head == NULL) {
        printf("The student record list is empty.\n");
        return;
    }

    struct Student* current = head;
    int index = 1;

    printf("Student Record List:\n");
    while (current != NULL) {
        printf("%d. Roll Number: %d | Name: %s | Marks: %.2f\n", index, current->rollNumber, current->name, current->marks);
        current = current->next;
        index++;
    }
}

int searchStudent(int rollNumber) {
    struct Student* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}
