#include <iostream>
#include <fstream>
#include <memory>
#include <array>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#include "standard_functions.h"
#include "Spatial_grids.h"
#include "PDE_solver.h"

class Injection_function: public Scalar_function {
    public:
    Injection_function(){};
    ~Injection_function(){};
    virtual double eval(double x) const {
        return (M_PI*M_PI*0.1/4.)*cos(M_PI*x/2.);
    }
};

class Initial_condition : public Scalar_function {
    public:
        Initial_condition(){};
        ~Initial_condition(){};
        virtual double eval(double x) const {
            return (1./10.)*cos(M_PI*x/2.);
        }
};

int main(){
    auto Q = std::make_shared<Injection_function>();
    auto F = std::make_shared<Initial_condition>();
    Diffusion_1_D Solver = Diffusion_1_D();
    Solver.set_diffusion_coefficient(0.1);
    double T_0 = 0.;
    double T_max = 50.;
    int T_points = 5000000;
    double delta_T = (T_max - T_0)/double(T_points);
    {
    auto Grid = std::make_shared<Spatial_grid_1D>(pow(2,8), -1., 1., 0., 0.);
    Grid->set_initial_condition(F);
    for(int i = 0; i <= T_points; i++){
        if(i % int(T_points/10) == 0){
            std::string s = std::to_string(T_0 + double(i)*delta_T);
            std::ostringstream ss;
            ss << "results_impl/numerical_solution_8_t_" << s << ".dat";
            std::string name = ss.str();
            Grid->save_grid(name);
        }
        Solver.implicit_Crank_Nicholson(Grid, Q, delta_T);
        Grid->reset_grid();
    }
    }
    std::cout<<"finish 8"<<std::endl;
    {
    auto Grid = std::make_shared<Spatial_grid_1D>(pow(2,9), -1., 1., 0., 0.);
    Grid->set_initial_condition(F);
    for(int i = 0; i <= T_points; i++){
        if(i % int(T_points/10) == 0){
            std::string s = std::to_string(T_0 + double(i)*delta_T);
            std::ostringstream ss;
            ss << "results_impl/numerical_solution_9_t_" << s << ".dat";
            std::string name = ss.str();
            Grid->save_grid(name);
        }
        Solver.implicit_Crank_Nicholson(Grid, Q, delta_T);
        Grid->reset_grid();
    }
    }
    std::cout<<"finish 9"<<std::endl;
    {
    auto Grid = std::make_shared<Spatial_grid_1D>(pow(2,10), -1., 1., 0., 0.);
    Grid->set_initial_condition(F);
    for(int i = 0; i <= T_points; i++){
        if(i % int(T_points/10) == 0){
            std::string s = std::to_string(T_0 + double(i)*delta_T);
            std::ostringstream ss;
            ss << "results_impl/numerical_solution_10_t_" << s << ".dat";
            std::string name = ss.str();
            Grid->save_grid(name);
        }
        Solver.implicit_Crank_Nicholson(Grid, Q, delta_T);
        Grid->reset_grid();
    }
    }
    return 0;
}