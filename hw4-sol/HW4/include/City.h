#ifndef CITY_H
#define CITY_H

using namespace std;
#include <iostream>
class City
{
    public:
        City();
        ~City();
        string getName();
        bool getVisited();
        void setName( string name);
        void setVisited( bool visit);
        void addAdjacent( string name, int id, int cost );
        bool isEmpty();
        void displayAdjacents();
        bool hasUnvisitedAdjacents();
        void setAdjacentsUnvisited();

        struct AdjacentCityNode // List for keeping a city's adjacents
        {
            string name;
            int costToGo;
            int flightID;
            bool isVisited;
            AdjacentCityNode *next;
        };

        AdjacentCityNode* returnHead();
        AdjacentCityNode* returnFirstUnvisitedAdjacent();

    private:
        string name;
        bool isVisited;
        AdjacentCityNode *head;
        int addjacentSize;
};

#endif // CITY_H
