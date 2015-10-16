#include <iostream>
#include <cmath>
#include "../lib.h"

using namespace std;

double integrand(double *x);


int main()
{
    int N = 1e5;
    int dim = 6;
    double x[dim];
    double a = -5; // lower integration limit
    double b = 5;  // upper integration limit

    long idum = -1;
    double crude_mc = 0;
    double sigma = 0;

    double fx;
    for (int i=0; i < N; i++) {
        for (int j = 0; j < dim; j++) {
            x[j] = a + (b-a)*ran0(&idum);
        }
        fx = integrand(x);
        crude_mc += fx;
        sigma += fx*fx;
    }

    double jacobidet = pow((b-a), dim);
    crude_mc /= N;
    sigma /= N;
    double variance = sigma - crude_mc*crude_mc;
    double const pi = 3.14159265359;
    double exact = 5*pi*pi/(16.0*16.0);
    crude_mc *= jacobidet;
    sigma *= jacobidet;
    cout << endl << "N          = " << N << endl;
    cout << endl << "Numeric    = " << crude_mc << endl;
    cout <<         "Exact      = " << exact << endl;
    cout <<         "Variance   = " << variance << endl;

    return 0;
}



double integrand(double *x)
{
    double x1 = x[0]; double y1 = x[1]; double z1 = x[2];
    double x2 = x[3]; double y2 = x[4]; double z2 = x[5];
    double alpha = 2;
    double exp1 = -2*alpha*sqrt(x1*x1 + y1*y1 + z1*z1);
    double exp2 = -2*alpha*sqrt(x2*x2 + y2*y2 + z2*z2);
    double deno = sqrt(pow((x1-x2),2) + pow((y1-y2),2) + pow((z1-z2),2));
    if (deno < pow(10,-6)) {
            return 0;
    }
    else {
        return exp(exp1+exp2)/deno;
    }
}

