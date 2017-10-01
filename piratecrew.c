/* Name: Paul Patryas
   Course number: Introduction to C Programming - COP3223
   Section number: 17 Fall 0R04 - Online
   Assignment: Project 2 
   Date: 03 Sep 2017 */


// preprocessor directive
#include <stdio.h>

// define constant
#define SWIM_LIMIT 100

// declare function that takes pointers as parameters
print_result(char *a, char *b, int *c);


int main() {

    // variable declarations
    int swim_meter;
    char digging_treasure, able_swim;

    // user input
    printf("Do you like digging for treasure?(Y/N)\n");
    scanf(" %c", &digging_treasure);

    // user input
    printf("Are you able to swim?(Y/N)\n");
    scanf(" %c", &able_swim);

    // if user answered 'Y' to being able to swim, ask how many meters
    if(able_swim == 'Y') {
        printf("How many meters are you able to swim?\n");
        scanf("%d", &swim_meter);
    }

    // pass arguments to function
    print_result(&digging_treasure, &able_swim, &swim_meter);

    return 0;

}

// function that takes pointers as parameters
print_result(char *a, char *b, int *c) {

    // declare and initialize temp variables to pointers for easier reading
    char tempA = *a, tempB = *b;
    int tempC = *c;

    // if user answered 'Y' to both questions and swim_meter >= SWIM_LIMIT, join crew
    if (tempA == 'Y' && tempB == 'Y' && tempC >= SWIM_LIMIT)
        printf("You may join the pirate crew! Arr!\n");

    // else, cannot join crew
    else
        printf("You may not join the crew.\n");
}
