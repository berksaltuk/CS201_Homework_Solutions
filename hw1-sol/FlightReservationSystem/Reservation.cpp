#include "Reservation.h"
#include <iostream>

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * RESERVATION CLASS
 */

using namespace std;
Reservation::Reservation(){

reservationNo = 0;
passengers = 0;
fNo = 0;
col = NULL;
seat = NULL;
}

Reservation::Reservation( const Reservation &obj){

    reservationNo = obj.reservationNo;
    passengers = obj.passengers;
    fNo = obj.fNo;

    if( obj.col != NULL && obj.seat != NULL){

    col = new char[passengers];
    seat = new int[passengers];

    for(int i = 0; i < passengers; ++i) {
        col[i] = obj.col[i];
        seat[i] = obj.seat[i];
    }
    }
    else{ col = NULL; seat = NULL; }

}

Reservation& Reservation::operator=(const Reservation& right)
{

    if ( &right != this ) { // to avoid self-assignment

	reservationNo = right.reservationNo;
    fNo = right.fNo;
    if ( passengers != right.passengers ) {

    if ( passengers > 0 ){
    delete [] col;
    delete [] seat;}

    passengers = right.passengers;

    if (passengers > 0 ){
    seat = new int[ passengers ];
    col = new char[ passengers];
	}

    else{
    seat = NULL;
    col = NULL;}
    }

    for ( int i = 0; i < passengers; i++ )
	{
    col[ i ] = right.col[ i ];
    seat[ i ] = right.seat[ i ];}
    }
 return *this; // to allow cascading

}

void Reservation::init(const int resNo, const int numPassengers, const int *seatRow, const char *seatCol, const int flightNo)
{
	fNo = flightNo;
    reservationNo = resNo;
	passengers = numPassengers;
	col = new char[passengers];
	seat = new int[passengers];

	for(int i = 0; i < passengers; i++)
	{
		col[i] = seatCol[i];
		seat[i] = seatRow[i];
	}
}

Reservation::~Reservation()
{

	if( col ) { delete [] col; col = NULL;}
	if( seat ) { delete [] seat; seat = NULL;}

}


int Reservation::getReservationNo(){

return reservationNo;

}

void Reservation::display(){

		cout << "Reservations under " << reservationNo << " in Flight " << fNo << ": ";

		for( int i = 0; i < passengers; i++){
			cout << seat[i]  << col[i] << " ";
		}
		cout << endl;
}
void Reservation::reserve(const int numPassengers, const int *seatRow, const char *seatCol, char**& seats){
	int numEq = 0;
	int count = 0;
	for(int i = 0; i < numPassengers; i++)
	{
		if( seatCol[i] == 'A'){ numEq = 0; } if( seatCol[i] == 'B'){ numEq = 1; } if( seatCol[i] == 'C'){ numEq = 2; } if( seatCol[i] == 'D'){ numEq = 3; }

		if( seats[seatRow[i] - 1][numEq] == 'x')
		{
			count++;
			cout << seat[i]  << col[i] << " ";

		}
	}

	if( count > 0 )
	{
	    if( count == 1){
			cout << "is not available." << endl;
	    }
	    if( count > 1){
            cout << "are not available." << endl;
	    }
            reservationNo = -1;
	}
	else{

        for(int i = 0; i < numPassengers; i++)
        {
            if( seatCol[i] == 'A'){ numEq = 0; } if( seatCol[i] == 'B'){ numEq = 1; } if( seatCol[i] == 'C'){ numEq = 2; } if( seatCol[i] == 'D'){ numEq = 3; }

            seats[seatRow[i] - 1][numEq] = 'x';
        }
	}
}

void Reservation::cancel( char**& seats){

	int numEq = 0;
	cout << "Reservations for the seats ";
	for(int i = 0; i < passengers; i++)
	{
		if( col[i] == 'A'){ numEq = 0; } if( col[i] == 'B'){ numEq = 1; } if( col[i] == 'C'){ numEq = 2; } if( col[i] == 'D'){ numEq = 3; }
		if( col[i] == 'E'){ numEq = 4; } if( col[i] == 'F'){ numEq = 5; } if( col[i] == 'G'){ numEq = 6; } if( col[i] == 'H'){ numEq = 7; }

		seats[seat[i] - 1][numEq] = 'o';
		cout << seat[i] << col[i] << " ";
	}
	cout << "is canceled in Flight " << fNo;
	cout << endl;
}
