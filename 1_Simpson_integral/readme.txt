to compile the code use:                     make compile
to run the code use:                         make exe

To remove the .o and .x executable use:      make clean
To remove the results file use:              make delete

To plot the results use:                     python3 plot.py


The code run a test on an second order Simpson method for the integration of a scalar function.


It runs the integral of the function:   F(x) = x^4 - 2x + 1

on the interval [0 , 2]

with 2^N steps, from N = 1 to N = 16

The analytic value is I = 4.4

The output is printed in "results.dat":

        1 column: Log10 (Number of steps)
        2 column: Numerical value of the integral
        3 column: Relative error with respect to the analytic value of the integral: [ (I(N) - I)/I ]^2


Results are plotted in plot.py:

        1 plot: Comparison between the numerical and analytical value of the integral
                in function of the number of integration steps

        2 plot: Comparison between the numerical error and its analytical upper bound:
                        - It appears the round-of error, that saturate the precision of the calculation, when:
                            N ~ 4000,   err ~ 10^(-30)
