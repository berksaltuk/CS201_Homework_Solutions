#include "FlightMap.h"

int main() {

    FlightMap fm( "files/cityFile.txt", "files/flightFile.txt" );

    cout << "The list of the cities that BSYAir serves is given below:" << endl;
    fm.displayAllCities();
    cout << endl;

    cout << "The cities adjacent to W are:" << endl;
    fm.displayAdjacentCities( "W" );
    cout << endl;

    cout << "The whole flight map is shown below:" << endl;
    fm.displayFlightMap();
    cout << endl;

    fm.findFlights( "W", "Z" );
    cout << endl;

    fm.findFlights( "S", "P" );
    cout << endl;

    fm.findLeastCostFlight( "Y", "Z" );
    cout << endl;

    fm.findLeastCostFlight( "P", "X" );
    cout << endl;

    fm.runFlightRequests( "files/requestFile.txt" );

    return 0;
}

