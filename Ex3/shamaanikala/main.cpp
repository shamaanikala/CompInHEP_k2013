#include <iostream>
#include "Measurement.hpp"

int main() {
    Measurement m(1.0,2.0);
    std::cout<<"Measurement: ("<<m.getX()<<","<<m.getY()<<")"<<std::endl;
    std::cout<<"Distance: "<<m.distance()<<std::endl;

    std::cout<<"--------------"<<std::endl;

    std::cout<<"Error without setting up the error matrix: "<<m.calculateError()<<std::endl;
    std::cout<<"Error matrix:"<<std::endl;
    m.printErrorMatrix();

    std::cout<<"--------------"<<std::endl;

    std::cout<<"Setting up the error matrix..."<<std::endl;
    
    
    m.setErrorMatrix(0.05,0.04,0.10);
    m.printErrorMatrix();

    std::cout<<"--------------"<<std::endl;
    
    std::cout<<"Calculating the error..."<<std::endl;
    std::cout<<"Error: "<<m.calculateError()<<std::endl;
    std::cout<<"Signifigance: ";
    std::cout<<m.calculateSignifigance()<<std::endl;

    std::cout<<"--------------"<<std::endl;

    std::cout<<"Setting up another measurement object..."<<std::endl;
    Measurement n(0.98,0.76);
    std::cout<<"Another measurement: ("<<n.getX()<<","<<n.getY()<<")"<<std::endl;
    std::cout<<"Distance: "<<n.distance()<<std::endl;
    std::cout<<"Setting up diag(1,1) as error matrix for the new measurement..."<<std::endl;
    n.setErrorMatrix(1.0,1.0,0.0);
    std::cout<<"Error matrix now:"<<std::endl;
    n.printErrorMatrix();
    std::cout<<"--------------"<<std::endl;
    
    std::cout<<"Calculating the error..."<<std::endl;
    std::cout<<"Error: "<<n.calculateError()<<std::endl;
    std::cout<<"Signifigance: ";
    std::cout<<n.calculateSignifigance()<<std::endl;

    std::cout<<"--------------"<<std::endl;

    std::cout<<"Setting up the error matrix from the first measurement..."<<std::endl;
    n.setErrorMatrix(m);
    n.printErrorMatrix();

    std::cout<<"--------------"<<std::endl;
    
    std::cout<<"Calculating the error..."<<std::endl;
    std::cout<<"Error: "<<n.calculateError()<<std::endl;
    std::cout<<"Signifigance: ";
    std::cout<<n.calculateSignifigance()<<std::endl;
    return EXIT_SUCCESS;
}