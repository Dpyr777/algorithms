#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "derivative.h"
#include "grad_descent.h"

double get_random_start_point();

void grad_descent(char* function){
#if 0
    char* derX = derivative(function, 'x');
    char* derY = derivative(function, 'y');
#endif
    srand(time(NULL));
    printf("derX = 2 * x - 2 - 400 * x * y + 400 * x^3\n");
    printf("derY = 200 * y - 200 * x^2\n");

    
    double xNew;
    double yNew;

    double xOld;
    double yOld;

    double f; 

    double step = 0.001f;
    double eps = 0.00001f;
    for (int i = 0; i < 10; ++i){
        xNew = get_random_start_point(); 
        printf("x0 = %f\n", xNew);

        yNew = get_random_start_point();
        printf("y0 = %f\n", yNew);

        xOld = 0.0;
        yOld = 0.0;

        f = (1 - xNew) * (1 - xNew) + 100 * (yNew - xNew * xNew) * (yNew - xNew * xNew);
        printf("minum function in points x = %.2f; y = %.2f  => f = %.2f\n", xNew, yNew, f);

        while (fabs(xNew - xOld) > eps || fabs(yNew - yOld) > eps){
            xOld = xNew;
            yOld= yNew;
            xNew = xOld - step * (2 * xOld - 2 - 400 * xOld * yOld + 400 * powf(xOld, 3));  
            yNew = yOld - step * (200 * yOld - 200 * powf(xOld, 2));
            f = (1 - xNew) * (1 - xNew) + 100 * (yNew - xNew * xNew) * (yNew - xNew * xNew);
            //printf("minum function in points x = %.2f; y = %.2f  => f = %.8f\n", xNew, yNew, f);
            if (fabs(xNew / xOld) > 5.0 || fabs(yNew / xOld) > 5.0){
                printf("Blow-up\n");
                break;
            }
        }
        printf("minum function in points x = %.2f; y = %.2f  => f = %.4f\n", xNew, yNew, f);
    }
}
double get_random_start_point(){
    double point = 1.0f / (rand() % 10 + 1); 
    if ((rand() & 1) == 0) {
        point = -point;
    }
    return point; 
}

