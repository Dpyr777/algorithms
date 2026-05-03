#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "grad_descent.h"
#include "simulated_annealing.h"
#include "get_random_start_point.h"
#include "genetic_algorithm.h"

int main(){
    srand(time(NULL));
#if 0
    char* function = (char*)malloc(100 * size(char));
    scanf("%99s", function);
#endif
    char* function = "(1 - x)^2 + 100 * (y - x^2)^2";
    printf("Function Rosenbrock -> f(x, y) = %s\n", function); 
    double x0 = 0.0;
    double y0 = 0.0;
    double f = 0.0;
    double fGrad;
    double fSim;
    double fGen;
    for (int i = 0; i < 10; ++i){
        x0 = get_random_start_point(10, false); 
        y0 = get_random_start_point(10, false);
        f = (1 - x0) * (1 - x0) + 100 * (y0 - x0 * x0) * (y0 - x0 * x0); 
        printf("Value function in starting points x0 = %.2f; y0 = %.2f  => f = %f\n", x0, y0, f);
        printf("--------------------------------------\n");
        fGrad = grad_descent(function, x0, y0);
        fSim = simulated_annealing(function, x0, y0);
        fGen = genetic_algorithm(function, x0, y0);
        printf("--Function--\t\t --Value--\nGradient descent:\t %f\nSimulated annealing:\t %f\nGenetic algorithm:\t %f\n", fGrad, fSim, fGen); 
        printf("======================================\n");
    }
    
    return 0;
}
