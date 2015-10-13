#include <iostream>
#include "../gaussianquadrature.h"
#include <cmath>

using namespace std;

// f is the function to integrate
double integrand(double x1, double y1, double z1, double x2, double y2, double z2);

/* Need to change the functions which generate the roots and weights
 * so that they return all roots, not only upper ones. Remember
 * the roots and weights are symmetric.
 */


int main()
{
    int order = 10;
    double a = -10;
    double b = 10;
    double *roots = new double[order];
    double *weights = new double[order];

    rootsLegendre(order, roots);
    weightsLegendre(order, weights, roots);

    /* Calculating the mesh points and change the limits from x \in [-1,1] to t \in [a, b].
     * We have that
     *                          t = (b-a)/2*x + (b+a)/2
     * The weights are conserved.
     */
    double x[order];
    double xm = (b-a)/2;
    double xp = (b+a)/2;
    for (int i=0; i < order; i++) {
        x[i] = xm*roots[i]+xp;
    }

    // integrate:
    double integral = 0;
    for (int i=0; i < order; i++) {
        for (int j=0; j < order; j++) {
            for (int k=0; k < order; k++) {
                for (int l=0; l < order; l++) {
                    for (int m=0; m < order; m++) {
                        for (int n=0; n < order; n++) {
                            integral += weights[i]*weights[j]*weights[k]*weights[l]*weights[m]*weights[n]*
                                    integrand(x[i], x[j], x[k], x[l], x[m], x[n]);
                        }
                    }
                }
            }
        }
    }

    // a correction factor of (b-a)/2 is needed when changing the integraiton limits.
    integral *= xm;


    // for (int i=0; i < order; i++){ cout << weights[i] << "    " << roots[i] << endl; }

    double exact = 5*3.1415*3.1415/(16.0*16.0);
    cout << endl << "Exact      = " << exact << endl;
    cout << "Numeric    = " << integral << endl;
    cout << "rel Error  = " << fabs(integral - exact)/exact << endl;

    delete[] roots;
    delete[] weights;
    return 0;
}

// function to integrate
double integrand(double x1, double y1, double z1, double x2, double y2, double z2) {
    double alpha = 2;
    double exp1 = -2*alpha*sqrt(x1*x1 + y1*y1 + z1*z1);
    double exp2 = -2*alpha*sqrt(x2*x2 + y2*y2 + z2*z2);
    double deno = sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
    if(deno <pow(10.,-6.)) {
        return 0;
    }
    else {
        return exp(exp1+exp2)/deno;
    }
}
