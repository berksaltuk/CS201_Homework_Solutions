#ifndef PATHSTACK_H
#define PATHSTACK_H

#include "City.h"

using namespace std;

class PathStack
{
    public:
        PathStack();
        ~PathStack();
        bool isStackEmpty() const;
        void push( string name ) ;
        void pop();
        void display();
        void display2();
        struct myStack // Stack for keeping the paths
        {
            string name;
            myStack *second;
        };

        myStack* getTop();
    private:
        string *path;
        int pathLength;
        myStack *top;
};

#endif // PATHSTACK_H
