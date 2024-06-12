#ifndef GD_HPP
#define GD_HPP
#include <random>
#include <chrono>
#include "func.hpp"

#define sqr(x) ((x)*(x))

const double D = 1e-6; // for stopping gradient descent
const double H = 1e-9; // for calculating gradient
extern std::mt19937 engine;
extern Function f;
extern size_t n;

std::vector<Point> gradient_descent(std::string&& function, double left_border, double right_border, double step_len, size_t max_steps_count);

#endif // GD_HPP
