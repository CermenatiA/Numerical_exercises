#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "standard_functions.h"
#include "integrators.h"

#ifndef test_function_h_
#define test_function_h_

class test_function : public scalar_function {

    public:
        test_function() {};
        ~test_function() {};

        virtual double Eval(double x) const { return pow(x, 4.) - 2. * x + 1.;}
};
#endif

int main(){
    std::ofstream output;
    output.open("results.dat");
    integrator_1D Integral;
    auto F = std::make_shared<test_function>();
    for(int i = 1; i < 21; i++){
        output << i << std::setw(12) << Integral.Simpson_2_order(F, 0., 2., pow(2, i) ) << std::endl;
    }
    return 0;
}