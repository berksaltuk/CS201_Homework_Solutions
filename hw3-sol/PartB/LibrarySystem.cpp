#include "LibrarySystem.h"

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Library System Class
 */


LibrarySystem::LibrarySystem()
{
    sHead = NULL;
    bHead = NULL;

    numOfStudents = 0;
    numOfBooksInLibrary = 0;

}

LibrarySystem::~LibrarySystem()
{
    StudentNode* current = sHead;
    while( current != NULL ) {
        StudentNode* next = current->next;
        delete current;
        current = next;
    }
    sHead = NULL;

    Student::Student::BookNode* current2 = bHead;
    while( current2 != NULL ) {
        Student::BookNode* next = current2->next;
        delete current2;
        current2 = next;
    }
    bHead = NULL;
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear)
{
   StudentNode *cur = sHead;
    while( cur != NULL)
    {
        if(cur->s.bookExist(bookId))
        {
            cout << "Book " << bookId << " checked out by student " << cur->s.getName() << " and cannot be added to the library." << endl;
            return;
        }
        cur = cur->next;
    }

   delete cur;

    Student::BookNode *bCur = bHead;
    bool exist = false;
    while( bCur != NULL)
    {
        if(bCur->b.getId() == bookId)
        {
            cout << "Book " << bookId << " already exists." << endl;
            exist = true;
            return;
        }
        bCur = bCur->next;
    }

   delete bCur;
if(!exist){
    if( bHead == NULL )
    {

        bHead = new Student::BookNode;
        bHead->b.setAllStuff(bookId, bookName, bookYear);
        bHead->next = NULL;
        numOfBooksInLibrary++;

        cout << "Book " << bookId << " has been added." << endl;
    }
    else
    {
            Student::BookNode *bNode = new Student::BookNode;
            bNode->b.setAllStuff(bookId, bookName, bookYear);
            bNode->next = bHead;
            bHead = bNode;


            numOfBooksInLibrary++;
            cout << "Book " << bookId << " has been added." << endl;
    }
}
}

void LibrarySystem::deleteBook(const int bookId)
{

    bool found = false;

    if(bHead != NULL)
    {
        Student::BookNode *cur = bHead;
        if( cur->b.getId() == bookId)
        {
            found = true;
            Student::BookNode *temp = bHead;
            bHead = bHead->next;

            returnBook(temp->b.getId());

            temp->b.setAllStuff(0,"",0);
            delete temp;
            temp = NULL;

            numOfBooksInLibrary--;
            cout << "Book "<< bookId << " has been deleted" << endl;
        }
        else
        {

            while( cur-> next != NULL)
            {
                if(cur->next->b.getId()== bookId)
                {
                    found = true;

                    Student::BookNode *temp = cur->next; //holding the node which I will delete to not cause a memory leak

                    returnBook(temp->b.getId());

                    if( cur->next->next != NULL)
                    {
                        cur->next = cur->next->next;
                    }
                    else
                    {
                        cur->next = NULL;
                    }

                    cout << "Book "<< bookId << " has been deleted" << endl;
                    numOfBooksInLibrary--;

                    delete temp;
                    temp = NULL;
                    break;
                }
                cur = cur -> next;
            }

        }
        cur = NULL;
    }

    StudentNode *temp = sHead;

    while( temp != NULL)
    {
        if( temp->s.bookExist(bookId) )
        {
            found = true;
            returnBook(bookId);

            Student::BookNode *cur = bHead;
            if( cur->b.getId() == bookId)
            {
                found = true;
                Student::BookNode *temp = bHead;
                bHead = bHead->next;

                returnBook(temp->b.getId());

                temp->b.setAllStuff(0,"",0);
                delete temp;
                temp = NULL;

                numOfBooksInLibrary--;
                cout << "Book "<< bookId << " has been deleted" << endl;
            }
            else
            {

                while( cur-> next != NULL)
                {

                    if(cur->next->b.getId()== bookId)
                    {

                        Student::BookNode *temp = cur->next; //holding the node which I will delete to not cause a memory leak

                        returnBook(temp->b.getId());

                        if( cur->next->next != NULL)
                        {
                            cur->next = cur->next->next;
                        }
                        else
                        {
                            cur->next = NULL;
                        }

                        cout << "Book "<< bookId << " has been deleted" << endl;
                        numOfBooksInLibrary--;

                        delete temp;
                        temp = NULL;

                        break;
                    }
                    cur = cur -> next;
                }

            }
            cur = NULL;

        }
        temp = temp->next;
    }


    if( !found )
    {
        cout << "Book " << bookId << " does not exist." << endl;
    }

}

