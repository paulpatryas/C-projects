/* Name: Paul Patryas
   Date: 24 Sep 2017 */

// preprocessor directive
#include<stdio.h>

// declare cleanup function
void cleanInput();

// declare function that takes pointers as parameters
float checkForNonNumericCharacters(int *a, float *b, char *c);

// declare function that takes pointers as parameters
float checkPostiveNumbersWithBound(int *a, float *b, char *c);

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
    checkForNonNumericCharacters(&flag, &observed_days, &buffer);
    checkPostiveNumbersWithBound(&flag, &observed_days, &buffer);


    // out of do...while loop and into for loops
    for (i=0; i < observed_days; i++) {
        printf("\nHow many trips were completed in day #%d?\n", i+1);
        // store flag as input for next for loop and check_input function
        flag = scanf("%f%c", &how_many_trips, &buffer);
        // pass arguments to function
        checkForNonNumericCharacters(&flag, &how_many_trips, &buffer);
        checkPostiveNumbersWithBound(&flag, &how_many_trips, &buffer);

            // for loop asking for each trip_length and adding to total
            for (j=0; j < how_many_trips; j++) {
                printf("How long was trip #%d in hours?\n", j+1);
                // store flag as input for check_input function
                flag = scanf("%f%c", &trip_length, &buffer);
                // pass arguments to function
                checkForNonNumericCharacters(&flag, &trip_length, &buffer);
                checkPostiveNumbersWithBound(&flag, &trip_length, &buffer);
                // total = total + trip_length
                total += trip_length;
            }
        // once out of 2nd for loop, do simple calculations for average and go back to 1st for loop
        average = total / how_many_trips;
        // print out average for each Day#, reset total to zero, and increment day_counter by 1
        printf("\nDay #%d: The average time was %.3f hours.\n", day_counter + 1, average);
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

// function that takes pointers as parameters
float checkPostiveNumbersWithBound(int *a, float *b, char *c){
    // checks user input if it is in range of defined bound of 0 and 10, if not, ask user to enter correct lower bound
    while(!(0 <= *b && *b <= 10)){
        printf("Please enter a positive number between 0 and 10\n");
        // stores user input as a flag
        *a = scanf("%f%c", &*b, *&c);
        // pass arguments to function and check for non-numeric characters again
        checkForNonNumericCharacters(&*a,&*b,&*c);
    }
    // return float value *this is the input the user entered for the question*
    return *b;
}



