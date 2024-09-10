#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

struct Song { // creating the song structure 
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    struct Song* next;
};

void addSong(struct Song** head, char title[], char artist[]); // function prototyepe for add song
void deleteSong(struct Song** head, char title[]); // function prototyepe for delete sonf
void displayPlaylist(struct Song* head); // function prototyepe for display playlist
void playPlaylist(struct Song* head); // function prototyepe for play playlist
int searchSong(struct Song* head, char title[]); // function prototyepe for search song

int main() {
    struct Song* head = NULL; // inizialing the head of song
    int choice; 
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];

    do {
        printf("\nMenu:\n");
        printf("1. Add a song to the playlist\n");
        printf("2. Delete a song from the playlist\n");
        printf("3. Display the playlist\n");
        printf("4. Play the playlist\n");
        printf("5. Search for a song\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the song title: ");
                getchar(); // Clear the newline character from the input buffer
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline character
                printf("Enter the artist name: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = '\0'; // Remove the newline character
                addSong(&head, title, artist);
                break;

            case 2:
                printf("Enter the song title to delete: ");
                getchar(); // Clear the newline character from the input buffer
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline character
                deleteSong(&head, title);
                break;

            case 3:
                displayPlaylist(head);
                break;

            case 4:
                playPlaylist(head);
                break;

            case 5:
                printf("Enter the song title to search for: ");
                getchar(); // Clear the newline character from the input buffer
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline character
                int index = searchSong(head, title);
                if (index != -1) {
                    printf("Song found at position %d in the playlist.\n", index + 1);
                } else {
                    printf("Song not found in the playlist.\n");
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
    struct Song* current = head;
    while (current != NULL) {
        struct Song* nextSong = current->next;
        free(current);
        current = nextSong;
    }

    return 0;
}

void addSong(struct Song** head, char title[], char artist[]) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    if (newSong == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strncpy(newSong->title, title, MAX_TITLE_LENGTH - 1);
    newSong->title[MAX_TITLE_LENGTH - 1] = '\0'; // Ensure null-terminated string

    strncpy(newSong->artist, artist, MAX_ARTIST_LENGTH - 1);
    newSong->artist[MAX_ARTIST_LENGTH - 1] = '\0'; // Ensure null-terminated string

    newSong->next = *head;
    *head = newSong;

    printf("Song added to the playlist.\n");
}

void deleteSong(struct Song** head, char title[]) {
    struct Song* current = *head;
    struct Song* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Song deleted from the playlist.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Song not found in the playlist.\n");
}

void displayPlaylist(struct Song* head) {
    if (head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }

    struct Song* current = head;
    int index = 1;

    printf("Playlist:\n");
    while (current != NULL) {
        printf("%d. Title: %s | Artist: %s\n", index, current->title, current->artist);
        current = current->next;
        index++;
    }
}

void playPlaylist(struct Song* head) {
    if (head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }

    struct Song* current = head;
    printf("Playing playlist:\n");

    while (current != NULL) {
        printf("Title: %s | Artist: %s\n", current->title, current->artist);
        current = current->next;
    }
}

int searchSong(struct Song* head, char title[]) {
    struct Song* current = head;
    int index = 0;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}
