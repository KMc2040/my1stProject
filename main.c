/*
 * main.c
 *
 *  Created on: Jun 29, 2025
 *      Author: K M Charan
 *
 * -----------*-----------
 * 
 * This is the main application file for the bus seat reservation system.
 * It provides a menu-driven interface for users to interact with the system.
 *
 * Note: Please don't run it in IDE, please use terminal for better experience.
 * Save the requires files as attached in the GitHub.
 * Open the folder location in the terminal, and use the below command for the experience.
 * start ./main.exe
 *
 * -----------*-----------
 *
 */

#include <stdio.h>   // For standard input/output functions like printf, scanf
#include <stdlib.h>  // For exit()
#include "seat_reservation.h" // Include our custom header for seat reservation functions

/**
 * @brief Clears the input buffer to prevent issues with subsequent scanf calls.
 * This is important when scanf fails to read expected input.
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Declare a 2D array to represent the bus seats.
    // The dimensions ROWS and COLS are defined in seat_reservation.h
    int busSeats[ROWS][COLS];

    // Initialize all seats to empty
    initializeSeats((int *)busSeats, ROWS, COLS); // Cast to int* as initializeSeats expects a pointer to int

    int choice;
    int row, col;

    do {
        // Display the main menu
        printf("\n--- Bus Seat Reservation System ---\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Read user's choice with input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            clearInputBuffer(); // Clear buffer in case of invalid input
            continue; // Skip to the next iteration of the loop
        }
        clearInputBuffer(); // IMPORTANT: Clear any remaining newline character after reading the integer

        switch (choice) {
            case 1:
                displaySeats((int *)busSeats, ROWS, COLS); // Display the current seat layout
                break;
            case 2:
                printf("Enter row number (1-%d): ", ROWS);
                if (scanf("%d", &row) != 1) {
                    printf("Invalid input for row. Please enter a number.\n");
                    clearInputBuffer();
                    break; // Exit switch case, go to next loop iteration
                }
                printf("Enter column number (1-%d): ", COLS);
                if (scanf("%d", &col) != 1) {
                    printf("Invalid input for column. Please enter a number.\n");
                    clearInputBuffer();
                    break; // Exit switch case, go to next loop iteration
                }
                clearInputBuffer(); // IMPORTANT: Clear buffer after reading row and col

                // Call bookSeat function (adjusting to 0-indexed for the function)
                bookSeat((int *)busSeats, ROWS, COLS, row - 1, col - 1);
                break;
            case 3:
                printf("Enter row number (1-%d) to cancel: ", ROWS);
                if (scanf("%d", &row) != 1) {
                    printf("Invalid input for row. Please enter a number.\n");
                    clearInputBuffer();
                    break; // Exit switch case, go to next loop iteration
                }
                printf("Enter column number (1-%d) to cancel: ", COLS);
                if (scanf("%d", &col) != 1) {
                    printf("Invalid input for column. Please enter a number.\n");
                    clearInputBuffer();
                    break; // Exit switch case, go to next loop iteration
                }
                clearInputBuffer(); // IMPORTANT: Clear buffer after reading row and col

                // Call cancelSeat function (adjusting to 0-indexed for the function)
                cancelSeat((int *)busSeats, ROWS, COLS, row - 1, col - 1);
                break;
            case 4:
                printf("Exiting Bus Seat Reservation System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4); // Continue loop until user chooses to exit

    return 0; // Indicate successful program execution
}





