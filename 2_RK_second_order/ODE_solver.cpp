#include <iostream>
#include <memory>

#include "standard_functions.h"
#include "ODE_solver.h"

ODE_Solver::ODE_Solver() {}

ODE_Solver::~ODE_Solver() {}

double ODE_Solver::simple_solver_1_order(const std::shared_ptr<Scalar_function>& F, double x_0, double y_0, double delta_x) const {
    return y_0 + delta_x * F->eval(x_0 + delta_x/2.);
}

std::array<double, 2> ODE_Solver::system_2_D_solver_2_order(const std::shared_ptr<System_function_2D>& F, double x_0, std::array<double, 2> y_0, double delta_x) const {
    std::array<double, 2> k1 = F->eval(x_0, y_0);
    k1.at(0) = k1.at(0) * delta_x / 2. + y_0.at(0);
    k1.at(1) = k1.at(1) * delta_x / 2. + y_0.at(1);
    std::array<double, 2> y_next = F->eval(x_0 + delta_x / 2., k1);
    y_next.at(0) = y_next.at(0) * delta_x + y_0.at(0);
    y_next.at(1) = y_next.at(1) * delta_x + y_0.at(1);
    return y_next;
}