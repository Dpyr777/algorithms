#include <stdio.h>
#include "grad_descent.h"

int main(){

#if 0
    char* function = (char*)malloc(100 * size(char));
    scanf("%99s", function);
#endif
    char* function = "(1 - x)^2 + 100 * (y - x^2)^2";
    printf("Function Rosenbrock -> f(x, y) = %s\n", function); 
    grad_descent(function);
    
    return 0;
}
