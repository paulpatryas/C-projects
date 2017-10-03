/* Name: Paul Patryas
   Another misc project
   Date: 24 Sep 2017 */

#include<stdio.h>

// declare cleanup function
void cleanInput();

// declare functions that takes pointers as parameters
float checkForNonNumericCharacters(int *a, float *b, char *c);
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
    checkForNonNumericCharacters(&flag, &observed_days, &buffer);
    checkPostiveNumbersWithBound(&flag, &observed_days, &buffer);

    // out of do...while loop and into for loops
    for (i=0; i < observed_days; i++) {
        printf("\nHow many trips were completed in day #%d?\n", i+1);
        flag = scanf("%f%c", &how_many_trips, &buffer);
        checkForNonNumericCharacters(&flag, &how_many_trips, &buffer);
        checkPostiveNumbersWithBound(&flag, &how_many_trips, &buffer);

            // for loop asking for each trip_length and adding to total
            for (j=0; j < how_many_trips; j++) {
                printf("How long was trip #%d in hours?\n", j+1);
                flag = scanf("%f%c", &trip_length, &buffer);
                checkForNonNumericCharacters(&flag, &trip_length, &buffer);
                checkPostiveNumbersWithBound(&flag, &trip_length, &buffer);
                total += trip_length;
            }
        average = total / how_many_trips;
        printf("\nDay #%d: The average time was %.3f hours.\n", day_counter + 1, average);
        total = 0;
        day_counter++;

    }


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
        if (*a != 2 || *c != '\n'){
            printf("Input error of non numeric characters. Please enter a positive number\n");
            cleanInput();
            *a = scanf("%f%c", &*b, &*c);
            return *b;
        }
        else
            break;
       }while(1); // continue do...while loop until false
}

// function that takes pointers as parameters
float checkPostiveNumbersWithBound(int *a, float *b, char *c){
    while(!(0 <= *b && *b <= 10)){
        printf("Please enter a positive number between 0 and 10\n");
        *a = scanf("%f%c", &*b, *&c)'
        checkForNonNumericCharacters(&*a,&*b,&*c);
        return *b;
    }
}


