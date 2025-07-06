/*
 * seat_reservation.h
 *
 *  Created on: Jun 29, 2025
 *      Author: K M Charan
 *
 * -----------*-----------
 *
 * The header file contains function declarations and constants.
 *
 *  -----------*-----------
 */

#ifndef SEAT_RESERVATION_H_
#define SEAT_RESERVATION_H_

// Define the dimensions of the bus seat layout
#define ROWS 5  // Number of rows
#define COLS 4  // Number of columns

// Define seat states
#define SEAT_EMPTY 0  // Represents an empty (available) seat
#define SEAT_BOOKED 1 // Represents a booked (occupied) seat

/**
 * @brief Initializes all seats in the bus to SEAT_EMPTY.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * It's treated as a 1D array for pointer arithmetic.
 * @param rows The number of rows in the seat layout.
 * @param cols The number of columns in the seat layout.
 */
void initializeSeats(int *seats, int rows, int cols);

/**
 * @brief Displays the current seating arrangement of the bus.
 * 'O' represents an empty seat, 'X' represents a booked seat.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * @param rows The number of rows in the seat layout.
 * @param cols The number of columns in the seat layout.
 */
void displaySeats(int *seats, int rows, int cols);

/**
 * @brief Attempts to book a seat at the specified row and column.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * @param rows The total number of rows.
 * @param cols The total number of columns.
 * @param row The 0-indexed row number of the seat to book.
 * @param col The 0-indexed column number of the seat to book.
 * @return 1 if the seat was successfully booked, 0 otherwise (e.g., invalid
 * coordinates or seat already booked).
 */
int bookSeat(int *seats, int rows, int cols, int row, int col);

/**
 * @brief Attempts to cancel a seat at the specified row and column.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * @param rows The total number of rows.
 * @param cols The total number of columns.
 * @param row The 0-indexed row number of the seat to cancel.
 * @param col The 0-indexed column number of the seat to cancel.
 * @return 1 if the seat was successfully cancelled, 0 otherwise (e.g., invalid
 * coordinates or seat not booked).
 */
int cancelSeat(int *seats, int rows, int cols, int row, int col);

#endif /* SEAT_RESERVATION_H_ */
