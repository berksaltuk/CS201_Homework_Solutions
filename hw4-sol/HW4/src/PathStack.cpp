#include "PathStack.h"

PathStack::PathStack()
{
    top = NULL;
    pathLength = 0;
}

PathStack::~PathStack()
{
    myStack *cur = top;
    while( cur != NULL)
    {
        myStack *next = cur->second;

        delete cur;

        cur = next;
    }

    top = NULL;

}

void PathStack::push( string cName )
{
    myStack *instance = new myStack;

    instance->name = cName;

    instance->second = top;

    top = instance;

    pathLength++;
}

void PathStack::pop()
{
    if(!isStackEmpty())
    {
        myStack *instance = top;

        top = top->second;

        instance->second = NULL;
        delete instance;

        pathLength--;
    }
}

bool PathStack::isStackEmpty() const
{
    return top == NULL;
}

PathStack::myStack* PathStack::getTop()
{
    if( !isStackEmpty())
    {
        return top;
    }
    return NULL;
}

void PathStack::display()
{
    myStack *cur = top;
    PathStack temp;

    while( cur!= NULL)
    {
        temp.push( cur->name);
        cur = cur->second;
    }
    temp.display2();
}

void PathStack::display2()
{
    myStack *cur = top;

    while( cur!= NULL)
    {
        cout << cur->name << " ";
        cur = cur->second;
    }
    cout<<endl;
}

