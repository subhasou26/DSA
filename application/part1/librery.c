#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Book structure
struct Book {
    char title[100];
    char author[100];
    int publicationYear;
    struct Book* nextBook; // Pointer to the next book in the genre
};

// Define the Genre structure
struct Genre {
    char genreName[50];
    struct Book* books; // Pointer to the list of books in this genre
    struct Genre* nextGenre; // Pointer to the next genre in the catalog
};

// Function to create a new book node
struct Book* createBookNode(const char* title, const char* author, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Memory allocation failed for a new book node.\n");
        exit(1);
    }
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->publicationYear = year;
    newBook->nextBook = NULL;
    return newBook;
}

// Function to insert a new book at the front of the book linked list under a genre
void insertBookAtFront(struct Genre* genre, struct Book* newBook) {
    if (genre == NULL || newBook == NULL) {
        printf("Invalid input for inserting a book.\n");
        return;
    }
    newBook->nextBook = genre->books;
    genre->books = newBook;
}

// Function to delete the first book from the book linked list under a genre
void deleteBookFromFront(struct Genre* genre) {
    if (genre == NULL || genre->books == NULL) {
        printf("The book list is empty or invalid genre.\n");
        return;
    }
    struct Book* temp = genre->books;
    genre->books = genre->books->nextBook;
    free(temp);
}

// Function to display the details of all books under a specific genre
void displayBooks(struct Genre* genre) {
    if (genre == NULL || genre->books == NULL) {
        printf("No books available in this genre.\n");
        return;
    }
    printf("Books in the '%s' genre:\n", genre->genreName);
    struct Book* currentBook = genre->books;
    while (currentBook != NULL) {
        printf("Title: %s\n", currentBook->title);
        printf("Author: %s\n", currentBook->author);
        printf("Publication Year: %d\n", currentBook->publicationYear);
        printf("\n");
        currentBook = currentBook->nextBook;
    }
}

// Function to create a new genre node
struct Genre* createGenreNode(const char* genreName) {
    struct Genre* newGenre = (struct Genre*)malloc(sizeof(struct Genre));
    if (newGenre == NULL) {
        printf("Memory allocation failed for a new genre node.\n");
        exit(1);
    }
    strcpy(newGenre->genreName, genreName);
    newGenre->books = NULL; // Initialize the book list as empty
    newGenre->nextGenre = NULL;
    return newGenre;
}

// Function to insert a new genre at the front of the genre linked list
void insertGenreAtFront(struct Genre** catalog, struct Genre* newGenre) {
    if (newGenre == NULL) {
        printf("Invalid input for inserting a genre.\n");
        return;
    }
    newGenre->nextGenre = *catalog;
    *catalog = newGenre;
}

// Function to delete the first genre from the genre linked list
void deleteGenreFromFront(struct Genre** catalog) {
    if (*catalog == NULL) {
        printf("The genre catalog is empty.\n");
        return;
    }
    struct Genre* temp = *catalog;
    *catalog = (*catalog)->nextGenre;
    free(temp);
}

// Function to display the names of all genres in the library catalog
void displayGenres(struct Genre* catalog) {
    if (catalog == NULL) {
        printf("The genre catalog is empty.\n");
        return;
    }
    printf("Library Catalog Genres:\n");
    while (catalog != NULL) {
        printf("%s\n", catalog->genreName);
        catalog = catalog->nextGenre;
    }
}


