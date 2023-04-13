#ifndef integrators_h
#define integrators_h

#include "standard_functions.h"
#include <iostream>
#include <memory>

class Integrator_1D {

    public:
        Integrator_1D();
        ~Integrator_1D();
        
        double mid_points(const std::shared_ptr<Scalar_function>& F, double a, double b, int N_step) const;
        double simpson_2_order(const std::shared_ptr<Scalar_function>& F, double a, double b, unsigned long int N_step) const;
        double simpson_Log_2_order(const std::shared_ptr<Scalar_function>&, double a, double b, int N_step) const;

        void set_lower_bound(double x);


    private:

        bool check_bounds(double a, double b) const;

        double _lower_bound = 1e-5;
};
#endif
