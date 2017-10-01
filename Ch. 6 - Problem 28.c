#include <stdio.h>
#include <stdbool.h>

// declare bool function prototype
bool array(int arr1[], int arr2[]);
void getResults(bool);

int main() {

    int array1[] = {90, 61, 77, 201, 503, 35, 900, 190, 10, 23};
    int array2[] = {90, 61, 77, 21, 503, 35, 900, 190, 10, 23};

    puts("Array A\t\t Array B\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t\t%d\n", array1[i], array2[i]);
    }
        // pass both arrays into bool function
        bool result = array(array1, array2);

        // print out the results
        getResults(result);


    return 0;
}

// compare both arrays and determine if they are both the same or not
bool array(int arr1[], int arr2[]) {

    for (int i = 0; i < 10; i++)
        if (arr1[i] != arr2[i]) {
            return false;
        }
            return true;
}

// pass bool result and print out yes or no
void getResults(bool tempResult) {
    puts("\nAre both arrays the same?");
    if (tempResult == 1) {
        puts("Yes");
    }
    else {
        puts("No");
    }
}
