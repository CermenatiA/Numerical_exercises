#ifndef Non_linear_pendulum_h
#define Non_linear_pendulum_h

#include <iostream>
#include <memory>
#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>

#include "standard_functions.h"
#include "ODE_solver.h"

class Non_linear_pendulum: public System_function_2D {
    public:
        Non_linear_pendulum() {}
        ~Non_linear_pendulum() {}

        virtual std::array<double, 2> Eval(double t, std::array<double, 2> y) const{
            std::array<double, 2> f;
            f.at(0) = y.at(1);
            f.at(1) = (-1.) * _g * sin(y.at(0)) / _l;
            return f;
        }

        double Kinetic_E(double Omega) const {return 0.5*_l*_l*Omega*Omega;}
        double Potential_E(double Theta) const {return _g*_l*(1. - cos(Theta));}
        double Total_E(double Theta, double Omega) const {return Kinetic_E(Omega) + Potential_E(Theta);}

    protected:
        double _g = 9.8;
        double _l = 0.1;
};
#endif

int main(){
    std::ofstream output;
    output.open("results.dat");
    std::array<double, 2> Init_Val;
    std::array<double, 2> Next_Val;
    Init_Val.at(0) = M_PI * 179. / 180.;
    Init_Val.at(1) = 0.;
    double Init_T = 0.;
    double T_step = 0.0001;
    auto F = std::make_shared<Non_linear_pendulum>();
    output << Init_T << std::setw(12) << Init_Val.at(0) << std::setw(12) << Init_Val.at(1) << std::setw(12) << F->Kinetic_E(Init_Val.at(1)) << std::setw(12) << F->Potential_E(Init_Val.at(0)) << std::setw(12) << F->Total_E(Init_Val.at(0), Init_Val.at(1)) << std::endl;
    ODE_solver Solver;
    while(Init_T <= 10.){
        Next_Val = Solver.System_2_D_solver_2_order(F, Init_T, Init_Val, T_step);
        Init_T = Init_T + T_step;
        Init_Val = Next_Val;
        output << Init_T << std::setw(16) << Init_Val.at(0) << std::setw(16) << Init_Val.at(1) << std::setw(16) << F->Kinetic_E(Init_Val.at(1)) << std::setw(16) << F->Potential_E(Init_Val.at(0)) << std::setw(16) << F->Total_E(Init_Val.at(0), Init_Val.at(1)) << std::endl;
    }
    return 0;
}