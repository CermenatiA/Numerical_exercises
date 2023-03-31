#ifndef ODE_solver_h
#define ODE_solver_h

#include <iostream>
#include <memory>
#include <array>
#include "standard_functions.h"

class ODE_solver{
    public:
    
        ODE_solver();
        ~ODE_solver();

        double Simple_solver_1_order(const std::shared_ptr<scalar_function>& F, double x_0, double y_0, double delta_x) const;

        std::array<double, 2> System_2_D_solver_2_order(const std::shared_ptr<System_function_2D>& F, double x_0, std::array<double, 2> y_0, double delta_x) const;
};
#endif