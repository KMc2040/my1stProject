all: main.c seat_reservation.c
	gcc main.c seat_reservation.c -o make -I.