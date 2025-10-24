#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>

class Book {
private:
    char* title;
    int pages;

public:
    Book(const char* t, int p);
    Book(const Book& other);
    Book(Book&& other) noexcept;
    Book& operator=(const Book& other);
    Book& operator=(Book&& other) noexcept;
    ~Book();

    void print() const;
};

#endif
