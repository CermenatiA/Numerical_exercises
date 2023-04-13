#ifndef ODE_solver_h
#define ODE_solver_h

#include <iostream>
#include <memory>
#include <array>
#include "standard_functions.h"

class ODE_Solver{
    public:
    
        ODE_Solver();
        ~ODE_Solver();

        double simple_solver_1_order(const std::shared_ptr<Scalar_function>& F, double x_0, double y_0, double delta_x) const;

        std::array<double, 2> system_2_D_solver_2_order(const std::shared_ptr<System_function_2D>& F, double x_0, std::array<double, 2> y_0, double delta_x) const;
};
#endif