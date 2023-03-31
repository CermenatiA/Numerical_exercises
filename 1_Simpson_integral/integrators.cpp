#include "integrators.h"
#include "standard_functions.h"

#include <iostream>
#include <memory>
#include <math.h>

integrator_1D::integrator_1D() {}

integrator_1D::~integrator_1D() {}

double integrator_1D::mid_points(const std::shared_ptr<scalar_function>& F, double a, double b, int N_step) const {
    if(Check_bounds(a,b)){
        if(b == a){
            return 0.;
        }
        double h=(b-a)/double(N_step);
        double V=0;
        for(int i=0; i<N_step; i++)
        {
            V = V + F->Eval(a + ((b - a) * (double(i) + 0.5) / double(N_step)));
        }
        return (b - a) * V / double(N_step);
    }
    else{
        return -1;
    }
    return 0.;
}

double integrator_1D::Simpson_2_order(const std::shared_ptr<scalar_function>& F, double a, double b, int N_step) const {
    if(Check_bounds(a,b)){
        if(b == a){
           return 0.;
        }
        if(N_step%2 == 0){
            N_step++;
        }
        double h = (b - a)/double(N_step);
        double V = F->Eval(a) + F->Eval(b) + 4. * F->Eval(b - h);
        for(int i=0; i < N_step/2 - 1; i++){
            V = V + 2. * F->Eval(a + (2. * (double(i) + 1.) * h)) + 4. * F->Eval(a + (2.*double(i) + 1.) * h);
        }
        return V * h / 3.;
    }
    else{
        return -1;
    }
    return 0;
}

double integrator_1D::Simpson_Log_2_order(const std::shared_ptr<scalar_function>& F, double a, double b, int N_step) const {
    if(Check_bounds(a,b)){
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
        double V = a * F->Eval(a) + b * F->Eval(b) + 4. * b * F->Eval(b / r) / r;
        for(int i=0; i < N_step/2 - 1; i++){
            V = V + 2. * a * pow(r, 2. * (double(i) + 1.)) * F->Eval(a * pow(r, 2. * (double(i) + 1.))) + 4. * a * pow(r, 1. + 2.*double(i)) * F->Eval(a * pow(r, 2.*double(i) + 1.));
        }
        return V * log(r) / 3.;
    }
    else{
        return -1;
    }
}




bool integrator_1D::Check_bounds(double a, double b) const {
    if(b<a)
    {
        std::cerr<<"controllare gli estremi dell'intervallo"<<std::endl;
        return false;
    }
    else{
        return true;
    }
}

void integrator_1D::Set_lower_bound(double x) {
    _lower_bound = x;
}
