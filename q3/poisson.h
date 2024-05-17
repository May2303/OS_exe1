#include <math.h>

// function for calculating the Poisson distribution
// more explain about this func is in the folder q2
long double poisson(double lambda, int k) {
    return expl(-lambda) * powl(lambda, k) / tgamma(k + 1);
}


