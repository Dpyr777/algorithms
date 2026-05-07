#include "functions.h"
#include <math.h>

double rosenbrock(double x, double y){
    return (1 - x) * (1 - x) + 100 * (y - x * x) * (y - x * x); 
}

double himmelblau(double x, double y){
    return (x * x + y - 11) * (x * x + y - 11) + (x + y * y - 7) * (x + y * y - 7);
}

double rastrigin(double x, double y){
    return 20 + x * x + y * y - 10 * (cos(2 * M_PI * x) + cos(2 * M_PI * y));
}
