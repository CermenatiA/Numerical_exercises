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

        virtual std::array<double, 2> eval(double t, std::array<double, 2> y) const{
            std::array<double, 2> f;
            f.at(0) = y.at(1);
            f.at(1) = (-1.) * _g * sin(y.at(0)) / _l;
            return f;
        }

        double kinetic_E(double Omega) const {return 0.5*_l*_l*Omega*Omega;}
        double potential_E(double Theta) const {return _g*_l*(1. - cos(Theta));}
        double total_E(double Theta, double Omega) const {return kinetic_E(Omega) + potential_E(Theta);}

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
    output << Init_T << std::setw(24) << Init_Val.at(0) << std::setw(24) 
            << Init_Val.at(1) << std::setw(24) << F->kinetic_E(Init_Val.at(1)) 
            << std::setw(24) << F->potential_E(Init_Val.at(0)) << std::setw(24) 
            << F->total_E(Init_Val.at(0), Init_Val.at(1)) << std::endl;
    ODE_Solver Solver;
    while(Init_T <= 60.){
        Next_Val = Solver.system_2_D_solver_2_order(F, Init_T, Init_Val, T_step);
        Init_T = Init_T + T_step;
        Init_Val = Next_Val;
        output << Init_T << std::setw(24) << Init_Val.at(0) << std::setw(24) 
                << Init_Val.at(1) << std::setw(24) << std::setprecision(12) << F->kinetic_E(Init_Val.at(1)) 
                << std::setw(24) << std::setprecision(12) << F->potential_E(Init_Val.at(0)) 
                << std::setw(24) << std::setprecision(12) << F->total_E(Init_Val.at(0), Init_Val.at(1)) 
                << std::endl;
    }
    return 0;
}