#include <iostream>
#include <cmath>
#include "../lib.h"
#include <omp.h>

using namespace std;

double integrand(double u, double theta1, double phi1, double v, double theta2, double phi2);


int main()
{
    double const pi = 3.14159265359;

    int N = 10000;
    double u, v, theta1, theta2, phi1, phi2;
    double fx;
    double mc_importance = 0;
    double sigma = 0;
    long idum = -1;


    for (int i=0; i < N; i++) {
        u = -log(1-ran0(&idum));
        v = -log(1-ran0(&idum));
        theta1 = pi*ran0(&idum);
        theta2 = pi*ran0(&idum);
        phi1 = 2*pi*ran0(&idum);
        phi2 = 2*pi*ran0(&idum);

        fx = integrand(u, theta1, phi1, v, theta2, phi2);
        mc_importance += fx;
        sigma += fx*fx;
    }

    double jacobidet = 4*pow(pi,4);
    mc_importance /= N;
    sigma /= N;
    double variance = sigma - mc_importance*mc_importance;
    double exact = 5*pi*pi/(16.0*16.0);
    mc_importance *= jacobidet;
    sigma *= jacobidet;
    cout << endl << "N          = " << N << endl;
    cout << endl << "Numeric    = " << mc_importance << endl;
    cout <<         "Exact      = " << exact << endl;
    cout <<         "Variance   = " << variance << endl;



    return 0;
}

double integrand(double u, double theta1, double phi1, double v, double theta2, double phi2)
{
    double alpha = 2;
    double cos_beta = cos(theta1)*cos(theta2) + sin(theta1)*sin(theta2)*cos(phi1-phi2);
    double r_12 = sqrt(u*u + v*v - 2*u*v*cos_beta);
    if (r_12 < 1e-6 || isnan(r_12)) {
        return 0;
    }
    else {
        return 1.0/(pow(2*alpha, 5))*sin(theta1)*sin(theta2)*u*u*v*v/r_12;
    }
}
