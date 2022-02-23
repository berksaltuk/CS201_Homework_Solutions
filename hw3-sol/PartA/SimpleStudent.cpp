#include "SimpleStudent.h"

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Simple Student Class
 */

Student::Student()
{
    this->name = "";
    this->id = 0;
}

string Student::getName()
{
    return name;
}

int Student::getId()
{
    return id;
}

void Student::setId( int id)
{
    this->id = id;
}

void Student::setName( string name)
{
    this->name = name;
}
