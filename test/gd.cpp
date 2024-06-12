#include "gd.hpp"
#include <cassert>

const double EPS = 1e-6;

#define USE_MATH_DEFINES

bool eq(const Point& a, const Point& b) {
    if (a.x.size() != b.x.size())
        return false;
    for (size_t i = 0; i < a.x.size(); ++i)
        if (fabs(a.x[i] - b.x[i]) >= EPS)
            return false;
    return true;
}

#define GD(func, l, r, s, c, ...) assert(eq(gradient_descent(func, l, r, s, c).back(), Point{std::vector<double>{__VA_ARGS__}}));

int main() {
    // function             bounds      step            expected
    GD("x^2",               -10, 10,    0.5,  1000,     {0}         )
    GD("(x-2)^2",           -10, 10,    0.5,  1000,     {2}         )
    GD("(x+2)^2+(y-1)^2",   -10, 10,    0.5,  1000,     {-2,1}      )
    GD("x^3-3*x",           -1,  2,     0.25, 1000,     {1}         )
    GD("2+2*2",             -10, 10,    0.5,  1000                  )
    return 0;
}
