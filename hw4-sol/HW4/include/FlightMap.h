#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H

#include <iostream>
#include <fstream>
#include <string>
#include "City.h"
#include "PathStack.h"

using namespace std;
class FlightMap {

    public:
        FlightMap( const string cityFile, const string flightFile );
        ~FlightMap();
        void displayAllCities() const;
        void displayAdjacentCities( const string cityName ) const;
        void displayFlightMap() const;
        void findFlights( const string deptCity, const string destCity ) const;
        void findLeastCostFlight( const string deptCity, const string destCity ) const;
        void runFlightRequests( const string requestFile ) const;

        //Additional Methods
        void addCity( string name); // Only add cities since paths will change, not the city number
        void addPath( string p);
        void setAllUnvisited() const;

        bool isListEmpty() const;

    private:

        PathStack** paths;
        struct CityNode //List for keeping cities
        {
            City c;
            CityNode *next;
        };

        CityNode *head;
        int numOfCities;
    public: CityNode* returnCity(string cityName) const;
};


#endif // FLIGHTMAP_H


