#include <iostream>
#include <memory>
#include <array>
#include <fstream>
#include <iomanip>

#include "Spatial_grids.h"

Spatial_grid_1D::Spatial_grid_1D(){
    _Grid.at(0) = {_X_min, _F_x_min, 0.};
    _Grid.at(_N_points-1) = {_X_max, _F_x_max, 0.};
    double step = (_X_max - _X_min)/(double(_N_points) - 1.);
    for(int i = 1; i <_N_points - 1; i++){
        _Grid.at(i) = {_X_min + step*double(i), 0., 0.};
    }
}

Spatial_grid_1D::~Spatial_grid_1D() {};

Spatial_grid_1D::Spatial_grid_1D(int N_points, double x_min, double x_max, double F_x_min, double F_x_max){
    set_boundaries(x_min, x_max);
    set_boundary_values(F_x_min, F_x_max);
    set_Number_Of_Points(N_points);
    _Grid.at(0) = {_X_min, _F_x_min, 0.};
    _Grid.at(_N_points-1) = {_X_max, _F_x_max, 0.};
    double step = (_X_max - _X_min)/double(_N_points - 1);
    for(int i = 1; i <_N_points - 1; i++){
        _Grid.at(i) = {_X_min + step*double(i), 0., 0.};
    }
}

void Spatial_grid_1D::reset_grid(){
    for(int i=0; i < _N_points; i++){
        _Grid.at(i).F_now_val = _Grid.at(i).F_next_val;
        _Grid.at(i).F_next_val = 0.;
    }
    return;
}

void Spatial_grid_1D::save_grid(std::string name) const {
    std::ofstream output;
    output.open(name, std::ios::app);
    for(int i = 0; i < _N_points; i++){
        output << _Grid.at(i).X_val << std::setw(16) << _Grid.at(i).F_now_val << std::endl;
    }
    return;
}

void Spatial_grid_1D::set_initial_condition(){
    _Grid.at(0).F_now_val = get_F_x_min();
    _Grid.at(_N_points - 1).F_now_val = get_F_x_max();
    for(int i = 1; i < _N_points - 1; i++){
        _Grid.at(i).F_now_val = 0.;
    }
    return;
}

void Spatial_grid_1D::set_initial_condition(const std::shared_ptr<Scalar_function>& F){
    _Grid.at(0).F_now_val = get_F_x_min();
    _Grid.at(_N_points - 1).F_now_val = get_F_x_max();
    for(int i = 1; i < _N_points - 1; i++){
        _Grid.at(i).F_now_val = F->eval(_Grid.at(i).X_val);
    }
    return;
}

void Spatial_grid_1D::set_boundaries(double x_min, double x_max){
    _X_min = x_min;
    _X_max = x_max;
    return;
}

double Spatial_grid_1D::get_X_min() const { return _X_min;}

double Spatial_grid_1D::get_X_max() const { return _X_max;}

void Spatial_grid_1D::set_boundary_values(double F_x_min, double F_x_max){
    _F_x_min = F_x_min;
    _F_x_max = F_x_max;
    return;
}

double Spatial_grid_1D::get_F_x_min() const { return _F_x_min;}

double Spatial_grid_1D::get_F_x_max() const { return _F_x_max;}

void Spatial_grid_1D::set_Number_Of_Points(int N){
    _N_points = N;
}

int Spatial_grid_1D::get_Number_Of_Points() const {return _N_points;}

double Spatial_grid_1D::get_delta_x() const { return (_X_max - _X_min)/double(_N_points - 1);}