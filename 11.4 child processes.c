#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printOdds() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            printf("Odd: %d\n", i);
        }
    }
}

void printEvens() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        }
    }
}

void printMultiplesOf3() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            printf("Multiple of 3: %d\n", i);
        }
    }
}

void printMultiplesOf5() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 5 == 0) {
            printf("Multiple of 5: %d\n", i);
        }
    }
}

int main()
{
    ptinf("%d",printMultiplesOf5());
    return 0;
}