void LibrarySystem::addStudent(const int studentId, const string studentName)
{
    StudentNode *cur = sHead;
    bool exist = false;

    while(cur != NULL)
    {
        if(cur->s.getId() == studentId)
        {
            cout << "Student " << studentId << " already exists." << endl;
            exist = true;
            break;
        }
        cur = cur->next;
    }
    cur = NULL;
    if(!exist)
    {
        if( sHead == NULL)
        {
            sHead = new StudentNode;
            sHead->s.setAll(studentName, studentId);
            sHead->next = NULL;
            numOfStudents++;

            cout << "Student " << studentName << " : " << studentId << " has been added." << endl;
        }
        else
        {
            StudentNode *temp = new StudentNode;
            temp->s.setAll(studentName, studentId);
            temp->next = sHead;
            sHead = temp;

            temp = NULL;
            numOfStudents++;
            cout << "Student " << studentName << " : " << studentId << " has been added." << endl;
        }
    }
}

void LibrarySystem::deleteStudent(const int studentId)
{
    if(sHead == NULL)
    {
        cout << "No students in the system." << endl;
    }
    else
    {
        StudentNode *cur = sHead;
        if( cur->s.getId() == studentId)
        {
            StudentNode *temp = sHead;

            sHead = sHead->next;

            //TO DO
            Student::BookNode *bCur = temp->s.returnHead();
            while( bCur != NULL)
            {
                returnBook( bCur->b.getId());
                bCur = bCur -> next;
            }

            temp->s.setAll("", 0);
            delete temp;
            temp = NULL;

            numOfStudents--;
            cout << "Student "<< studentId << " has been deleted" << endl;
        }
        else
        {
            bool found = false;

            while( cur-> next != NULL)
            {
                if(cur->next->s.getId()== studentId)
                {
                    found = true;

                    StudentNode *temp = cur->next; //holding the node which I will delete to not cause a memory leak

                    //TO DO

                    Student::BookNode *bCur = temp->s.returnHead();

                    while( bCur != NULL)
                    {
                        returnBook( bCur->b.getId());
                        bCur = bCur -> next;
                    }

                    if( cur->next->next != NULL)
                    {
                        cur->next = cur->next->next;
                    }
                    else
                    {
                        cur->next = NULL;
                    }
                    cout << "Student "<< studentId << " has been deleted" << endl;
                    numOfStudents--;

                    temp->s.setAll("",0);
                    delete temp;
                    temp = NULL;
                    break;
                }
                cur = cur -> next;
            }
            if( !found)
            {
                cout << "Student " << studentId << " does not exist." << endl;
            }
        }
        cur = NULL;
    }
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
    StudentNode *cur1 = sHead;
    StudentNode *curS = sHead;

    Student::BookNode *curB = bHead;
    StudentNode *holdS = NULL;
    Student::BookNode *holdB = NULL;
    bool already = false;
    bool foundStudent = false;
    bool inLibrary = false;

    while (curB != NULL)
    {
        if(curB->b.getId() == bookId)
        {
            inLibrary = true;
            holdB = curB;
        }
        curB = curB->next;
    }
    curB = NULL;

    while( cur1 != NULL)
    {
        if( cur1->s.bookExist(bookId))
        {
            already = true;
            cout << "Book " << bookId << " has been already checked out by another student." << endl;
        }
        cur1 = cur1 -> next;
    }
    cur1 = NULL;

    while( curS != NULL)
    {
        if( curS->s.getId() == studentId)
        {
            holdS = curS;
            foundStudent = true;
        }
        curS = curS->next;
    }
    curS = NULL;
    if( inLibrary && !already && foundStudent)
    {

        holdS->s.addBook(holdB->b.getId(), holdB->b.getName(), holdB->b.getYearPublished());
        holdS->s.setBookCheckedOut(bookId);
        deleteCheckedOut(bookId);
        cout << "Book " << bookId << " has been checked out by student " << studentId <<endl;
    }

    if( !foundStudent)
    {
        cout << "Student " << studentId << " does not exist for checkout." <<endl;
    }
    if( !inLibrary && !already)
    {
        cout << "Book " << bookId << " does not exist for checkout."<< endl;
    }
    holdS = NULL;
    holdB = NULL;
}

