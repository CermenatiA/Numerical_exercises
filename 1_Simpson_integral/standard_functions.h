#ifndef standard_functions_h_
#define standard_functions_h_

#include <iostream>
#include <memory>
#include <array>

// STANDARD SCALAR FUNCTIONS

class Scalar_function {
    public:
        virtual double eval(double x) const = 0;
};


class Scalar_function_2D {
    public:
        virtual double eval(double x, double y) const = 0;
};


class Scalar_function_3D {
    public:
        virtual double eval(double x, double y, double z) const = 0;
};

class Scalar_function_4D {
    public:
        virtual double eval(double t, double x, double y, double z) const = 0;
};


class Vectorial_2_function {
    public:
        virtual std::array<double, 2> eval(double x) const = 0;
};

class Vectorial_2_function_2D {
    public:
        virtual std::array<double, 2> eval(double x, double y) const = 0;
};

class System_function_2D {
    public:
        virtual std::array<double, 2> eval(double t, std::array<double, 2> y) const = 0;
};

#endif
