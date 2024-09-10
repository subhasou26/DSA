#include <iostream>
#include <string>
using namespace std;


struct Book {
    string title;
    string author;
};

int main() {
    int num_books;

    
    cout << "Enter the number of books: ";
    cin >> num_books;

    
    Book* books = new Book[num_books];

    for (int i = 0; i < num_books; ++i) {
        cout << "\nEnter details for Book " << i + 1 << ":" << endl;
        cout << "Title: ";
        cin>>books[i].title;
        cout<<"\n";
        cout << "Author: ";
        cin>>books[i].author;
        cout<<"\n";
    }

    
    cout << "\nBook Details:" << endl;
    for (int i = 0; i < num_books; ++i) {
        cout << "Book " << i + 1 << ":" << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << endl;
    }
    delete[] books;

    return 0;
}