void LibrarySystem::returnBook(const int bookId)
{
    Student::BookNode *cur = bHead;
    StudentNode *curS = sHead;

    bool only = false;
     while( cur != NULL)
     {
        if( cur->b.getId() == bookId)
        {
            only = true;

        }
        cur = cur ->next;
    }

    while( curS != NULL)
    {
        if(curS->s.bookExist(bookId))
        {

           Book b = curS->s.getBook(bookId);
           addBookBack(b.getId(), b.getName(), b.getYearPublished());
           curS->s.deleteBook(bookId);

           cout << "Book " << bookId << " has been returned." << endl;
        }
        curS = curS->next;
    }


    if( only )
    {
        cout << "Book " << bookId <<" has not been checked out." << endl;
    }

    curS = NULL;
    cur = NULL;
}

void LibrarySystem::showAllBooks() const
{
    Student::BookNode *cur = bHead;
    cout << "Book ID" <<setw (20)  << setfill  (' ') << "Book Name"<<setw (20)  << setfill  (' ')<< "Year"<<setw (20)  << setfill  (' ') << "Status"<< endl;
    while( cur != NULL)
    {
        cout << cur->b.getId() << setw (23)  << setfill  (' ') << cur->b.getName() <<setw (20)  << setfill  (' ')<< cur->b.getYearPublished() <<  setw (35)<<setfill (' ');

        cout << "Not checked out"<< endl;

        cur = cur->next;

    }

    StudentNode* sCur = sHead;
    while( sCur != NULL)
    {
        sCur->s.displayBooks(true);
        sCur = sCur->next;
    }
    cur = NULL;
}

void LibrarySystem::showBook(const int bookId) const
{
    Student::BookNode *cur = bHead;

    while( cur != NULL)
    {
        if(cur->b.getId() == bookId)
        {
           cout << cur->b.getId() << setw (25)  << setfill  (' ') << cur->b.getName() <<setw (20)  << setfill  (' ')<< cur->b.getYearPublished() << setw (25)  << setfill  (' ');

            cout << "Not checked out"<< endl;
        }

        cur = cur -> next;
    }

    StudentNode *cur2 = sHead;
    while( cur2!=NULL)
    {
        if(cur2->s.bookExist(bookId))
        {
            cout << cur2->s.getBook(bookId).getId() << setw (25)  << setfill  (' ') << cur2->s.getBook(bookId).getName() <<setw (20)  << setfill  (' ')<<cur2->s.getBook(bookId).getYearPublished() << setw (25)  << setfill  (' ');

            cout << "Checked out by student " <<  cur2->s.getId() << endl;
        }
        cur2 = cur2->next;
    }
    cur = NULL;
    cur2 = NULL;
}

void LibrarySystem::showStudent(const int studentId) const
{
    StudentNode *cur = sHead;
    bool exist = false;

    while( cur != NULL)
    {
        if( cur->s.getId() == studentId)
        {
            exist = true;
            cout << "Student id: " << studentId << "  student name: " << cur->s.getName() << endl;

            if( cur->s.getNumOfBooks() > 0)
            {
                cout << "Student " << studentId << " has following books: " << endl;
                cur->s.displayBooks(false);
            }
            else
            {
                cout << "Student " << studentId << " has no books." << endl;
            }
        }
        cur = cur -> next;
    }
    cur = NULL;
    if(!exist)
    {
        cout << "Student " << studentId << " does not exist." << endl;
    }

}

//Helper methods

void LibrarySystem::deleteCheckedOut(const int bookId)
{
    Student::BookNode *cur = bHead;
    if( cur->b.getId() == bookId)
    {
        Student::BookNode *temp = bHead;
        bHead = bHead->next;

        temp->b.setAllStuff(0,"",0);
        delete temp;
            temp = NULL;

            numOfBooksInLibrary--;
        }
        else
        {

            while( cur-> next != NULL)
            {
                if(cur->next->b.getId()== bookId)
                {

                    Student::BookNode *temp = cur->next;

                    if( cur->next->next != NULL)
                    {
                        cur->next = cur->next->next;
                    }
                    else
                    {
                        cur->next = NULL;
                    }

                    numOfBooksInLibrary--;
                    numOfBooksCheckedOut++;
                    delete temp;
                    temp = NULL;
                    break;
                }
                cur = cur -> next;
            }

        }
        cur = NULL;
}

void LibrarySystem::addBookBack(const int bookId, const string bookName, const int bookYear)
{
    if( bHead == NULL )
    {

        bHead = new Student::BookNode;
        bHead->b.setAllStuff(bookId, bookName, bookYear);
        bHead->next = NULL;
        numOfBooksInLibrary++;

    }
    else
    {
        Student::BookNode *bNode = new Student::BookNode;
        bNode->b.setAllStuff(bookId, bookName, bookYear);
        bNode->next = bHead;
        bHead = bNode;


        numOfBooksInLibrary++;
    }
}
