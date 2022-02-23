#include "FlightMap.h"
#include <sstream>
FlightMap::FlightMap(const string cityFile, const string flightFile)
{

    head = NULL;

    numOfCities = 0;
    //Declare variables
    string fileName = cityFile;
    string name;
    ifstream inputFile;

    //Open the stream for the input file
    inputFile.open( fileName.c_str(), ios_base::in );

    //Continue until the end of the file
    while ( inputFile.eof() == false ) {
        //Read until the end of the line
        getline( inputFile, name, '\n' );
        addCity(name);
    }

    //Close the input file stream
    inputFile.close();


    string fileName2 = flightFile;
    string departureCity;
    string landingCity;
    string flightID;
    string cost;

    ifstream inputFile2;

    //Open the stream for the input file
    inputFile2.open( fileName2.c_str(), ios_base::in );
    //Continue until the end of the file
    while ( inputFile2.eof() == false ) {
        //Read until a comma
        getline( inputFile2, departureCity, ',' );
        string holdDep = departureCity;

        getline( inputFile2, landingCity, ',' );
        string holdLand = landingCity;

        getline( inputFile2, flightID, ',' );
        stringstream id(flightID);
        int holdID = 0;
        id >> holdID;

        getline( inputFile2, cost, '\n' );
        stringstream costOf(cost);
        int holdCost = 0;
        costOf >> holdCost;

        CityNode *cur = head;
        while( cur != NULL)
        {
            if( cur->c.getName().compare( holdDep) == 0)
            {
                cur->c.addAdjacent( holdLand, holdID, holdCost);
            }
            cur = cur->next;
        }


    }
    //Close the input file stream
    inputFile2.close();


}

FlightMap::~FlightMap()
{
    CityNode *cur = head;
    while( cur != NULL)
    {
        CityNode *next = cur->next;

        delete cur;

        cur = next;
    }

    head = NULL;

}

void FlightMap::displayAllCities() const
{
    CityNode *cur = head;

    while( cur != NULL){
        if( cur->next != NULL)
        {
            cout << cur->c.getName() << ", ";
        }
        else
        {
            cout << cur->c.getName() << "." <<endl;
        }
        cur = cur->next;
    }
}

void FlightMap::displayAdjacentCities( const string cityName ) const
{
    CityNode *cur = head;

    while( cur != NULL)
    {
        if( cur->c.getName().compare(cityName) == 0)
        {
            cur->c.displayAdjacents();
        }
        cur = cur->next;
    }
    cout << endl;
}

void FlightMap::displayFlightMap() const
{
    CityNode *cur = head;

    while( cur != NULL){

        cout << cur->c.getName() << "-> ";
        cur->c.displayAdjacents();
        cout << endl;
        cur = cur->next;
    }
    cout << endl;
}

void FlightMap::findFlights( const string deptCity, const string destCity ) const
{
   /* cout << "Request is to fly from " << deptCity << " to "  << destCity << "." << endl;
    bool displayedOnce = false;
    // TO DO
    string display = "";
    int grandTotal = 0;
    PathStack newPath;
    CityNode *cur = returnCity( deptCity);


    newPath.push( cur->c.getName());

    while( cur!= NULL){
        while( !cur->c.isEmpty() &&!newPath.isStackEmpty() && (newPath.getTop()->name).compare(destCity) != 0)
        {

            if( !cur->c.isEmpty() && cur->c.hasUnvisitedAdjacents())
            {
                City::AdjacentCityNode *temp = cur->c.returnHead();
                while( temp !=NULL )
                {

                    if( temp->isVisited == false)
                    {
                        temp->isVisited = true;
                        string adjacent = temp->name;
                        CityNode *otherCur = returnCity( adjacent);

                        if( otherCur->c.getVisited() == false)
                        {

                            display += "Flight" + cur->c.getName() + " to "  + otherCur->c.getName() + "  TL \n";

                            newPath.push( otherCur->c.getName());
                            cur = otherCur;

                            grandTotal += temp->costToGo;
                            break;
                        }
                    }

                    temp = temp->next;
                }
            }
            else
            {
                newPath.pop();
            }
        }
        if( !newPath.isStackEmpty())
        {
            displayedOnce = true;

            cout << display << endl;
            cout << "Total Cost .......... " << grandTotal << " TL" << endl;


        }

        //returnCity(newPath.getTop()->name)->c.setVisited(false);

        newPath.pop();
        if( !newPath.isStackEmpty())
        {
            cur = returnCity( newPath.getTop()->name);

        }
        else
        {
            cur = NULL;
        }

    }

    if( !displayedOnce)
    {
        cout << "Sorry. BSYAir does not fly from " << deptCity << " to "  << destCity << "." << endl;
    }
    setAllUnvisited();*/
}
void FlightMap::findLeastCostFlight( const string deptCity, const string destCity ) const
{

   cout << "A least cost path from " << deptCity << " to " << destCity << " is \n";
   // TO DO
   findFlights( deptCity, destCity);

}

void FlightMap::runFlightRequests( const string requestFile ) const
{
    //Declare variables
    string fileName = requestFile;
    string depCity;
    string landCity;
    ifstream inputFile;

    //Open the stream for the input file
    inputFile.open( fileName.c_str(), ios_base::in );

    //Continue until the end of the file
    while ( inputFile.eof() == false ) {

        getline( inputFile, depCity, ',' );
        string holdDep = depCity;

        getline( inputFile, landCity, '\n' );
        string holdLand = landCity;

        findFlights( holdDep, holdLand);
        findLeastCostFlight( holdDep, holdLand);
    }

    //Close the input file stream
    inputFile.close();

}

//Additional methods
void FlightMap::addCity( string name)
{
    CityNode *newNode = new CityNode;
    newNode->c.setName(name);
    newNode->next = head;
    head = newNode;


    numOfCities++;
}

bool FlightMap::isListEmpty() const
{
    return head == NULL;
}

void FlightMap::setAllUnvisited() const
{
    CityNode *cur = head;

    while( cur != NULL)
    {
        cur->c.setVisited( false );
        cur->c.setAdjacentsUnvisited();
        cur = cur->next;
    }
}

FlightMap::CityNode* FlightMap::returnCity( string cityName) const
{
    CityNode* cur = head;
    while( cur != NULL)
    {
        if( cityName.compare( cur->c.getName()) == 0)
        {
            return cur;
        }

        cur = cur->next;
    }

    return NULL;
}
