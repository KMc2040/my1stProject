/*
 * seat_reservation.c
 *
 *  Created on: Jun 29, 2025
 *      Author: K M Charan
 *
 *  -----------*-----------
 *
 * This file implements the core logic for the bus seat reservation system,
 * including initializing, displaying, booking, and cancelling seats.
 * Pointer arithmetic is used to navigate the 2D seat array.
 *
 *  -----------*-----------
 */

#include <stdio.h>  // For standard input/output functions like printf, scanf
#include "seat_reservation.h" // Include our custom header for seat reservation functions

/**
 * @brief Initializes all seats in the bus to SEAT_EMPTY.
 *
 * The 2D array is treated as a 1D array for efficient
 * traversal using pointer arithmetic.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * @param rows The number of rows in the seat layout.
 * @param cols The number of columns in the seat layout.
 */
void initializeSeats(int *seats, int rows, int cols) {
    // Iterate through all elements of the 2D array using pointer arithmetic
    for (int i = 0; i < rows * cols; ++i) {
        *(seats + i) = SEAT_EMPTY; // Set each seat to empty
    }
}

/**
 * @brief Displays the current seating arrangement of the bus.
 * 'O' represents an empty seat, 'X' represents a booked seat.
 *
 * Seats are displayed with 1-based indexing for user readability.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * @param rows The number of rows in the seat layout.
 * @param cols The number of columns in the seat layout.
 */
void displaySeats(int *seats, int rows, int cols) {
    printf("\n--- Bus Seat Layout ---\n");
    printf("    "); // Padding for column numbers
    // Print column headers (1-based)
    for (int j = 0; j < cols; ++j) {
        printf("C%d ", j + 1);
    }
    printf("\n");

    // Print row separator
    printf("   +");
    for (int j = 0; j < cols; ++j) {
        printf("---");
    }
    printf("+\n");

    // Iterate through rows and columns to display seat status
    for (int i = 0; i < rows; ++i) {
        printf("R%d | ", i + 1); // Print row header (1-based)
        for (int j = 0; j < cols; ++j) {
            // Access seat using pointer arithmetic: *(base_address + row_index * num_cols + col_index)
            if (*(seats + i * cols + j) == SEAT_EMPTY) {
                printf("O  "); // Empty seat
            } else {
                printf("X  "); // Booked seat
            }
        }
        printf("|\n");
    }

    // Print bottom separator
    printf("   +");
    for (int j = 0; j < cols; ++j) {
        printf("---");
    }
    printf("+\n");
    printf("O = Available, X = Booked\n");
    printf("-------------------------\n");
}

/**
 * @brief Attempts to book a seat at the specified row and column.
 *
 * Validates the input coordinates and checks if the seat is available.
 * If valid and available, the seat is marked as booked using pointer arithmetic.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * @param rows The total number of rows.
 * @param cols The total number of columns.
 * @param row The 0-indexed row number of the seat to book.
 * @param col The 0-indexed column number of the seat to book.
 * @return 1 if the seat was successfully booked, 0 otherwise.
 */
int bookSeat(int *seats, int rows, int cols, int row, int col) {
    // Validate row and column coordinates (0-indexed)
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        printf("Error: Invalid seat coordinates (Row: %d, Col: %d). Please enter valid numbers.\n", row + 1, col + 1);
        return 0; // Indicate failure
    }

    // Access the seat using pointer arithmetic
    if (*(seats + row * cols + col) == SEAT_EMPTY) {
        *(seats + row * cols + col) = SEAT_BOOKED; // Mark seat as booked
        printf("Seat R%d-C%d successfully booked.\n", row + 1, col + 1);
        return 1; // Indicate success
    } else {
        printf("Seat R%d-C%d is already booked. Please choose another seat.\n", row + 1, col + 1);
        return 0; // Indicate failure
    }
}

/**
 * @brief Attempts to cancel a seat at the specified row and column.
 *
 * Validates the input coordinates and checks if the seat is currently booked.
 * If valid and booked, the seat is marked as empty using pointer arithmetic.
 *
 * @param seats A pointer to the beginning of the 2D seat array.
 * @param rows The total number of rows.
 * @param cols The total number of columns.
 * @param row The 0-indexed row number of the seat to cancel.
 * @param col The 0-indexed column number of the seat to cancel.
 * @return 1 if the seat was successfully cancelled, 0 otherwise.
 */
int cancelSeat(int *seats, int rows, int cols, int row, int col) {
    // Validate row and column coordinates (0-indexed)
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        printf("Error: Invalid seat coordinates (Row: %d, Col: %d). Please enter valid numbers.\n", row + 1, col + 1);
        return 0; // Indicate failure
    }

    // Access the seat using pointer arithmetic
    if (*(seats + row * cols + col) == SEAT_BOOKED) {
        *(seats + row * cols + col) = SEAT_EMPTY; // Mark seat as empty
        printf("Seat R%d-C%d successfully cancelled.\n", row + 1, col + 1);
        return 1; // Indicate success
    } else {
        printf("Seat R%d-C%d is not booked. Cannot cancel.\n", row + 1, col + 1);
        return 0; // Indicate failure
    }
}




