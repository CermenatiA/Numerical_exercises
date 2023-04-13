to compile the code use:                     make compile
to run the code use:                         make exe

To remove the .o and .x executable use:      make clean
To remove the results file use:              make delete

To plot the results use:                     python3 plot.py


The code run a test on a second order Runge Kutta algorithm for solving Ordinary Differential Equations:

The algorithm is tested on a non-linear pendulum:

        d(Theta)/dt = (Omega)
        d(Omega)/dt = - g/l sin((Theta))

with g = 9.8 m/s^2      and l = 0.1 m

and initial condition [Theta_0 , Omega_0] = [179° , 0]


The results are printed in the file "results.dat":

        1 column: time [s]
        2 column: Theta [rad]
        3 column: Omega [s^-1]
        4 column: Kinetic energy per unit mass [m^2 / s^2]
        5 column: Potential energy per unit mass [m^2 / s^2]
        6 column: Total energy per unit mass [m^2 / s^2]


The results are plotted in plot.py:

        1 plot: time evolution of Theta(t), Omega(t)
        2 plot: time evolution of K(t), U(t), E(t)
        3 plot: time evolution of E(t) - E(t=0)
                - the algorithm doesn't conserve the energy, that grows linearly with the time
                    Delta_E ~ 10^(-8) t
                    plus an oscillatory component of amplitude ~ (10^-7)