#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function to calculate the Poisson distribution
   Calculate the Poisson probability using the formula:
     P(X = k) = (e^(-lamda) * lamda^k) / k!
     where:
       e is approximately 2.71828
       lamda is the average rate of occurrences
       k is the number of occurrences
*/
long double poisson(double lamda, int k) {
    return expl(-lamda) * powl(lamda, k) / tgamma(k + 1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {// Check if arguments is correct
        printf("you have missig aruments!\n");
        return 1;
    }

    //create long double var:
    long double lamda = strtold(argv[1], NULL);// Convert arguments to right types
    int k = atoi(argv[2]);// k is the second arg

    
    long double result = poisson(lamda, k);// calculate the Poisson distribution

    
    printf("%.20Lf\n", result);// print result, 20 points after the dot

    return 0;
}
