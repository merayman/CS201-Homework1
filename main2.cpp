#include <iostream>
#include <stdio.h>
#include "Library.h"
using namespace std;


int main() {

    Library l;

    l.addBook("book1", "house1", 2017);
    l.addBook("book2", "house2", 2016);
    l.addBook("book3", "house3", 2013);

    l.removeBook("book3");
    l.displayAllBooks();

    printf("\n End of add remove book... \n");

    l.addCoauthor("book1", "author1");
    l.addCoauthor("book1", "author1");
    l.addCoauthor("book2", "author2");
    l.addCoauthor("book1", "author2");

    printf("\n End of add Add CoAuthors... \n");

    l.displayBook("book1");
    printf("\n End of display book... \n");
    l.displayAuthor("author2");
    printf("\n End of display author... \n");

    l.removeCoauthor("book1", "author2");
    printf("\n End of remove Coauthor... \n");

    l.displayBook("book1");
    printf("\n End of display book... \n");

    l.removeCoauthor("book2", "author3");
    printf("\n End of remove Coauthor... \n");

    l.removeBook("book2");
    printf("\n End of remove book... \n");

    l.displayAllBooks();
    printf("\n End of display all books... \n");

    return 0;

}
