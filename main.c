#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "grad_descent.h"
#include "simulated_annealing.h"
#include "get_random_start_point.h"

int main(){
    srand(time(NULL));
#if 0
    char* function = (char*)malloc(100 * size(char));
    scanf("%99s", function);
#endif
    char* function = "(1 - x)^2 + 100 * (y - x^2)^2";
    printf("Function Rosenbrock -> f(x, y) = %s\n", function); 
    double xNew = 0.0;
    double yNew = 0.0;
    for (int i = 0; i < 10; ++i){
        xNew = get_random_start_point(100, false); 
        printf("x0 = %f\n", xNew);
        yNew = get_random_start_point(100, false);
        printf("y0 = %f\n", yNew);
        grad_descent(function, xNew, yNew);
        simulated_annealing(function, xNew, yNew);
        printf("======================================\n");
    }
    
    return 0;
}
