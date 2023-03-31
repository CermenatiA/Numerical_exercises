#ifndef integrators_h
#define integrators_h

#include "standard_functions.h"
#include <iostream>
#include <memory>

class integrator_1D {

    public:
        integrator_1D();
        ~integrator_1D();
        
        double mid_points(const std::shared_ptr<scalar_function>& F, double a, double b, int N_step) const;
        double Simpson_2_order(const std::shared_ptr<scalar_function>& F, double a, double b, int N_step) const;
        double Simpson_Log_2_order(const std::shared_ptr<scalar_function>&, double a, double b, int N_step) const;

        bool Check_bounds(double a, double b) const;

        void Set_lower_bound(double x);


    private:
        double _lower_bound = 1e-5;
};
#endif
