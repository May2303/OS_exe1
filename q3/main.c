#include <stdio.h>
#include "poisson.h" // include this lib to linked the func poisson

int main() {
    //lamdas array that hold all the lamda value 
    long double lamdas[] = {1.0, 2.0, 2.0, 3.0, 3.0};
    int k[] = {1, 2, 10, 2, 100};
    int i;
    for (i = 0; i < 5; i++) { //for every line in the library
        printf("K: %d, lamda: %.2Lf , Value %d: %.20Lf\n", k[i],lamdas[i], i + 1, poisson(k[i], lamdas[i]));
    }
    return 0;
}