int main() {
    struct Genre* catalog = NULL; // Initialize an empty catalog

    int choice;
    char genreName[50], title[100], author[100];
    int year;

    while (1) {
        printf("\nLibrary Catalog Management System\n");
        printf("1. Add new genre\n");
        printf("2. Add new book under a genre\n");
        printf("3. Delete a genre (and all books under it)\n");
        printf("4. Delete a book from a genre\n");
        printf("5. Display all genres and books\n");
        printf("6. Search for a book by title\n");
        printf("7. Update book details by title\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the genre: ");
                scanf("%s", genreName);
                struct Genre* newGenre = createGenreNode(genreName);
                insertGenreAtFront(&catalog, newGenre);
                printf("Genre added to the catalog.\n");
                break;
            case 2:
                printf("Enter the name of the genre: ");
                scanf("%s", genreName);
                
                struct Genre* genreToAddBook = catalog;
                while (genreToAddBook != NULL && strcmp(genreToAddBook->genreName, genreName) != 0) {
                    genreToAddBook = genreToAddBook->nextGenre;
                }
                if (genreToAddBook != NULL) {
                printf("Enter the title of the book: ");
                scanf("%s", title);
                printf("Enter the author of the book: ");
                scanf("%s", author);
                printf("Enter the publication year of the book: ");
                scanf("%d", &year);
                    struct Book* newBook = createBookNode(title, author, year);
                    insertBookAtFront(genreToAddBook, newBook);
                    printf("Book added to the genre.\n");
                } else {
                    printf("Genre not found in the catalog.\n");
                }
                break;
            case 3:
                printf("Enter the name of the genre to delete: ");
                scanf("%s", genreName);
                struct Genre* prevGenre = NULL;
                struct Genre* genreToDelete = catalog;
                while (genreToDelete != NULL && strcmp(genreToDelete->genreName, genreName) != 0) {
                    prevGenre = genreToDelete;
                    genreToDelete = genreToDelete->nextGenre;
                }
                if (genreToDelete != NULL) {
                    if (prevGenre != NULL) {
                        prevGenre->nextGenre = genreToDelete->nextGenre;
                    } else {
                        catalog = genreToDelete->nextGenre;
                    }
                    free(genreToDelete);
                    printf("Genre and all books under it deleted.\n");
                } else {
                    printf("Genre not found in the catalog.\n");
                }
                break;
            case 4:
                printf("Enter the name of the genre: ");
                scanf("%s", genreName);
                struct Genre* genreToDeleteBookFrom = catalog;
                while (genreToDeleteBookFrom != NULL && strcmp(genreToDeleteBookFrom->genreName, genreName) != 0) {
                    genreToDeleteBookFrom = genreToDeleteBookFrom->nextGenre;
                }
                if (genreToDeleteBookFrom != NULL) {
                    deleteBookFromFront(genreToDeleteBookFrom);
                    printf("First book in the genre deleted.\n");
                } else {
                    printf("Genre not found in the catalog.\n");
                }
                break;
            case 5:
                displayGenres(catalog);
                struct Genre* currentGenre = catalog;
                while (currentGenre != NULL) {
                    displayBooks(currentGenre);
                    currentGenre = currentGenre->nextGenre;
                }
                break;
            case 6:
                printf("Enter the title of the book to search: ");
                scanf("%s", title);
                struct Genre* genreToSearch = catalog;
                while (genreToSearch != NULL) {
                    struct Book* bookToSearch = genreToSearch->books;
                    while (bookToSearch != NULL) {
                        if (strcmp(bookToSearch->title, title) == 0) {
                            printf("Book found in genre '%s':\n", genreToSearch->genreName);
                            printf("Title: %s\n", bookToSearch->title);
                            printf("Author: %s\n", bookToSearch->author);
                            printf("Publication Year: %d\n", bookToSearch->publicationYear);
                            break;
                        }
                        bookToSearch = bookToSearch->nextBook;
                    }
                    genreToSearch = genreToSearch->nextGenre;
                }
                if (genreToSearch == NULL) {
                    printf("Book not found in the catalog.\n");
                }
                break;
            case 7:
                printf("Enter the title of the book to update: ");
                scanf("%s", title);
                struct Genre* genreToUpdate = catalog;
                while (genreToUpdate != NULL) {
                    struct Book* bookToUpdate = genreToUpdate->books;
                    while (bookToUpdate != NULL) {
                        if (strcmp(bookToUpdate->title, title) == 0) {
                            printf("Enter the new author of the book: ");
                            scanf("%s", author);
                            printf("Enter the new publication year of the book: ");
                            scanf("%d", &year);
                            strcpy(bookToUpdate->author, author);
                            bookToUpdate->publicationYear = year;
                            printf("Book details updated.\n");
                            break;
                        }
                        bookToUpdate = bookToUpdate->nextBook;
                    }
                    genreToUpdate = genreToUpdate->nextGenre;
                }
                if (genreToUpdate == NULL) {
                    printf("Book not found in the catalog.\n");
                }
                break;
            case 8:
                // Free memory and exit
                while (catalog != NULL) {
                    struct Genre* tempGenre = catalog;
                    catalog = catalog->nextGenre;
                    while (tempGenre->books != NULL) {
                        struct Book* tempBook = tempGenre->books;
                        tempGenre->books = tempGenre->books->nextBook;
                        free(tempBook);
                    }
                    free(tempGenre);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
