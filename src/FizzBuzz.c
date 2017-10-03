/* By: Paul Patryas
   Infamous FizzBuzz program */
 
#include <stdio.h>

int main() {

    for(int i=1; i < 100; i++) {
        // if divisible by 3 & 5, print FizzBuzz
        if(i % 5 == 0 && i % 3 == 0)
            printf("%d is FizzBuzz\n", i);
        // if divisible by 5, print Buzz
        else if(i % 5 == 0)
            printf("%d is Buzz\n", i);
        // if divisible by 3, print Fizz
        else if(i % 3 == 0)
            printf("%d is Fizz\n", i);
    }
    return 0;
}
