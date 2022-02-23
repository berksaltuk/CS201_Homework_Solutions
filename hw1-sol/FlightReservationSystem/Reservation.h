#ifndef RESERVATION_H
#define RESERVATION_H

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * RESERVATION INTERFACE
 */

class Reservation
{
public:
		Reservation();
        ~Reservation();
		Reservation& operator=(const Reservation& right);
		Reservation( const Reservation &obj);

		int getReservationNo();

		void init(const int resNo, const int numPassengers, const int *seatRow, const char *seatCol, const int flightNo);
        void reserve(const int numPassengers, const int *seatRow, const char *seatCol, char**& seats);
		void display();
		void cancel(char**& seats);

    private:
        int reservationNo;
		int passengers;
		int fNo;

		int* seat;

		char* col;

};

#endif // RESERVATION_H

