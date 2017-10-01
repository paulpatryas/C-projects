#include <stdio.h>
#include <stdbool.h>
// old project from June 2016

bool testArr(int arr1[], int arr2[]);
void printResult(bool);

int main() {
    int arr1[] = {14, 34, 1, 90, 23, 6, 39, 17, 18, 209};
    int arr2[] = {14, 34, 1, 100, 23, 6, 39, 17, 18, 209};

    puts("Array A\t\t Array B");
    for (int i = 0; i < 10; i++) {
        printf("%d\t\t%d\n", arr1[i], arr2[i]);
    }

    bool result = testArr(arr1, arr2);
    printResult(result);

    return 0;
}
bool testArr(int arr1[], int arr2[]) {
    for(int i=0; i<10; i++)
        if(arr1[i] != arr2[i]) {
            return false;
        }
            return true;
}
void printResult(bool tempResult) {
    puts("\nAre both arrays the same?");

    if(tempResult) {
        puts("Yes");
    }
    else
        puts("No");
}

