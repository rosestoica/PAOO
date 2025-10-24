#include "Book.hpp"

Book::Book(const char* t, int p) : pages(p) {
    std::cout << "[Constructor] Creating book: " << t << std::endl;
    title = new char[strlen(t) + 1];
    strcpy(title, t);
}

Book::Book(const Book& other) : pages(other.pages) {
    std::cout << "[Copy Constructor] Copying book: " << other.title << std::endl;
    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);
}

Book::Book(Book&& other) noexcept : title(other.title), pages(other.pages) {
    std::cout << "[Move Constructor] Moving book: " << other.title << std::endl;
    other.title = nullptr;
}

Book::~Book() {
    std::cout << "[Destructor] Deleting book: " 
              << (title ? title : "nullptr") << std::endl;
    delete[] title;
    //delete on null is ok
    //delete *2 of same memory -> undefined behaviour
}

void Book::print() const {
    std::cout << "Book: " << title << " (" << pages << " pages)" << std::endl;
}

Book& Book::operator=(const Book& other) {
    std::cout << "[Copy Assignment] " << other.title << std::endl;

    if (this != &other) {               
        delete[] title;                 
        pages = other.pages;
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
    }
    return *this;
}

Book& Book::operator=(Book&& other) noexcept {
    std::cout << "[Move Assignment] : " << other.title << std::endl;

    if (this != &other) {
        delete[] title;                 
        title = other.title;            
        pages = other.pages;
        other.title = nullptr;          
    }
    return *this;
}
