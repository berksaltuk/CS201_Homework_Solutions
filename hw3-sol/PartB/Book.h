#ifndef BOOK_H
#define BOOK_H

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Book Interface
 */


#include <iostream>
using namespace std;

class Book
{
    public:
        Book();
        int getId();
        int getYearPublished();
        string getName();
        void setAllStuff(int id, string name, int yearPublished);
        void setCheckedOut(bool checkOut);
        bool getCheckedOut();

    private:
        int id;
        int yearPublished;
        string name;
        bool isCheckedOut;

};

#endif // BOOK_H
