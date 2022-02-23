#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include "Reservation.h"

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * FLIGHT INTERFACE
 */

class Flight
{
    public:
        Flight();
		Flight(const int flightNo, const int rowNo, const int sNo);
        Flight(const Flight &obj);
        ~Flight();

		Flight& operator=( const Flight &right);

        int getFlightNo() const;
        int getAvailableSeats();
        int getRowNo() const;
        int getSeatNo() const;
        int getResForFlight(int resCode);

        void displayVisually();
        void cancel(int resCode);

        Reservation reserve(const int resNo, const int numPassengers, const int *seatRow, const char *seatCol);



    private:
        unsigned int valid;
        unsigned int resSize;

        int flightNo;
        int rowNo;
        int seatNo;

        char** seats;

		Reservation* res;
};

#endif // FLIGHT_H
