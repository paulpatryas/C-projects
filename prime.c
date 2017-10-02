/* By: Paul Patryas
 * C program to check whether a given number is prime or not
 * and output the given number with a suitable message.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    // declare variables
    int num, j, flag;

    printf("Enter a number \n");
    scanf("%d", &num);

    if (num <= 1) {
        printf("%d is not a prime numbers \n", num);
        exit(1);
    }
    // check whether user input is prime or not
    flag = 0;
    for (j = 2; j <= num / 2; j++) {
        if ((num % j) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%d is a prime number \n", num);
     else
        printf("%d is not a prime number \n", num);
    return 0;
}
