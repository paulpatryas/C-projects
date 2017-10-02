/* By: Paul Patryas
Date: 27 Aug 2017 */

// preprocessor directive
#include <stdio.h>

// define constants
#define KILOMETERS_TO_SPAIN 7228
#define ORANGES_PER_CREW_MEMBER 0.5

// declare functions that takes pointers as parameters
void calculate_and_print(float *a, float *b);
float checkForNonNumericCharacters(int *a, float *b, char *c);
float checkForPostiveNumbers(int *a, float *b, char *c);

// declare cleanup function
void cleanInput(void);

int main() {

    // declare variables
    float how_many_kilometers_perDay, how_many_crewMembers, trip_length, total_oranges;
    char buffer;

    // asks user for input
    printf("How many kilometers can your ship travel in one day?\n");

    // declare and initialize flag and assign it to the scanf function
    // store possible non numeric characters inputted by user
    int flag = scanf("%f%c", &how_many_kilometers_perDay, &buffer);

    // pass arguments to function
    checkForNonNumericCharacters(&flag, &how_many_kilometers_perDay, &buffer);
    checkForPostiveNumbers(&flag, &how_many_kilometers_perDay, &buffer);

    // asks user for input
    printf("\nHow many crew members can your ship hold?\n");

    // initialize flag and assign it to the scanf function once again
    // store possible non numeric characters inputted by user
    flag = scanf("%f%c", &how_many_crewMembers, &buffer);

    // pass arguments to function
    checkForNonNumericCharacters(&flag, &how_many_crewMembers, &buffer);
    checkForPostiveNumbers(&flag, &how_many_crewMembers, &buffer);

    // initialize variables and assign it by conversion of constants and user input using arithmetic
    trip_length = KILOMETERS_TO_SPAIN / how_many_kilometers_perDay;
    total_oranges = ORANGES_PER_CREW_MEMBER * how_many_crewMembers;

    // passes trip_length and total_oranges_needed as arguments to function
    calculate_and_print(&trip_length, &total_oranges);

    return 0;
}

// initialize cleanup function
void cleanInput() {

    while (getchar()!='\n');
    return;
}

// initialize function that takes pointers as parameters
// calculates result of how many total oranges needed when two positive numbers are inputted to both questions in main()
void calculate_and_print(float *a, float *b) {

    // declare and initialize a float value and assign it to the product of the pointers
    float total_oranges_needed = (*a) * (*b);
    // prints out the result up to two decimal places
    printf("\nYou will need %.2f oranges to make the trip!\n", total_oranges_needed);
}

// function that takes pointers as parameters
float checkForNonNumericCharacters(int *a, float *b, char *c){
    do {
        // checks user input for non-numeric characters or a mix of numeric and non-numeric characters
        if (*a != 2 || *c != '\n'){
            // prints out an error message for the user to enter a positive number
            printf("Input error of non numeric characters. Please enter a positive number\n");
            // cleans input from terminal or else the do...while loop will run indefinitely for non numeric characters entered
            cleanInput();
            // stores user input as a flag
            *a = scanf("%f%c", &*b, &*c);
        }
        else
            break;
       }while(1); // continue do...while loop until false

    return *b; // return float value *this is the input the user entered for the question*}
}

float checkForPostiveNumbers(int *a, float *b, char *c){
    // checks user input if it is in range of lower bound, if not, ask user to enter correct lower bound
    while(*b <= 0){
        printf("Please enter a positive number\n");
        // stores user input as a flag
        *a = scanf("%f%c", &*b, *&c);
        // pass arguments to function and check for non-numeric characters again
        checkForNonNumericCharacters(&*a,&*b,&*c);
    }
    // return float value *this is the input the user entered for the question*
    return *b;
}
