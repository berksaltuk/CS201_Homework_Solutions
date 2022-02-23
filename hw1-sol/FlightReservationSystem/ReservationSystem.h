#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include "Flight.h"
#include "Reservation.h"
#include <iostream>

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * RESERVATION SYSTEM INTERFACE
 */


class ReservationSystem
{
    public:
        ReservationSystem();
        ~ReservationSystem();

        int makeReservation( const int flightNo, const int numPassengers,const int *seatRow, const char *seatCol );

        void addFlight( const int flightNo, const int rowNo, const int seatNo );
        void cancelFlight( const int flightNo );
        void showAllFlights();
        void showFlight( const int flightNo );
        void cancelReservation( const int resCode );
        void showReservation( const int resCode );

        // DATA MEMBERS AND METHODS THAT I ADDED
     private:

        Flight* flights;
		Reservation* reserves;

		int resNo;

        unsigned int valid;
		unsigned int size;
		unsigned int validRes;
		unsigned int resSize;
};

#endif // RESERVATIONSYSTEM_H
