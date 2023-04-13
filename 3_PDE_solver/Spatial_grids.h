#ifndef Spatial_grids_h
#define Spatial_grids_h

#include <iostream>
#include <memory>
#include <array>

#include "standard_functions.h"

struct Grid_1D{
    double X_val;
    double F_now_val;
    double F_next_val;
};

class Spatial_grid_1D {

    public:
        Spatial_grid_1D();
        ~Spatial_grid_1D();
        Spatial_grid_1D(int N_points, double x_min, double x_max, double F_x_min, double F_x_max);
        void reset_grid();
        void save_grid(std::string name) const;

        std::array<Grid_1D, 10000> _Grid;

        void set_initial_condition();
        void set_initial_condition(const std::shared_ptr<Scalar_function>& F);

        void set_boundaries(double x_min, double x_max);
        double get_X_min() const;
        double get_X_max() const;
        void set_boundary_values(double F_x_min, double F_x_max);
        double get_F_x_min() const;
        double get_F_x_max() const;
        void set_Number_Of_Points(int N);
        int get_Number_Of_Points() const;
        double get_delta_x() const;

    private:

        double _X_min = -1.;
        double _X_max = +1.;
        double _F_x_min = 0.;
        double _F_x_max = 0.;

        int _N_points = 101;

        
};


#endif