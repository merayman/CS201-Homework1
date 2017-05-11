//
// Created by musab on 3/24/17.
//

#ifndef HW1_LIBRARY_H
#define HW1_LIBRARY_H

#endif HW1_LIBRARY_H

#include <iostream>
#include <string.h>
#include "Book.h"
using namespace std;

class Library{
public:
    Library();
    ~Library();

    void addBook(string bookTitle, string publishingHouse, int publishingYear);//ez
    void removeBook( string bookTitle);

    void addCoauthor( string bookTitle, string bookAuthor);
    void removeCoauthor( string bookTitle, string coauthorName);

    void displayAllBooks();
    void displayBook(string bookTitle);
    void displayAuthor(string authorName);
    Book **books;
    int size;
};
