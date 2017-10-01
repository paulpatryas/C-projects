// old project from 2016

#include <stdio.h>

int getAverag(int);

int main() {

    int num;

    fputs("Please enter the range of numbers to find the average: ", stdout);
    scanf("%d", &num);

    float result = getAverage(num);

    printf("The average is: %.2f", result);

    return 0;
}
int getAverage(int tempNum) {
    float avg, sum = 0;
    for(int i=0; i<tempNum; i++) {
        float number;
        scanf("%f", &number);
        sum += number;
    }
    avg = sum / tempNum;
    return avg;
}
