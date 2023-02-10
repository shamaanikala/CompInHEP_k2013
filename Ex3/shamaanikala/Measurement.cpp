#include <iostream>
#include <cmath>
#include "Measurement.hpp"

void Measurement::setErrorMatrix(double pvar_x, double pvar_y, double pcov_xy) {
    var_x = pvar_x;
    var_y = pvar_y;
    cov_xy = pcov_xy;
}

void Measurement::setErrorMatrix(Measurement p) {
    var_x = p.var_x;
    var_y = p.var_y;
    cov_xy = p.cov_xy;
}

void Measurement::printErrorMatrix() {
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout<<"|"<<var_x<<" | "<<cov_xy<<"|"<<std::endl;
    std::cout<<"|"<<cov_xy<<" | "<<var_y<<"|"<<std::endl;
}

double Measurement::calculateError() {
    // calculates the error in distance
    // virhex = varx = std_x^2
    // lasketaan r = sqrt(x*x+y*y) virhe
    // dr/dx = 0.5*sqrt(x*x+y*y)^(-1)*2x = x/r
    // dr/dy = 0.5*sqrt(x*x+y*y)^(-1)*2y = y/r
    // virhe r = sqrt((x/r*virhex)^2 + (y/r*virhex)^2)
    // = sqrt(x^2*virhex^2 + y^2*virhey^2)/r
    //return M_11*x + M_12*y + M_21*x + M_22*y;

    // TODO: Add opt error calculation with covariance

    double error_x = var_x;
    double error_y = var_y;
    return sqrt(x*x*error_x*error_x + y*y*error_y*error_y)/distance();
}

double Measurement::calculateSignifigance() {
    return distance()/calculateError();
}