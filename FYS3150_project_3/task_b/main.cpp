#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "../gaussianquadrature.h"

using namespace std;

double integrand(double u, double theta1, double phi1, double v, double theta2, double phi2);

int main()
{
    double const pi = 3.14159265359;

    int N = 10;
    double *theta = new double [N];
    double *phi = new double [N];
    double *r = new double [N+1];
    double *weightsTheta = new double [N];
    double *weightsPhi = new double [N];
    double *weightsR = new double [N+1];

    rootsLegendre(N, theta);
    weightsLegendre(N, weightsTheta, theta, 0, pi);
    rootsLegendre(N, phi);
    weightsLegendre(N, weightsPhi, phi, 0, 2*pi);
    gauss_laguerre(r, weightsR, N, 2);

    double theta1, theta2, dTheta1, dTheta2;
    double phi1, phi2, dPhi1, dPhi2;
    double u, v, du, dv;
    double integral = 0;
    for (int i=0; i<N; i++) {
        du      = weightsR[i+1];
        u       = r[i+1];
        for (int j=0; j<N; j++) {
            dv      = weightsR[j+1];
            v       = r[j+1];
            for (int k=0; k<N; k++) {
                dTheta1 = weightsTheta[k];
                theta1  = theta[k];
                for (int l=0; l<N; l++) {
                    dTheta2 = weightsTheta[l];
                    theta2  = theta[l];
                    for (int m=0; m<N; m++) {
                        dPhi1   = weightsPhi[m];
                        phi1    = phi[m];
                        for (int n=0; n<N; n++) {
                            dPhi2   = weightsPhi[n];
                            phi2    = phi[n];

                            integral += du*dv*dTheta1*dTheta2*dPhi1*dPhi2*integrand(u, theta1, phi1, v, theta2, phi2);
                        }
                    }
                }
            }
        }
    }
    double exact = 5*pi*pi/(16.0*16.0);
    cout << endl << "N          = " << N << endl << endl;
    cout <<         "Numeric    = " << integral << endl;
    cout <<         "Exact      = " << exact << endl;

    delete [] theta;
    delete [] weightsTheta;
    delete [] r;
    delete [] weightsR;
    delete [] phi;
    delete [] weightsPhi;

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
        return 1.0/(32*pow(alpha, 5))*sin(theta1)*sin(theta2)/r_12;
    }
}

