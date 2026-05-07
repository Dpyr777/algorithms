#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "types.h"

Point grad_descent(func_ptr function, Point point, int deriv);
Point simulated_annealing(func_ptr function, Point point);
Point genetic_algorithm(func_ptr function, Point point);

#endif
