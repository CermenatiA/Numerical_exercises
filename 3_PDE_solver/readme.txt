to compile the code use:                     make compile_implicit
                                             make compile_explicit

First you should create, in your work directory, two directories called:

    "results_expl"
    "results_impl"

These will store all the output files generated from the codes to plot the results

to run the code you have compiled use:                         make exe

To remove the .o and .x executable use:      make clean
To remove the results file use:              make delete_impl
                                             make delete_expl

To plot the results use:                     python3 plot_impl.py
                                             python3 plot_expl.py


The code test two methods to solve parabolic PDEs:

        1 explicit Crank Nicholson method
        2 implicit Crank Nicholson method

tested on a purely diffusive transport equation


The methods are tested for a known solution of the steady state equation: u(x) = cos(pi/2 x/H)
deriving the associate source term

on a spatial grid on the range [ -H, H]

for H = 1       and D = 0.1


Each output file contains, at a given time:

        1 column: the x point on the grid
        2 column: the value of the function at that point


Results are plotted by the associate plot... .py file, which plot:

        1 plot: the evolution with time of the solution on the spatial grid (with 2^8 points on the grid)
        2 plot: the evolution in time of the error for different number of points on the grid
        3 plot: the relative error raising up the nummber of points on the grid


The algorithm show the scaling 1/N^2 of the error, evaluated as the 2-norm of the function:

        err = [ 1/N sum_i ( (u(x_i) - f(x_i) )/f(x_i) ) ]^2