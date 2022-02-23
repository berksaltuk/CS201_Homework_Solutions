#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <iomanip>
#include <iostream>

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Library System Interface
 */


using namespace std;

#include "Student.h"

class LibrarySystem {
    public:
        LibrarySystem();

        ~LibrarySystem();

        void addBook(const int bookId, const string bookName, const int bookYear);
        void deleteBook(const int bookId);
        void addStudent(const int studentId, const string studentName);
        void deleteStudent(const int studentId);
        void checkoutBook(const int bookId, const int studentId);
        void returnBook(const int bookId);
        void showAllBooks() const;
        void showBook(const int bookId) const;
        void showStudent(const int studentId) const;

        //helper methods
        void deleteCheckedOut(const int bookId);
        void addBookBack(const int bookId, const string bookName, const int bookYear);

    private:


        struct StudentNode
        {
            Student s;
            StudentNode *next;
        };


        Student::BookNode *bHead;
        StudentNode *sHead;


        int numOfStudents;
        int numOfBooksInLibrary;
        int numOfBooksCheckedOut;

};

#endif // LIBRARYSYSTEM_H
