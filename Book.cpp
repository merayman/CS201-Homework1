//
// Created by musab on 3/24/17.
//
#include <iostream>
#include <string.h>
#include "Book.h"
using namespace std;

Book::Book (string bTitle, string bPublisher, int bPublishYear) {
    title=bTitle;
    publisher = bPublisher;
    publishYear=bPublishYear;
    coauthorSize=0;
    coauthors = new string[coauthorSize];
}
Book::~Book() {
    delete [] coauthors;
}
Book::Book(){
    title;
    publisher;
    coauthorSize=0;
    coauthors = new string[coauthorSize];
    publishYear=0;
}

//copy constructor
Book::Book(const Book &otherBook)
        : coauthorSize(otherBook.coauthorSize){
    title=otherBook.title;
    publisher=otherBook.publisher;
    publishYear = otherBook.publishYear;
    if(coauthorSize>0) {
        coauthors = new string[coauthorSize];
        for (int i = 0; i < coauthorSize; ++i) {
            coauthors[i] = otherBook.coauthors[i];
        }
    }
    else
        coauthors = NULL;

}
//overload " = " assignment
void Book::operator=(const Book &otherBook) {
    if( &otherBook != this){
        title=otherBook.title;
        publisher=otherBook.publisher;
        if(coauthorSize!= otherBook.coauthorSize) {
            if(coauthorSize>0)
                delete [] coauthors;
            coauthorSize = otherBook.coauthorSize;
            if(coauthorSize>0)
                coauthors = new string[coauthorSize];
            else
                coauthors=NULL;
        }
        for (int i = 0; i < coauthorSize; ++i) {
            coauthors[i] = otherBook.coauthors[i];
        }
        publishYear = otherBook.publishYear;
    }
}
//function that check whether books are same or not
//if they are same return true
bool Book::isSame(Book b) {
    if(title.size()!=b.title.size())
        return false;
    int size = b.title.size();
    bool result = true;
    for (int i = 0; i < size & result; ++i) {
        result = tolower(title[i]) == tolower((b.title)[i]);
    }
    return result;
}