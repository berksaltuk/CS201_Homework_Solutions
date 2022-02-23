#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H

#include <cstring>
#include <iostream>

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Simple Student Interface
 */

using namespace std;

class Student
{
    public:
        Student();

        string getName();
        int getId();
        void setId(int id);
        void setName(string name);

    private:
        string name;
        int id;
};

#endif // SIMPLESTUDENT_H
