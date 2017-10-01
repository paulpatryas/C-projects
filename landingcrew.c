/* Name: Paul Patryas
   Course number: Introduction to C Programming - COP3223
   Section number: 17 Fall 0R04 - Online
   Assignment: Project 4
   Date: 24 Sep 2017 */

// preprocessor directive
#include<stdio.h>

// declare cleanup function
void cleanInput();

// declare function that takes pointers as parameters
float check_input(int *a, float *b, char *c);

int main() {

    // variable declarations
    int i, j, flag, day_counter = 0;
    char buffer;
    float observed_days, how_many_trips, trip_length, total, average;

    printf("How many days will you observe the landing crew?\n");

    // initialize flag and assign it to the scanf function
    // store possible non numeric characters inputted by user
    flag = scanf("%f%c", &observed_days, &buffer);

    // pass arguments to function
    check_input(&flag, &observed_days, &buffer);


    // out of do...while loop and into for loops
    for (i=0; i < observed_days; i++) {
        printf("\nHow many trips were completed in day #%d?\n", i+1);
        // store flag as input for next for loop and check_input function
        flag = scanf("%f%c", &how_many_trips, &buffer);
        // pass arguments to function
        check_input(&flag, &how_many_trips, &buffer);

            // for loop asking for each trip_length and adding to total
            for (j=0; j < how_many_trips; j++) {
                printf("How long was trip #%d?\n", j+1);
                // store flag as input for check_input function
                flag = scanf("%f%c", &trip_length, &buffer);
                // pass arguments to function
                check_input(&flag, &trip_length, &buffer);
                // total = total + trip_length
                total += trip_length;
            }
        // once out of 2nd for loop, do simple calculations for average and go back to 1st for loop
        average = total / how_many_trips;
        // print out average for each Day#, reset total to zero, and increment day_counter by 1
        printf("\nDay #%d: The average time was %.3f.\n", day_counter + 1, average);
        total = 0;
        day_counter++;

    } // run main for loop until false and then quit program


    return 0;

}

// initialize cleanup function
void cleanInput(void) {
    while (getchar()!='\n');
    return;
}

// function that takes pointers as parameters
float check_input(int *a, float *b, char *c) {

    /* do...while loop checking user input
    if user input are characters or non-positive numbers, loop it
    if user input is a positive number from the start: go to else statement, which breaks do...while loop and returns a float value
    proceed to for loops in main(). Repeat do...while loop if user inputs an error in for loops */

    do {
        // checks user input for non-numeric characters or a mix of numeric and non-numeric characters
        if (*a != 2 || *c != '\n') {
            // prints out an error message for the user to enter a positive number
            printf("Input error of non numeric characters. Please enter a positive number\n");
            // cleans input from terminal or else the do...while loop will run indefinitely for non numeric characters entered
            cleanInput();
            // stores user input as a flag
            *a = scanf("%f%c", &*b, &*c);
        }
        // checks user input for a negative number
        else if (*b <= 0) {
            printf("You either entered a negative number or zero. Please enter a positive number\n");
            // stores user input as a flag
            *a = scanf("%f%c", &*b, &*c);
            // pass arguments to function and start from scratch
            check_input(&*a, &*b, &*c);
        }
        // if user input is a positive number -> break do...while loop, if not -> continue do...while loop
        else {
            break;
        }
    } while(1); // continue do...while loop until false

    // return float value *this is the input the user entered for each question*
    return *b;
}


