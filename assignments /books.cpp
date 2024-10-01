#include <iostream>
#include <vector>
#include <string>

class Book {
    std::string title, author, isbn;
    bool is_borrowed;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i), is_borrowed(false) {}

    bool borrow() {
        if (is_borrowed) return false;
        is_borrowed = true;
        return true;
    }

    bool returnBook() {
        if (!is_borrowed) return false;
        is_borrowed = false;
        return true;
    }

    bool isAvailable() const {
        return !is_borrowed;
    }

    std::string getTitle() const {
        return title;
    }

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << '\n';
    }
};

class Library {
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void borrowBook(int index) {
        if (index >= 0 && index < books.size()) {
            if (books[index].borrow()) {
                std::cout << "Book '" << books[index].getTitle() << "' borrowed successfully.\n";
            } else {
                std::cout << "Error: Book '" << books[index].getTitle() << "' is already borrowed.\n";
            }
        } else {
            std::cout << "Invalid book selection.\n";
        }
    }

    void returnBook(int index) {
        if (index >= 0 && index < books.size()) {
            if (books[index].returnBook()) {
                std::cout << "Book '" << books[index].getTitle() << "' returned successfully.\n";
            } else {
                std::cout << "Error: Book '" << books[index].getTitle() << "' was not borrowed.\n";
            }
        } else {
            std::cout << "Invalid book selection.\n";
        }
    }

    void displayAllBooks() const {
        std::cout << "Books:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            std::cout << i + 1 << ". " << books[i].getTitle();
            if (!books[i].isAvailable()) {
                std::cout << " (borrowed)";
            }
            std::cout << '\n';
        }
    }

    void displayAvailableBooks() const {
        std::cout << "Available books:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isAvailable()) {
                std::cout << i + 1 << ". " << books[i].getTitle() << '\n';
            }
        }
    }

    int getAvailableBooksCount() const {
        int count = 0;
        for (const auto& book : books) {
            if (book.isAvailable()) count++;
        }
        return count;
    }
};

void displayMenu() {
    std::cout << "Library System\n";
    std::cout << "1. Borrow a book\n";
    std::cout << "2. Return a book\n";
    std::cout << "3. Exit\n";
}

int main() {
    Library lib;
    lib.addBook(Book("1984", "George Orwell", "123456"));
    lib.addBook(Book("To Kill a Mockingbird", "Harper Lee", "654321"));
    lib.addBook(Book("Jack Reacher", "Hermosa", "9874"));
    lib.addBook(Book("Maya", "Zues", "753932"));
    lib.addBook(Book("Mr. D", "Heries Paul", "73495"));
    lib.addBook(Book("Blooow", "Henry", "5767"));

    while (true) {
        displayMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                if (lib.getAvailableBooksCount() > 0) {
                    std::cout << "Select a book to borrow:\n";
                    lib.displayAvailableBooks();
                    int bookChoice;
                    std::cout << "Enter the book number: ";
                    std::cin >> bookChoice;
                    lib.borrowBook(bookChoice - 1);  // Adjusting for 0-based index
                } else {
                    std::cout << "No books available to borrow.\n";
                }
                break;
            }
            case 2: {
                std::cout << "Select a book to return:\n";
                lib.displayAllBooks();
                int bookChoice;
                std::cout << "Enter the book number: ";
                std::cin >> bookChoice;
                lib.returnBook(bookChoice - 1);  // Adjusting for 0-based index
                break;
            }
            case 3:
                std::cout << "Exiting the system.\n";
                return 0;
            default:
                std::cout << "Invalid option, try again.\n";
                break;
        }
    }

    return 0;
}
