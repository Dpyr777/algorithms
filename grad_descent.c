#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "derivative.h"


void grad_desent(char* function){
#if 0
    char* derX = derivative(function, 'x');
    char* derY = derivative(function, 'y');
#endif
    srand(time(NULL));
    printf("derX = 2 * x + 2 - 400 * x * y + 400 * x^3");
    printf("derY = 2 * y - 200 * x^2");

    
    float x0 = 1.0f / (rand() % 10); 
    if ((rand() & 1) == 0) {
        x0 = -x0;
    }
    printf("x0 = %f", x0);

    float y0 = 1.0f / (rand() % 10); 
    if ((rand() & 1) == 0) {
        y0 = -y0;
    }
    printf("y0 = %f", y0);
}
