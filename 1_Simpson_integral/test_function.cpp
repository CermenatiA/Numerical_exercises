#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "standard_functions.h"
#include "integrators.h"

#ifndef test_function_h_
#define test_function_h_

class Test_function : public Scalar_function {

    public:
        Test_function() {};
        ~Test_function() {};

        virtual double eval(double x) const { return pow(x, 4.) - 2. * x + 1.;}
};
#endif

int main(){
    std::ofstream output;
    output.open("results.dat");
    Integrator_1D Integral;
    auto F = std::make_shared<Test_function>();
    for(int i = 1; i < 17; i++){
        long int n = pow(2,i);
        double V = Integral.simpson_2_order(F, 0., 2., n );
        output << log10(pow(2,i)) << std::setw(24) << std::setprecision(16) << V << std::setw(24) << std::setprecision(16) << log10((pow((4.4 - V)/4.4 , 2.))) << std::endl;
    }
    return 0;
}

