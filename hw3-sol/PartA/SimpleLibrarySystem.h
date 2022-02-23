#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H

#include <cstring>
#include <iostream>
#include "SimpleStudent.h"

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Simple Library System Interface
 */

using namespace std;

class LibrarySystem {
    public:
    LibrarySystem();
    ~LibrarySystem();

    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void showStudent(const int studentId) const;

    private:

    struct StudentNode{
        Student s;
        StudentNode *next;
    };

    int numOfStudents;
    StudentNode *head;
};

#endif // SIMPLELIBRARYSYSTEM_H
