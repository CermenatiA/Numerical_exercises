#ifndef PDE_solver_h
#define PDE_solver_h

#include <iostream>
#include <memory>
#include <array>
#include <vector>

#include "standard_functions.h"
#include "Spatial_grids.h"

class Diffusion_1_D {
    public:
        Diffusion_1_D();
        ~Diffusion_1_D();

        void explicit_Crank_Nicholson(const std::shared_ptr<Spatial_grid_1D>& Grid, const std::shared_ptr<Scalar_function>& Q, double delta_T);
        void implicit_Crank_Nicholson(const std::shared_ptr<Spatial_grid_1D>& Grid, const std::shared_ptr<Scalar_function>& Q, double delta_T);

        void set_diffusion_coefficient(double D);
        double get_diffusion_coefficient();

        void gsl_linalg_solve_tridiag(const std::vector<double>& diag, const std::vector<double>& abovediag,
                             const std::vector<double>& belowdiag, const std::vector<double>& rhs, std::vector<double>& solution);
        void solve_tridiag_nonsym(const std::vector<double>& diag, const std::vector<double>& abovediag,
                         const std::vector<double>& belowdiag, const std::vector<double>& rhs, std::vector<double>& x, size_t N);

    private:

        double _D = 0.1;
};
#endif