#include<iostream>
#include<cmath>  // For abs() function to check the stopping condition
using namespace std;

double func(double x) {
    return x * x * x - 3;  // The function f(x) = x^3 - 3
}

void fxn(double* a, double* b) {
    double valAta, valAtb, valAtMean;
    valAta = func(*a);  // Value of f(a)
    valAtb = func(*b);  // Value of f(b)
    double mean = (*a + *b) / 2;  // Midpoint
    valAtMean = func(mean);  // Value of f(mean)
    
    if (valAta * valAtMean < 0) {
        *b = mean;  // Update b
    } else {
        *a = mean;  // Update a
    }
}

int main() {
    double a = 1, b = 2;
    int it = 0;
    double tolerance = 0.0001;  // Desired tolerance for the root

    // Continue until the interval is smaller than the tolerance
    while (abs(b - a) > tolerance) {  
        fxn(&a, &b);
        it++;
    }

    cout << "Root lies between " << a << " and " << b << ".\n";
    cout << "Number of iterations: " << it << endl;

    return 0;
}
