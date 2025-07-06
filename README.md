# my1stProject

Bus Seat Reservation System (C Language)
This is a simple command-line application written in C that simulates a real-time bus seat reservation system. 
Users can view the current seat layout, book available seats, and cancel existing bookings. 
The system uses a 2D array to represent the bus seating, and pointer arithmetic is employed for efficient seat navigation.

Features
Seat Layout Representation: Uses a ROWS x COLS 2D integer array to represent the bus seats.

Seat States: 
Seats are marked as SEAT_EMPTY (0) or SEAT_BOOKED (1).

Pointer Arithmetic: 
All seat operations (initialization, display, booking, cancellation) are performed using pointers and pointer arithmetic for direct memory access.

Menu-Driven Interface: 
Provides a user-friendly menu for easy interaction.

Input Validation: 
Basic input validation is included to handle non-numeric inputs and out-of-bounds seat selections.

Modular Design: 
The code is separated into header (.h) and source (.c) files for better organization and reusability.

Files
main.c: Contains the main function, which handles the user interface, menu display, and calls to the seat reservation functions.

seat_reservation.h: Declares constants (like ROWS, COLS, SEAT_EMPTY, SEAT_BOOKED) and function prototypes for the seat reservation logic.

seat_reservation.c: Implements the core functions for seat management:

initializeSeats(): Sets all seats to available.

displaySeats(): Shows the current status of all seats (O for empty, X for booked).

bookSeat(): Attempts to book a seat at specified coordinates.

cancelSeat(): Attempts to cancel a seat at specified coordinates.

Makefile: A build script to automate the compilation and linking process.

How to Compile
To compile the program, you will need a C compiler (like GCC) installed on your system.

Navigate to the project directory: Open your terminal or command prompt and go to the directory where you have saved all the project files (main.c, seat_reservation.c, seat_reservation.h, Makefile).

Run make:

make

The Makefile will compile the source files and link them to create an executable named bus_reservation.exe (on Windows) or bus_reservation (on Linux/macOS).

How to Run
After successful compilation, you can run the program from your terminal:

./bus_reservation.exe   # For Windows
./bus_reservation       # For Linux/macOS

The program will display a menu, and you can follow the prompts to interact with the seat reservation system.

Cleaning Up
To remove all compiled object files (.o) and the executable, you can use the clean target in the Makefile:

make clean

Program Reset Behavior
The seat reservation system's state (all bookings) is reset every time the program starts. This is because the seat layout is initialized in memory when the main function begins execution. Once the program exits, all its in-memory data is cleared.
