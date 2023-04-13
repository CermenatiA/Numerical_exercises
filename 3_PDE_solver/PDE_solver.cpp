#include <iostream>
#include <memory>
#include <array>
#include <vector>
#include <cmath>

#include "standard_functions.h"
#include "Spatial_grids.h"
#include "PDE_solver.h"

Diffusion_1_D::Diffusion_1_D() {};

Diffusion_1_D::~Diffusion_1_D() {};

void Diffusion_1_D::explicit_Crank_Nicholson(const std::shared_ptr<Spatial_grid_1D>& Grid, const std::shared_ptr<Scalar_function>& Q, double delta_T) {
    Grid->_Grid.at(0).F_next_val = Grid->get_F_x_min();
    Grid->_Grid.at(Grid->get_Number_Of_Points() -1).F_next_val = Grid->get_F_x_max();
    double lambda = delta_T*get_diffusion_coefficient()/pow(Grid->get_delta_x(),2.);
    for(int i = 1; i < Grid->get_Number_Of_Points() - 1; i++){
        Grid->_Grid.at(i).F_next_val = delta_T*Q->eval(Grid->_Grid.at(i).X_val) 
                                        + lambda*(Grid->_Grid.at(i+1).F_now_val 
                                        + Grid->_Grid.at(i-1).F_now_val) + (1. - 2.*lambda)*Grid->_Grid.at(i).F_now_val;
    }
    return;
};

void Diffusion_1_D::implicit_Crank_Nicholson(const std::shared_ptr<Spatial_grid_1D>& Grid, const std::shared_ptr<Scalar_function>& Q, double delta_T) {
    Grid->_Grid.at(0).F_next_val = Grid->get_F_x_min();
    Grid->_Grid.at(Grid->get_Number_Of_Points() -1).F_next_val = Grid->get_F_x_max();
    const double lambda = delta_T*get_diffusion_coefficient()/(2.*pow(Grid->get_delta_x(),2.));
    std::vector<double> Diag(Grid->get_Number_Of_Points() - 2, (1. + 2.*lambda));
    std::vector<double> AboveDiag(Grid->get_Number_Of_Points() - 3, (-1.)*lambda);
    std::vector<double> BelowDiag(Grid->get_Number_Of_Points() - 3, (-1.)*lambda);
    std::vector<double> RHS(Grid->get_Number_Of_Points() - 2, 0.);
    std::vector<double> Solution(Grid->get_Number_Of_Points() - 2, 0.);
    for(int k = 0; k < Grid->get_Number_Of_Points() - 2; k++){
        RHS.at(k) = (lambda*(Grid->_Grid.at(k).F_now_val + Grid->_Grid.at(k+2).F_now_val) 
                        + (1. - 2.*lambda)*Grid->_Grid.at(k + 1).F_now_val
                        + delta_T*Q->eval(Grid->_Grid.at(k+1).X_val));
    }
    gsl_linalg_solve_tridiag(Diag, AboveDiag, BelowDiag, RHS, Solution);
    for(int i = 1; i < Grid->get_Number_Of_Points() -1; i++){
        Grid->_Grid.at(i).F_next_val = Solution.at(i-1);
    }
    return;
}

void Diffusion_1_D::set_diffusion_coefficient(double D) { _D = D; }

double Diffusion_1_D::get_diffusion_coefficient() { return _D; }


void Diffusion_1_D::gsl_linalg_solve_tridiag(const std::vector<double>& diag, const std::vector<double>& abovediag,
                             const std::vector<double>& belowdiag, const std::vector<double>& rhs,
                             std::vector<double>& solution) {
  if (diag.size() != rhs.size()) {
    std::cout << "size of diag must match rhs" << std::endl;
  } else if (abovediag.size() != rhs.size() - 1) {
    std::cout << "size of abovediag must match rhs-1" << std::endl;
  } else if (belowdiag.size() != rhs.size() - 1) {
    std::cout << "size of belowdiag must match rhs-1" << std::endl;
  } else if (solution.size() != rhs.size()) {
    std::cout << "size of solution must match rhs" << std::endl;
  } else {
    solve_tridiag_nonsym(diag, abovediag, belowdiag, rhs, solution, diag.size());
  }
  return;
}

void Diffusion_1_D::solve_tridiag_nonsym(const std::vector<double>& diag, const std::vector<double>& abovediag,
                         const std::vector<double>& belowdiag, const std::vector<double>& rhs, std::vector<double>& x,
                         size_t N) {
    std::vector<double> alpha(N);
    std::vector<double> z(N);
    size_t i, j;
    alpha[0] = diag[0];
    z[0] = rhs[0];
    if (alpha[0] == 0) {
        std::cout << "division by 0" << std::endl;
    }
    for (i = 1; i < N; i++) {
        const double t = belowdiag[i - 1] / alpha[i - 1];
        alpha[i] = diag[i] - t * abovediag[i - 1];
        z[i] = rhs[i] - t * z[i - 1];
        if (alpha[i] == 0) {
        std::cout << "division by 0" << std::endl;
        }
    }   /* backsubstitution */
    x[N - 1] = z[N - 1] / alpha[N - 1];
    if (N >= 2) {
        for (i = N - 2, j = 0; j <= N - 2; j++, i--) {
            x[i] = (z[i] - abovediag[i] * x[i + 1]) / alpha[i];
        }
    }
    return;
}

