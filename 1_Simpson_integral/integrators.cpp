#include "integrators.h"
#include "standard_functions.h"

#include <iostream>
#include <memory>
#include <math.h>

Integrator_1D::Integrator_1D() {}

Integrator_1D::~Integrator_1D() {}

double Integrator_1D::mid_points(const std::shared_ptr<Scalar_function>& F, double a, double b, int N_step) const {
    if(check_bounds(a,b)){
        if(b == a){
            return 0.;
        }
        double h=(b-a)/double(N_step);
        double V=0;
        for(int i=0; i<N_step; i++)
        {
            V = V + F->eval(a + ((b - a) * (double(i) + 0.5) / double(N_step)));
        }
        return (b - a) * V / double(N_step);
    }
    else{
        return -1;
    }
    return 0.;
}

double Integrator_1D::simpson_2_order(const std::shared_ptr<Scalar_function>& F, double a, double b, unsigned long int N_step) const {
    if(check_bounds(a,b)){
        if(b == a){
           return 0.;
        }
        if(N_step%2 != 0){
            N_step++;
        }
        long double h = (b - a)/double(N_step);
        double V = F->eval(a) + F->eval(b) + 4. * F->eval(b - h);
        for(int i=0; i < N_step/2 - 1; i++){
            V = V + 2. * F->eval(a + (2. * (double(i) + 1.) * h)) + 4. * F->eval(a + (2.*double(i) + 1.) * h);
        }
        return V * h / 3.;
    }
    else{
        return -1;
    }
    return 0;
}

double Integrator_1D::simpson_Log_2_order(const std::shared_ptr<Scalar_function>& F, double a, double b, int N_step) const {
    if(check_bounds(a,b)){
        if(a == b){
            return 0.;
        }
        if(N_step%2 == 0){
            N_step++;
        }
        if(a == 0){
            a = _lower_bound;
        }
        if(a < 0){
            std::cerr<<"controllare gli estremi dell'intervallo"<<std::endl;
            return -1.;
        }
        double r = pow(b/a, 1./double(N_step));
        double V = a * F->eval(a) + b * F->eval(b) + 4. * b * F->eval(b / r) / r;
        for(int i=0; i < N_step/2 - 1; i++){
            V = V + 2. * a * pow(r, 2. * (double(i) + 1.)) * F->eval(a * pow(r, 2. * (double(i) + 1.))) + 4. * a * pow(r, 1. + 2.*double(i)) * F->eval(a * pow(r, 2.*double(i) + 1.));
        }
        return V * log(r) / 3.;
    }
    else{
        return -1;
    }
}




bool Integrator_1D::check_bounds(double a, double b) const {
    if(b<a)
    {
        std::cerr<<"controllare gli estremi dell'intervallo"<<std::endl;
        return false;
    }
    else{
        return true;
    }
}

void Integrator_1D::set_lower_bound(double x) {
    _lower_bound = x;
}
