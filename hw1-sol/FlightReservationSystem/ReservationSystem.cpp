#include "ReservationSystem.h"
#include "Flight.h"

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * RESERVATION SYSTEM CLASS
 */

using namespace std;
ReservationSystem::ReservationSystem(){
	size = 1;
	resSize = 1;

    flights = new Flight[size];

    valid = 0;
	resNo = 1;
	validRes = 0;
	reserves = new Reservation[resSize];
}

ReservationSystem::~ReservationSystem(){

    delete [] flights;
	delete [] reserves;

}

void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo ){

    bool isUnique = true;
    Flight temp (flightNo, rowNo, seatNo);
    for( unsigned int i = 0; i < valid; i++ )
    {
        if (flights[i].getFlightNo() == flightNo)
        {
            isUnique = false;
        }
    }

    if( isUnique)
    {
		if( valid < size)
		{
		flights[valid] = temp; // YES
		}
		else {
			unsigned int tempS = size + 1;
			Flight* tempo = new Flight[tempS];
			for(unsigned int i = 0; i < size; i++){
					tempo[i] = flights[i];
			}

			tempo[valid] = temp;


			size++;
			delete [] flights;
			flights = new Flight[size];
			for( unsigned int i = 0; i < size; i++){
				flights[i] = tempo[i];
			}
			delete [] tempo;
		}

    valid++;

    cout << "Flight " << flightNo << " has been added." << endl;
    }
    else{
        cout << "Flight " << flightNo << " already exists." << endl;
    }
}

void ReservationSystem::cancelFlight( const int flightNo ){
   bool found = false;

    for(unsigned i = 0; i < valid; i++)
    {
        if(flights[i].getFlightNo() == flightNo)
        {

			Flight* temp = new Flight[ size - 1];
			for(unsigned int k = 0; k < i; k++)
			{
				temp[k] = flights[k];
			}
            for(unsigned int j = i + 1; j < size; j++){
                temp[j - 1] = flights[j];
            }
			delete [] flights;
			valid--;
			size--;
			flights = new Flight[size];
			for(unsigned int a = 0; a < size; a++){
				flights[a] = temp[a];
			}
			delete [] temp;


			Reservation* tempRes = new Reservation[resSize - 1];

					for(unsigned int k = 0; k < i; k++)
					{
						tempRes[k] = reserves[k];
					}
					for(unsigned int j = i + 1; j < resSize; j++){
						tempRes[j - 1] = reserves[j];
					}
					delete [] reserves;
					validRes--;
					resSize--;
					reserves = new Reservation[resSize];
					for(unsigned int a = 0; a < resSize; a++){
					reserves[a] = tempRes[a];
					}

					delete [] tempRes;


        found = true;
        cout << "Flight " << flightNo << " and its all reservations are canceled." << endl;
        }
    }

    if(found == false){
        cout << "Flight " << flightNo << " does not exist." << endl;
    }
}

void ReservationSystem::showAllFlights(){

    if ( valid == 0)
    {
        cout << "No flights exist." << endl;
    }
    else{
		cout << "Flights currently operated:" << endl;
        for( unsigned int i = 0; i < valid; i++)
        {
            cout << "Flight " << flights[i].getFlightNo() << " (" << flights[i].getAvailableSeats() << " available seats)" << endl;
        }
    }
}

void ReservationSystem::showFlight( const int flightNo ){
   bool found = false;

    for(unsigned int i = 0; i < valid; i++)
    {
        if( flights[i].getFlightNo() == flightNo)
        {
			cout << "Flight " << flightNo << " has " << flights[i].getAvailableSeats() << " available seats" << endl;
            flights[i].displayVisually();
            found = true;
        }

    }

    if(!found){
        cout << "Flight " << flightNo << " does not exist." << endl;
    }

}

int ReservationSystem::makeReservation( const int flightNo, const int numPassengers,const int *seatRow, const char *seatCol ){

    for( unsigned int i = 0; i < valid; i++){
        if( flights[i].getFlightNo() == flightNo){

                    if( validRes < resSize){

                        reserves[validRes] = flights[i].reserve(resNo++, numPassengers, seatRow, seatCol);

                    }
                    else{

                        unsigned int tempS = resSize + 1;
                        Reservation* tempo = new Reservation[tempS];
                        for(unsigned int j = 0; j < resSize; j++){
                            tempo[j] = reserves[j];
                        }

                        tempo[validRes] = flights[i].reserve(resNo++, numPassengers, seatRow, seatCol);

                        resSize++;
                        delete [] reserves;
                        reserves = new Reservation[resSize];
                        for( unsigned int k = 0; k < resSize; k++){
                        reserves[k] = tempo[k];
                        }
                        delete [] tempo;

                    }
                    return reserves[validRes++].getReservationNo();
        }
    }
    cout << "Flight " << flightNo << " does not exist to make a reservation." << endl;
    return -1;
}

void ReservationSystem::cancelReservation( const int resCode ){
	bool found = false;

    for( unsigned int i = 0; i < valid; i++){
        if( flights[i].getResForFlight(resCode) == resCode){
            found = true;
			flights[i].cancel(resCode);

			for( unsigned int b = 0; b < validRes; b++){
				if( reserves[i].getReservationNo() == resCode)
				{
					Reservation* temp = new Reservation[resSize - 1];

					for(unsigned int k = 0; k < i; k++)
					{
						temp[k] = reserves[k];
					}
					for(unsigned int j = i + 1; j < resSize; j++){
						temp[j - 1] = reserves[j];
					}
					delete [] reserves;
					validRes--;
					resSize--;
					reserves = new Reservation[resSize];
					for(unsigned int a = 0; a < resSize; a++){
					reserves[a] = temp[a];
					}
					delete [] temp;
				}
			}

            break;
        }
    }

    if(found == false)
    {
        cout << "No reservations under code " << resCode << endl;
    }

}

void ReservationSystem::showReservation( const int resCode ){
   bool found = false;

    for( unsigned int i = 0; i < validRes; i++){

        if( reserves[i].getReservationNo() == resCode){
            found = true;
			reserves[i].display();
            break;
        }
    }

    if(found == false)
    {
        cout << "No reservations under code " << resCode << endl;
    }

}
