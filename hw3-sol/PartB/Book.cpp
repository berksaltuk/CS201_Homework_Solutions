#include <iostream>

#include "Book.h"

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Book Class
 */


Book::Book()
{
    this->id = 0;
    this->name = "";
    this->yearPublished = 0;
    this->isCheckedOut = false;
}

int Book::getId()
{
    return id;
}

int Book::getYearPublished()
{
    return yearPublished;
}

string Book::getName()
{
    return name;
}

void Book::setAllStuff(int bookId, string name, int yearPublished)
{
    this->id = bookId;
    this->name = name;
    this->yearPublished = yearPublished;
}

void Book::setCheckedOut(bool checkedOut)
{
    isCheckedOut = checkedOut;
}

bool Book::getCheckedOut()
{
    return isCheckedOut;
}

