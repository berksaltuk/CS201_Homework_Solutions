#include "Flight.h"
#include <iostream>
using namespace std;

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * FLIGHT CLASS
 */

Flight::Flight()
{
	resSize = 0;
    flightNo = 0;
    seatNo = 0;
    rowNo = 0;
    valid = 0;

	res = NULL;
	seats = NULL;
}


Flight::Flight(int fNo, int rNo, int sNo) : flightNo(fNo), rowNo(rNo), seatNo(sNo)
{
    valid = 0;
	resSize = 10;


    seats = new char*[rowNo];
	res = new Reservation[resSize];

    for(int i = 0; i < rowNo; ++i)
    {
        seats[i] = new char[seatNo];
    }
    for( int i = 0; i < rowNo; i++)
    {
        for( int j = 0; j < seatNo; j++)
        {
            seats[i][j] = 'o';
        }
    }

}

Flight::Flight( const Flight &obj){

	for(int i = 0; i < rowNo; ++i)
    {
        delete [] seats[i];
        seats[i] = NULL;
    }

        delete [] seats;
        seats = NULL;


        delete [] res;
        res = NULL;


    valid = obj.valid;
    flightNo = obj.getFlightNo();
    rowNo = obj.getRowNo();
    seatNo = obj.getSeatNo();



    if( obj.seats != NULL)
    {
        seats = new char*[rowNo];
        for(int i = 0; i < rowNo; ++i)
        {
            seats[i] = new char[seatNo];
        }

        for( int i = 0; i < rowNo; i++)
        {
            for( int j = 0; i < seatNo; i++)
            {
                seats[i][j] = obj.seats[i][j];
            }
        }
    }
    else{ seats = NULL; }

    if( obj.res != NULL)
    {
        for( unsigned int i = 0; i < resSize; i++)
        {
            res[i] = obj.res[i];
        }

    }
}

Flight::~Flight()
{

	if( seats ){
	for(int i = 0; i < rowNo; ++i)
    {
        delete [] seats[i];
        seats[i] = NULL;
    }

        delete [] seats;
        seats = NULL;
	}

    if( res ){
        delete [] res;
    }

}


int Flight::getAvailableSeats(){

    int count = 0;


    for( int i = 0; i < (rowNo); i++){
        for( int j = 0; j < seatNo; j++)
        {
            if(seats[i][j] == 'o'){
            count++;
            }
        }
    }
    return count;

}

int Flight::getFlightNo() const
{
    return flightNo;
}

int Flight::getRowNo() const
{
    return rowNo;
}

int Flight::getSeatNo() const
{
    return seatNo;
}

void Flight::displayVisually(){

    char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


    int numberTag = 1;

    for( int i = 0; i < getSeatNo(); i++){

        cout << letters[i] << " ";

    }
    cout << endl;
    cout << numberTag << " ";

    for( int i = 0; i < getRowNo(); i++){
        for( int j = 0; j < getSeatNo(); j++){
            cout << seats[i][j] << " ";
        }
        cout << endl;

        numberTag++;
        if( !(i + 2 > getRowNo())){{
        cout << numberTag << " ";
        }
}

    }}

Reservation Flight::reserve(const int resNo, const int numPassengers,const int *seatRow, const char *seatCol){

		Reservation r;
		r.init(resNo, numPassengers, seatRow, seatCol, getFlightNo());
		r.reserve(numPassengers, seatRow, seatCol, seats);

        res[valid++] = r;
        return r;

}

int Flight::getResForFlight(int resCode){
	int temp = 0;

	for(unsigned int i = 0; i < valid; i++){
		if( res[i].getReservationNo() == resCode)
        {
            temp = res[i].getReservationNo();
        }
	}

	return temp;
	}

void Flight::cancel(int resCode){

	for(unsigned int i = 0; i < valid; i++){
		if( res[i].getReservationNo() == resCode){
			res[i].cancel(seats);

			Reservation* temp = new Reservation[resSize - 1];

					for(unsigned int k = 0; k < i; k++)
					{
						temp[k] = res[k];
					}
					for(unsigned int j = i + 1; j < resSize; j++){
						temp[j - 1] = res[j];
					}
					delete [] res;
					valid--;
					resSize--;
					res = new Reservation[resSize];
					for(unsigned int a = 0; a < resSize; a++){
					res[a] = temp[a];
					}
					delete [] temp;

			}
	}

	}

Flight& Flight::operator=( const Flight& right ){


    if ( &right != this ) { // to avoid self-assignment

    valid = right.valid;
    flightNo = right.getFlightNo();

    if ( resSize != right.resSize ) {
    if ( resSize > 0 ){
    delete [] res;}

    resSize = right.resSize;
    if (resSize > 0 ){
    res = new Reservation[ resSize ];
    }
    else{
    res = NULL;
    }
    }
    for ( unsigned int i = 0; i < resSize; i++ ){
    res[ i ] = right.res[ i ];
    }

    if( rowNo != right.rowNo)
    {
        if( rowNo > 0)
        {
            for(int i = 0; i < rowNo; ++i) {
            delete [] seats[i];

            }

            delete seats;
        }


        rowNo = right.getRowNo();
        seatNo = right.getSeatNo();

        if( rowNo > 0 && seatNo > 0)
        {
            seats = new char*[rowNo];
            for(int i = 0; i < rowNo; ++i) {
                seats[i] = new char[seatNo];
            }

        }
        else{ seats = NULL;}
    }

     for( int i = 0; i < rowNo; i++){
            for( int j = 0; j < seatNo; j++){
        seats[i][j] = right.seats[i][j];
        }
    }


}
return *this; // to allow cascading

}
