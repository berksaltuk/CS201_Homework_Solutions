#include "City.h"

City::City()
{
    head = NULL;
    name = "";

    isVisited = false;
}

City::~City()
{
    AdjacentCityNode *cur = head;
    while( cur != NULL)
    {
        AdjacentCityNode *next = cur->next;

        delete cur;

        cur = next;
    }

    head = NULL;
}

void City::setName( string name)
{
    this->name = name;
}

string City::getName()
{
    return name;
}

bool City::getVisited()
{
    return isVisited;
}

void City::setVisited( bool visited)
{
    isVisited = visited;
}

void City::addAdjacent( string cName, int id, int cost)
{
   AdjacentCityNode *newNode = new AdjacentCityNode;

    if( head == NULL)
    {
        head = newNode;
        head->next = NULL;
        head->name = cName;
        head->flightID = id;
        head->costToGo = cost;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        head->name = cName;
        head->flightID = id;
        head->costToGo = cost;
    }
    head->isVisited = false;
    addjacentSize++;
}

void City::displayAdjacents()
{
    AdjacentCityNode *cur = head;
    while( cur != NULL)
    {
        cout << cur->name << ", ";
        cur = cur->next;
    }
}

bool City::isEmpty()
{
    return head == NULL;
}

City::AdjacentCityNode* City::returnHead()
{
    return head;
}

bool City::hasUnvisitedAdjacents()
{
    AdjacentCityNode *cur = head;
    while( cur != NULL)
    {
        if( cur->isVisited == false)
        {
            return true;
        }
        cur = cur->next;
    }

    return false;
}

void City::setAdjacentsUnvisited()
{
    AdjacentCityNode *cur = head;

    while( cur!= NULL)
    {
        cur->isVisited = false;
        cur = cur->next;
    }
}

City::AdjacentCityNode* City::returnFirstUnvisitedAdjacent()
{
    AdjacentCityNode* cur = head;

    while( cur != NULL)
    {
        if( !cur->isVisited)
        {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}
