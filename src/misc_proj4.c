/* Name: Paul Patryas
   Another misc project
   Date: 24 Sep 2017 */

#include<stdio.h>

// declare cleanup function
void cleanInput();

// declare functions that takes pointers as parameters
float checkForNonNumericCharacters(int *a, float *b, char *c);
float checkPostiveNumbersWithBound(int *a, float *b, char *c);
float checkObservedDays(float *a, char *b);
void loopObservedDays(float *a, char *b);
void loopHowManyTrips(float *b);
void printResult(float *a, float *b);

int main() {

    // initialize variables
    float observed_days;
    char buffer;

    printf("How many days will you observe the landing crew?\n");

    // call functions and pass arguments
    checkObservedDays(&observed_days, &buffer);
    loopObservedDays(&observed_days, &buffer);

    return 0;

}

// initialize cleanup function
void cleanInput(void) {
    while (getchar()!='\n');
    return;
}
// defensive programming function: checks for user errors
float checkObservedDays(float *a, char *b){
    int flag = scanf("%f%c", &*a, &*b);
    checkForNonNumericCharacters(&flag, &*a, &*b);
    checkPostiveNumbersWithBound(&flag, &*a, &*b);
    return *a;
}
// loop for observed days, defensive programming
void loopObservedDays(float *a, char *b){
    float how_many_trips, temp_ObservedDays = *a;
    for (int i = 0; i < temp_ObservedDays; i++) {
        printf("\nHow many trips were completed in day #%d?\n", i+1);
        int flag = scanf("%f%c", &how_many_trips, &*b);
        checkForNonNumericCharacters(&flag, &how_many_trips, &*b);
        checkPostiveNumbersWithBound(&flag, &how_many_trips, &*b);
        loopHowManyTrips(&how_many_trips);
    }
}
// loop for how many trips, defensive programming
void loopHowManyTrips(float *b) {
    float temp_how_many_trips = *b, trip_length, total; char buffer;
    for (int j=0; j < temp_how_many_trips; j++) {
        printf("How long was trip #%d in hours?\n", j+1);
        int flag = scanf("%f%c", &trip_length, &buffer);
        checkForNonNumericCharacters(&flag, &trip_length, &buffer);
        checkPostiveNumbersWithBound(&flag, &trip_length, &buffer);
        total += trip_length;
    }
    printResult(&total, &temp_how_many_trips);
}
// calculate average time and print out result
void printResult(float *a, float *b) {
    float tempTotal = *a, tempTripNumber = *b;
    float average = tempTotal / tempTripNumber;
    printf("\nThe average time was %.2f hours.\n", average);
    tempTotal = 0;
}
// check for non-numeric characters
float checkForNonNumericCharacters(int *a, float *b, char *c){
    while(*a != 2 || *c != '\n'){
        printf("Input error of non numeric characters. Please enter a positive number\n");
        cleanInput();
        *a = scanf("%f%c", &*b, &*c);
    }
    return *b;
}
// check for negative inputs by user
float checkPostiveNumbersWithBound(int *a, float *b, char *c){
    while(!(0 <= *b && *b <= 10)){
        printf("Please enter a positive number between 0 and 10\n");
        *a = scanf("%f%c", &*b, *&c);
        checkForNonNumericCharacters(&*a,&*b,&*c);
    }
    return *b;
}
