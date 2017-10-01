#include <stdio.h>
#include <stdbool.h>
// old project from 2016
void getLargest(int *tempRange, int *tempMax, int *tempFreq);
void printResult(int, int);

int main() {

    int range, max = 0, frequency = 0;
    fputs("Please enter a range of numbers: ", stdout);
    scanf("%d", &range);

    fputs("Enter each number one by one: ", stdout);

    getLargest(&range, &max, &frequency);

    printResult(max, frequency);

    return 0;
}
void getLargest(int *tempRange, int *tempMax, int *tempFreq) {
    for(int i=0; i < *tempRange; i++) {
        int num;
        scanf("%d", &num);
        if(num > *tempMax) {
            *tempMax = num;
            *tempFreq = 1;
        }
        else if(num == *tempMax) {
            *tempFreq += 1;
        }
    }
}
void printResult(int max, int freq) {
    printf("The largest number is %d and was entered %d time(s).", max, freq);
}
