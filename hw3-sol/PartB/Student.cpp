#include "Student.h"

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Student Class
 */


Student::Student()
{
    head = NULL;
    numOfBooks = 0;
    id = 0;
    name = "";
}

Student::~Student()
{
    BookNode* current = head;
    while( current != NULL ) {
        BookNode* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

void Student::setAll(string name, int id)
{
    this->id = id;
    this->name = name;
}

int Student::getId()
{
    return id;
}

int Student::getNumOfBooks()
{
    return numOfBooks;
}

string Student::getName()
{
    return name;
}

bool Student::addBook(const int bookId, const string bookName, const int bookYear)
{
    if( !bookExist(bookId))
    {
        if( head == NULL )
        {

            head = new BookNode;
            head->b.setAllStuff(bookId, bookName, bookYear);
            head->next = NULL;
            numOfBooks++;

            cout << "Book " << bookId << " has been added." << endl;
        }
        else
        {
                BookNode *bNode = new BookNode;
                bNode->b.setAllStuff(bookId, bookName, bookYear);
                bNode->next = head;
                head = bNode;
                numOfBooks++;

        }
        return true;
    }
    else
    {
        cout << "This student already checked out this book." << endl;
        return false;
    }

}

bool Student::deleteBook(const int bookId)
{
    if( !bookExist(bookId))
    {
        cout << "This student have not checked out the book with ID " << bookId << "." << endl;
        return false;
    }
    else
    {
    if(head != NULL){

        BookNode *temp = head;
        if( head->b.getId() == bookId)
        {
            if( numOfBooks == 1)
            {

                head = NULL;

                temp->b.setAllStuff(0,"",0);
                delete temp;
                temp = NULL;

            }
            else
            {
                head = head->next;
                temp->b.setAllStuff(0,"",0);
                delete temp;
                temp = NULL;
            }

            numOfBooks--;
            return true;
        }
        else
        {
            BookNode *cur = head;
            while( cur-> next != NULL)
            {
                if(cur->next->b.getId()== bookId)
                {

                    BookNode *temp = cur->next; //holding the node which I will delete to not cause a memory leak

                        if( cur->next->next != NULL)
                        {
                            cur->next = cur->next->next;
                        }
                        else
                        {
                            cur->next = NULL;
                        }

                    numOfBooks--;

                    temp->b.setAllStuff(0,"",0);
                    delete temp;
                    temp = NULL;

                    break;
                }
                cur = cur -> next;
            }

        }

        return true;
    }
    return false;

    }
}

bool Student::bookExist(const int id)
{
    if( head == NULL)
    {
        return false;
    }
    else
    {
        BookNode *current = head;

        while( current != NULL)
        {
            if( current->b.getId() == id )
            {
                current = NULL;
                return true;
            }
            current = current -> next;
        }

        current = NULL;
        return false;
    }
}

Book Student::getBook(const int bookId)
{
    BookNode *cur = head;
    BookNode *hold = NULL;

    while( cur != NULL)
    {
        if( cur->b.getId() == bookId)
        {
            hold = cur;
        }
        cur = cur->next;
    }

    return hold->b;
}

void Student::setBookCheckedOut(const int bookId)
{
    BookNode *cur = head;


    while( cur != NULL)
    {
        if( cur->b.getId() == bookId)
        {
            cur->b.setCheckedOut(true);
        }
        cur = cur->next;
    }
    cur = NULL;
}

void Student::displayBooks(bool includeCheckedOut)
{
    BookNode *cur = head;

    if( includeCheckedOut)
    {
        while(cur != NULL)
        {
            cout << cur->b.getId() << setw (23)  << setfill  (' ') << cur->b.getName() <<setw (20)  << setfill  (' ')<< cur->b.getYearPublished() <<  setw (35)<<setfill (' ') << "Checked out by student " <<  getId() << endl;
            cur = cur->next;
        }
    }
    else
    {
        cout << "Book ID" <<setw (20)  << setfill  (' ') << "Book Name"<<setw (20)  << setfill  (' ')<< "Year"<< endl;
        while(cur != NULL)
        {
            cout << cur->b.getId() << setw (23)  << setfill  (' ') << cur->b.getName() <<setw (20)  << setfill  (' ')<< cur->b.getYearPublished() << endl;
            cur = cur->next;
        }
    }

    cur = NULL;
}

Student::BookNode* Student::returnHead()
{
    return head;
}

