#ifndef MEASUREMENTHPP
#define MEASUREMENTHPP

#include <cmath>

class Measurement {
    private:
        const double x;
        const double y;
        // Error matrix elements
        // var_x^2 cov_xy
        // cov_xy var_y^2
        // Just using the matrix elements.
        // If an actual matrix object is needed
        // implment it with LAPACK or other
        double var_x; // \sigma_x^2 
        double var_y;
        double cov_xy; // symmetric matrix has identical off-diagonal terms
    public:
        Measurement(double x, double y) : x(x), y(y) {}
        Measurement(int x, int y) : x(double(x)), y(double(y)) {}
        double getX() const { return x; }
        double getY() const { return y; }
        void setErrorMatrix(double, double, double);
        void setErrorMatrix(Measurement);
        void printErrorMatrix();
        double distance() const { return sqrt(x*x + y*y); }
        double calculateError();
        double calculateSignifigance();
};
#endif