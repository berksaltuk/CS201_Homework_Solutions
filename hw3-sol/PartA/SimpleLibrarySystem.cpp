#include "SimpleLibrarySystem.h"
#include <iostream>
/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Simple Library System Class
 */


LibrarySystem::LibrarySystem()
{
    this->head = NULL;
    numOfStudents = 0;
}

LibrarySystem::~LibrarySystem()
{
    StudentNode* current = head;
    while( current != NULL ) {
        StudentNode* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

void LibrarySystem::addStudent(const int studentId, const string studentName)
{
    if( studentId > 0)
    {
        if( numOfStudents == 0)
        {
            head = new StudentNode;
            head->s.setId(studentId);
            head->s.setName(studentName);
            head->next = NULL;

            numOfStudents++;
            cout << "The student with ID " << studentId << " and name " << studentName <<" has been added as a member." << endl;
        }
        else
        {
            StudentNode *current = head;
            bool found = false;

            while(current != NULL)
            {
                if( current->s.getId() == studentId)
                {
                    found = true;
                    cout << "The student with ID " << studentId << " already exist." << endl;
                }

                current = current->next;
            }

            if( found == false)
            {
                StudentNode *sNode = new StudentNode;
                sNode->next = head;

                sNode->s.setId(studentId);
                sNode->s.setName(studentName);

                head = sNode;
                numOfStudents++;

                cout << "The student with ID " << studentId << " and name " << studentName <<" has been added as a member." << endl;
            }
        }
    }
    else
    {
        cout << "ID is not valid." << endl;
    }

}

void LibrarySystem::deleteStudent(const int studentId)
{
    if( numOfStudents > 0)
    {
        StudentNode *current = head;

        if( current->s.getId() == studentId)
        {
            StudentNode *temp = head; //holding the head to not cause a memory leak

            cout << "The student with ID " << studentId << " and name " << head->s.getName() <<" has been deleted." << endl;
            head = head->next;

            numOfStudents--;

            temp->s.setId(0);
            temp->s.setName("");
            delete temp;
        }
        else
        {
            bool found = false;
            while(current->next != NULL)
            {
                if( current->next->s.getId() == studentId)
                {
                    cout << "The student with ID " << studentId << " and name " << current->next->s.getName() <<" has been deleted." << endl;
                    found = true;

                    StudentNode *temp = current->next; //holding the node which I will delete to not cause a memory leak
                    if( current->next->next != NULL)
                    {
                        current->next = current->next->next;
                    }
                    else
                    {
                        current->next = NULL;
                    }

                    numOfStudents--;
                    temp->s.setId(0);
                    temp->s.setName("");
                    delete temp;
                    break;
                }
                current = current->next;
            }

            if(found == false)
            {
                cout << "No student with the ID " << studentId << "." << endl;
            }
        }
    }
    else
    {
        cout << "There is no one in the system." << endl;
    }

}

void LibrarySystem::showStudent(const int studentId) const
{
    StudentNode *current = head;
    bool found = false;
    if( numOfStudents > 0)
    {
        while(current != NULL)
        {
            if( current->s.getId() == studentId)
            {
                found = true;
                cout << "The student with ID " << current->s.getId() << " is " << current->s.getName() << "." << endl;
            }

            current = current->next;
        }

        if(found == false)
        {
           cout << "No students exist with ID " << studentId << "." <<endl;
        }
    }
    else
    {
        cout << "No students in the system." << endl;
    }
}
