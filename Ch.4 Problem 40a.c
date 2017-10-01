#include <stdio.h>
// old project from 2016
#define INCOMETAX .125
#define FEDERALTAX .25
#define STATETAX .10
#define RETIREMENT .08

void calculatePayroll(int *s, int *b);
void printPayroll(int *x, int *y, float, float, float, float, float, float);


int main() {
    int sales, bonus;

    fputs("Please enter the total sales for employee: ", stdout);
    scanf("%d", &sales);
    fputs("Now enter the bonus for the employee: ", stdout);
    scanf("%d", &bonus);

    calculatePayroll(&sales, &bonus);

    return 0;
}
void calculatePayroll(int *s, int *b) {
    float income, federalTax, stateTax, retirement, deductions, finalIncome;

    income = (*s + *b) * INCOMETAX;
    federalTax = income * FEDERALTAX;
    stateTax = income * STATETAX;
    retirement = income * RETIREMENT;
    deductions = (federalTax + stateTax + retirement);
    finalIncome = income - deductions;

    printPayroll(s, b, income, federalTax, stateTax, retirement, deductions, finalIncome);
}
void printPayroll(int *x, int *y, float inc, float fed, float state, float retire, float deduct, float finl) {
    printf("Sales: $%d\n Bonus: $%d\n Income: $%.2f\n Federal Tax: $%.2f\n State Tax: $%.2f\n Retirement: $%.2f\n Deductions: $%.2f\n Final Income: $%.2f\n",
            *x, *y, inc, fed, state, retire, deduct, finl);
}

