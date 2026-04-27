#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grad_descent.h"
#include "simulated_annealing.h"

int main(){
    srand(time(NULL));
#if 0
    char* function = (char*)malloc(100 * size(char));
    scanf("%99s", function);
#endif
    char* function = "(1 - x)^2 + 100 * (y - x^2)^2";
    printf("Function Rosenbrock -> f(x, y) = %s\n", function); 
    grad_descent(function);
    simulated_annealing(function);
    
    return 0;
}
