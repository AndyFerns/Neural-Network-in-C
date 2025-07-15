#include <stdlib.h>
#include <math.h>

// activation function (sigmoid)
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoidDerivative(double x) {
    double s = sigmoid(x);
    return (s * (1 - s));
}

double randWeight() {
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Random in [-1,1] 
}
