/* Name: Paul Patryas
   Another misc project
   Date: 24 Sep 2017 */

#include<stdio.h>

// declare cleanup function
void cleanInput();

// declare functions that takes pointers as parameters
float checkForNonNumericCharacters(int *a, float *b, char *c);
float checkPostiveNumbersWithBound(int *a, float *b, char *c);
void checkObservedDays();
void loopObservedDays(float *b);
void loopHowManyTrips(float *b);
void printResult(float *a, float *b);

int main() {


    checkObservedDays();

    return 0;

}

// initialize cleanup function
void cleanInput(void) {
    while (getchar()!='\n');
    return;
}
void checkObservedDays(){
    printf("How many days will you observe the landing crew?\n");
    int observed_days;
    char buffer;
    // initialize flag and assign it to the scanf function
    // store possible non numeric characters inputted by user
    int flag = scanf("%f%c", &observed_days, &buffer);
    checkForNonNumericCharacters(&flag, &observed_days, &buffer);
    checkPostiveNumbersWithBound(&flag, &observed_days, &buffer);
    loopObservedDays(&observed_days);
}

void loopObservedDays(float *b){
    float how_many_trips;
    char buffer;
    // out of do...while loop and into for loops
    for (int i = 0; i < *b; i++) {
        printf("\nHow many trips were completed in day #%d?\n", i+1);
        int flag = scanf("%f%c", &how_many_trips, &buffer);
        checkForNonNumericCharacters(&flag, &how_many_trips, &buffer);
        checkPostiveNumbersWithBound(&flag, &how_many_trips, &buffer);
        loopHowManyTrips(&how_many_trips);
    }

}

void loopHowManyTrips(float *b) {
    float trip_length, total, total_sum;
    char buffer;

    for (int j=0; j < *b; j++) {
        printf("How long was trip #%d in hours?\n", j+1);
        int flag = scanf("%f%c", &trip_length, &buffer);
        checkForNonNumericCharacters(&flag, &trip_length, &buffer);
        checkPostiveNumbersWithBound(&flag, &trip_length, &buffer);
        total += trip_length;
    }
    printResult(&total, &*b);
}

void printResult(float *a, float *b) {
    float average = *a / *b;
    printf("\nThe average time was %.2f hours.\n", average);
    *a = 0;
}

// function that takes pointers as parameters
float checkForNonNumericCharacters(int *a, float *b, char *c){
    do {
        if (*a != 2 || *c != '\n'){
            printf("Input error of non numeric characters. Please enter a positive number\n");
            cleanInput();
            *a = scanf("%f%c", &*b, &*c);
        }
        else
            break;
       }while(1); // continue do...while loop until false
    return *b;
}

// function that takes pointers as parameters
float checkPostiveNumbersWithBound(int *a, float *b, char *c){
    while(!(0 <= *b && *b <= 10)){
        printf("Please enter a positive number between 0 and 10\n");
        *a = scanf("%f%c", &*b, *&c);
        checkForNonNumericCharacters(&*a,&*b,&*c);
    }
    return *b;
}


