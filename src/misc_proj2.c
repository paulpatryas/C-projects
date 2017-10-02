/* Name: Paul Patryas
   Date: 20 Sep 2017 */

// preprocessor directive
#include <stdio.h>

// define constants
#define NEWGEAR 15
#define OLDGEAR 5

// declare function that takes a pointer as a parameter
option_menu(int *a);

int main() {

    // variable declarations
    int option;
    int new_pieces_gear, old_pieces_gear = 0;
    float total = 0;

    // Welcome message
    printf("Welcome to the market!");

    // call option menu and pass argument to function
    option_menu(&option);

    // continue while loop until user wants to quit
    while (option != 3) {

        switch (option) {
            // New Gear case
            case 1:
                printf("\nHow many pieces of new gear would you like to buy?\n");
                scanf("%d", &new_pieces_gear);
                total += new_pieces_gear * NEWGEAR;
                break;
            // Old Gear case
            case 2:
                printf("\nHow many pieces of old gear would you like to buy?\n");
                scanf("%d", &old_pieces_gear);
                total += old_pieces_gear * OLDGEAR;
                break;
            // Quit
            case 3:
                break;
            // Error case
            default:
                printf("\nSorry, %d is not a valid choice.\n", option);
                break;
        } // end switch

        // call option menu once again until user enters 3 to quit
        option_menu(&option);

    } // end of while loop

    // if total != 0, print everything as usual. else - print message without average
    if (total != 0) {

        // do simple calculations based on user input and print results
        float average_gear_cost = total / (new_pieces_gear + old_pieces_gear);
        printf("\nYour total cost is %.0f gold pieces.\n", total);
        printf("You obtained %d pieces of new gear and %d pieces of used gear.\n", new_pieces_gear, old_pieces_gear);
        printf("The cost per piece of gear is %.2f pieces of gold.\n", average_gear_cost);
    }
    else {

        // print with no average and 0 pieces of new and old gear if total == 0
        printf("\nYour total cost is %.0f gold pieces.\n", total);
        printf("You obtained %d pieces of new gear and %d pieces of used gear.\n", new_pieces_gear, old_pieces_gear);
    }

    return 0;
}

// function that takes a pointer as a parameter
option_menu(int *a) {

    // option menu for the user
    printf("\nWhat would you like to do?\n");
    printf(" 1. Buy New Gear.\n");
    printf(" 2. Buy Old Gear.\n");
    printf(" 3. Quit\n");

    scanf("%d", &*a);
}
