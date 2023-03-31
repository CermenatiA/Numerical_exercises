#ifndef standard_functions_h_
#define standard_functions_h_

// STANDARD SCALAR FUNCTIONS

class scalar_function {
    public:
        virtual double Eval(double x) const = 0;
};


class scalar_function_2D {
    public:
        virtual double Eval(double x, double y) const = 0;
};


class scalar_function_3D {
    public:
        virtual double Eval(double x, double y, double z) const = 0;
};

class scalar_function_4D {
    public:
        virtual double Eval(double t, double x, double y, double z) const = 0;
};


#endif
