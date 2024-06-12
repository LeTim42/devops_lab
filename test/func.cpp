#include "func.hpp"
#include <cassert>

const double EPS = 1e-9;

#define USE_MATH_DEFINES
#define F(func, val, ...) assert(fabs(Function{func}(Point{std::vector<double>{__VA_ARGS__}}) - (val)) < EPS);

int main() {
    //function          expected    arguments
    F("x",              1,          {1}         )
    F("x + 1",          3,          {2}         )
    F("x - 0.5",        0.5,        {1}         )
    F("2*x",            2,          {1}         )
    F("x/2",            0.5,        {1}         )
    F("x%3",            2,          {5}         )
    F("-x",             2,          {-2}        )
    F("-x*3",           -3,         {1}         )
    F("1 + x*2",        3,          {1}         )
    F("(1+x)*2",        4,          {1}         )
    F("x^2",            0.25,       {0.5}       )
    F("x**2",           9,          {3}         )
    F("0.5*x**2",       4.5,        {3}         )
    F("2^x",            8,          {3}         )
    F("x^x",            27,         {3}         )
    F("x^2/2 - 0.5*x",  3,          {3}         )
    F("abs(x)",         3,          {-3}        )
    F("1 + abs(x)",     2,          {-1}        )
    F("abs(x)*2",       3,          {-1.5}      )
    F("-abs(x)",        -1,         {-1}        )
    F("sqrt(x)",        3,          {9}         )
    F("log(x)",         1,          {M_E}       )
    F("exp(x)",         M_E*M_E,    {2}         )
    F("sin(x)",         1,          {M_PI/2}    )
    F("cos(x)",         -1,         {M_PI}      )
    F("tan(x)",         1,          {M_PI/4}    )
    F("arcsin(x)",      -M_PI/2,    {-1}        )
    F("arccos(x)",      0,          {1}         )
    F("arctan(x)",      -M_PI/4,    {-1}        )
    F("sinh(x)*2",      M_E-1/M_E,  {1}         )
    F("cosh(x)*2",      M_E+1/M_E,  {1}         )
    F("tanh(x)",  (M_E-1)/(M_E+1),  {0.5}       )
    F("sqrt(x^2)",      3,          {-3}        )
    F("log(exp(x))",    0.5,        {0.5}       )
    F("arcsin(sin(x))", M_PI/2,     {M_PI/2}    )
    F("abc",            5,          {5}         )
    F("2+2*2",          6                       )
    F("(2+2)*2",        8                       )
    F("x + y",          5,          {2, 3}      )
    F("x - y * z",      1,          {7, 2, 3}   )
    F("2*x - y",        3,          {2, 1}      )
    F("2*y - x",        3,          {2, 1}      )
    F("x^y",            8,          {2, 3}      )
    F("sin(x) + y",     1,          {-M_PI/2, 2})
    return 0;
}
