// Programming exercise 2.3
#include <stdio.h>
int main(void)
{

    int second, minute, hour, day, year, age_hours, age_days, age_years, age_seconds;
    char buffer;
    second = 1;
    minute = 60 * second;
    hour = 60 * minute;
    day = 24 * hour;
    year = 365 * day;
    printf("This is an age calculator that displays your age in days, hours, and seconds.\n");
    printf("Please enter your age in numbers in the proceeding question and then hit Enter.\n");
    printf("How old are you?\n");
    scanf("%d%c", &age_years, &buffer);
    while (age_years < 0 || age_years > 120 || buffer!='\n')
    {
        printf("Please enter a number between 1 and 120\n"); // If age_years is greater than 120, infinite loop
        scanf("%d%c", &age_years, &buffer);

    }
    if (age_years == 120)   // age_years is equal to 120
    {
        age_hours = 365 * 24 * age_years;
        age_days = 365 * age_years;
        age_seconds = year * age_years;
        printf("Geez you're old...\n");
        printf("You have lived for %d days or %d hours or %u seconds!\n", age_days, age_hours, age_seconds);
    }
    else if (age_years != 0 && age_years < 120) // age_years is not zero AND less than 120
    {
        age_hours = 365 * 24 * age_years;
        age_days = 365 * age_years;
        age_seconds = year * age_years;
        printf("You have lived for %d days or %d hours or %u seconds!\n", age_days, age_hours, age_seconds);
    }
    else if (age_years == 0) // age_years is exactly zero
    {
        printf("Terminating program due to user error. Have a nice day!\n");
    }
    return 0;
}


