#ifndef STUDENT_H
#define STUDENT_H

#include "Book.h"
#include <iomanip>

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Student Interface
 */

class Student
{
    public:
        Student();
        ~Student();

        string getName();

        int getId();
        int getNumOfBooks();

        bool bookExist(const int id);

        void setAll(string name, int id);
        bool addBook(const int bookId, const string bookName, const int bookYear);
        bool deleteBook(const int bookId);

        Book getBook(const int bookId);
        void setBookCheckedOut(const int bookId);
        void displayBooks(bool includeCheckedOut);

        struct BookNode
        {
            Book b;
            BookNode *next;
        };

        BookNode* returnHead();
    private:
        int id;
        string name;
        int numOfBooks;



        BookNode *head;


};

#endif // STUDENT_H
