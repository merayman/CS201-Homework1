//
// Created by musab on 3/24/17.
//

#ifndef HW1_BOOK_H
#define HW1_BOOK_H

#endif HW1_BOOK_H

#include <iostream>
#include <string.h>
using namespace std;

class Book{
public:
    Book(string bTitle, string bPublisher, int bPublishYear);
    Book();

    ~Book();
    //copy constructor:
    Book(const Book &otherBook);

    void operator=(const Book &otherBook);

    string title, publisher;
    string* coauthors;
    int publishYear, coauthorSize;
    //additional method to check whether books are same or not
    bool isSame(Book b);
};