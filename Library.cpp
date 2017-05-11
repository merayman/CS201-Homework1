//
// Created by musab on 3/24/17.
//

#include <iostream>
#include "Library.h"

using namespace std;

    Library::Library(){
        size = 0;
        books = NULL;
    }
    //destructor
    Library::~Library() {
        if(size>0) {
            for (int i = 0; i < size; ++i) {
                delete books[i];
            }
            delete[] books;
        }
        else
            delete books;
    }
    /*
     * adds a book to the library system if that book does not already exist.
     */
    //ez
    void Library::addBook(string bookTitle, string publishingHouse, int publishingYear){
        bool warning = true;
        Book temp1(bookTitle,publishingHouse,publishingYear);
        //controls whether given book already exists or not
        for(int i = 0; i<size&&warning; i++){
            if(this->books[i]->isSame(temp1)) {
                cout << "The book that already exists" << endl;
                warning = false;
            }
        }
        //add that book with given parameters
        if(warning) {
            Book **temp = new Book*[size + 1];
            for (int i = 0; i < size; ++i) {
                temp[i] = new Book(*books[i]);
            }
            temp[size] = new Book(bookTitle, publishingHouse, publishingYear);
            for (int k = 0; k < size; ++k) {
                delete books[k];
            }
            delete [] books;
            books = NULL;
            size++;
            books = new Book*[size];
            for (int j = 0; j < size; ++j) {
                books[j] = new Book(*temp[j]);
            }
            for (int l = 0; l < size; ++l) {
                delete temp[l];
            }
            delete [] temp;
            temp = NULL;
        }

    }
    /*
     * remove book with specific title
     */
    //ez
    void Library::removeBook( string bookTitle){
        int index =0;//index of the book that we will remove
        bool warning = true;
        Book temp(bookTitle,"",0);
        //controls whether given book already exists or not
        for(int i = 0; i < size && warning; i++){
            if(this->books[i]->isSame(temp)) {
                warning= false;
                index = i;
            }
        }
        //if does not exist, give warning
        if(warning){cout<<"WARNING: There is no such that book"<<endl;}
        //else remove that book from library
        else {
            for (int i = index; i < size-1; i++) {
                books[i] = books[i+1];
            }
            delete books[size-1];
            books[size-1]=NULL;
            size--;
        }
    }

    /*
     *  adds a coauthor to coauthors
     */
    //ez
    void Library::addCoauthor( string bookTitle, string bookCoauthor){
        //checks whether that book already exists or not
        bool warning = true;
        int index = 0;

        Book temp(bookTitle,"",0);
        for (int i = 0; i < size && warning; ++i) {
            if ((this->books[i])->isSame(temp)) {
                warning = false;
                index = i;
            }
        }
            if(warning){ cout<<"Warning: There is no such that book in the library: "<<bookTitle<<endl; }
            else{
                //checks whether that coauthor already exist in the list
                bool authorWarning = true;
                for (int j = 0; j < books[index]->coauthorSize && authorWarning; ++j) {
                    if (bookCoauthor==books[index]->coauthors[j] ){
                        authorWarning = false;
                        cout<<"Warning! The coauthor already exist in coauthors list: "<< bookCoauthor<<endl;
                    }
                }
                if(authorWarning){
                    string* temp = new string[(books[index]->coauthorSize)+1];
                    for (int k = 0; k < books[index]->coauthorSize; ++k) {
                        temp[k] = (books[index])->coauthors[k];
                    }
                    temp[books[index]->coauthorSize] = bookCoauthor;
                    delete [] books[index]->coauthors;
                    books[index]->coauthors = NULL;
                    books[index]->coauthors = new string[books[index]->coauthorSize+1];
                    for (int k = 0; k < books[index]->coauthorSize+1; ++k) {
                        books[index]->coauthors[k] = temp[k];
                    }
                    delete [] temp;
                    books[index]->coauthorSize++;
                }

            }
        }

    void Library::removeCoauthor( string bookTitle, string coauthorName){
        bool bookWarning = true;
        bool authorWarning = true;
        Book temp(bookTitle,"",0);
        for (int i = 0; i < size && bookWarning; ++i) {
            if(this->books[i]->isSame(temp)){
                int bookIndex = i;
                bookWarning = false;
                for (int j = 0; j < books[i]->coauthorSize && authorWarning; ++j) {
                    if( coauthorName == books[i]->coauthors[j] ){
                        int authorIndex = j;
                        authorWarning = false;
                        for (int k = authorIndex; k < books[i]->coauthorSize-1; ++k) {
                            books[i]->coauthors[k] = books[i]->coauthors[k+1];
                        }
                    }
                }
                books[bookIndex]->coauthorSize--;
                if(authorWarning)
                    cout<<"There is no such that coauthor in the list: "<<coauthorName <<endl;
            }
        }
        if(bookWarning)
            cout<<"There is no such that book: "<<bookTitle <<endl;
    }
    //ez
    void Library::displayAllBooks() {
        if(size==0)
            cout<<"--EMPTY--";
        else if(size==1)
            cout<<books[0]->title<<", "<<books[0]->publishYear<<"(for the 1st book)"<<endl;
        else if(size==2) {
            cout << books[0]->title << ", " << books[0]->publishYear << "(for the 1st book)" << endl;
            cout<<books[1]->title<<", "<<books[1]->publishYear<<"(for the 2nd book)"<<endl;
        }
        else {
            cout << books[0]->title << ", " << books[0]->publishYear << "(for the 1st book)" << endl;
            cout<<books[1]->title<<", "<<books[1]->publishYear<<"(for the 2nd book)"<<endl;
            for (int i = 2; i < size; ++i) {
                cout << books[i]->title << ", " << books[i]->publishYear << " (for the " << i + 1 << "th book)" << endl;
            }
        }
    }
    //ez
    void Library::displayBook(string bookTitle){
        int index = 0;
        bool warning = true;
        Book temp(bookTitle,"",0);
        for (int i = 0; i < size && warning; ++i) {
            if(this->books[i]->isSame(temp)){
                index = i;
                warning = false;
            }
        }
        if(warning)
            cout<<"--EMPTY--"<<endl;
        else{
            cout<<bookTitle<<", "<<books[index]->publisher<<", "<<books[index]->publishYear<<endl;
            for (int i = 0; i < books[index]->coauthorSize; ++i) {
                cout<<books[index]->coauthors[i]<<"( for the coauthor "<< i+1 <<" )"<<endl;
            }
        }
    }
    //ez
    void Library::displayAuthor(string authorName){
        if(size <= 0)
            cout<<"--EMPTY--"<<endl;
        else
        {
            int tempSize = 0;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < books[i]->coauthorSize; ++j) {
                    if (books[i]->coauthors[j] == authorName){
                        tempSize++;
                    }
                }
            }
            if(tempSize == 0)
                cout<<"--EMPTY--"<<endl;
            else {
                cout<<authorName<<endl;
                int tempIndex = 0;

                for (int i = 0; i < size; ++i) {
                    for (int j = 0; j < books[i]->coauthorSize; ++j) {
                        if (books[i]->coauthors[j] == authorName) {
                            cout<<books[i]->title<<", ";
                            cout<<books[i]->publishYear;
                            cout<<"(for the book "<<++tempIndex<<" )"<<endl;
                        }
                    }
                }
            }
        }
    }