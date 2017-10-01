#include <stdio.h>
#include <stdlib.h>
// old project from 2016
void getCalculatedAge();
void cleanInput();

int main() {
    char do_over;
    do{
        system("CLS"); // clear the screen if user chooses yes
        getCalculatedAge();
        printf("Would you like to continue? (Y/N)");
        scanf("%c", &do_over);
        getchar();
    }while(do_over == 'Y' || do_over == 'y');
}
void getCalculatedAge() {
    float second, minute, hour, day, year, return_age, age_hours, age_days, age_years, age_seconds;
    char buffer;  // Holds last character from user input.
                  // (i.e '\n' or any other character besides numbers)
    char do_over;
    int flag;
    second = 1;
    minute = 60 * second;
    hour = 60 * minute;
    day = 24 * hour;
    year = 365 * day;

    printf("This is an age calculator program displaying your age in days, hours, \n"
           "and seconds.\n");
    printf("How old are you? ");

    flag = scanf("%f%c", &age_years, &buffer); // Gets input from user
    // While scanf did not read 2 objects (i.e 1 int & 1 char)
    // or the user inputed a number and then a character (eg. 12te)
    // ask user to type a valid value
        while (flag != 2 || buffer != '\n') {
            cleanInput(); // cleans user input if user types anything but an integer
            printf("%s","You have typed non numeric characters.\n"
                    "Please type a number between 1 and 120: ");
            flag = scanf("%f%c", &age_years, &buffer);
        }
            if(age_years > 0) {
                age_days = (age_years * year) / day;
                age_hours = (age_years * year) / hour;
                age_seconds = year * age_years;
                printf("You have lived for %.2f days or %.2f hours or %e seconds!\n", age_days, age_hours, age_seconds);
            }
            else {
                printf("User inputted a negative number. Quitting.\n");
            }
}
void cleanInput(void){
    while (getchar()!='\n');
    return;
}
