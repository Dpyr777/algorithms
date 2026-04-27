#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "get_random_start_point.h"
#include "simulated_annealing.h"


void simulated_annealing(char* function){
    
    printf("Simulated annealing!\n");
    double xNew = get_random_start_point(10, false);
    double yNew = get_random_start_point(10, false);

    double xOld;
    double yOld;

    double initialState = 1000;
    double finalState = 0.0001;

    double startStep = 0.1;

    double currentState = initialState;

    double fOld = (1 - xOld) * (1 - xOld) + 100 * (yOld - xOld * xOld) * (yOld - xOld * xOld); 
    double fNew;
    double st;
    double step; 

    printf("minum function in points x = %.2f; y = %.2f  => f = %f\n", xNew, yNew, fOld);

    while (currentState > finalState){
        step = startStep * (currentState / initialState);
        // прибавляем или отнимаем шаг
        st = (rand() & 1) ? -1 : 1;
        xOld = xNew + step * st;
        
        st = (rand() & 1) ? -1 : 1;
        yOld = yNew + step * st;

        fNew = (1 - xOld) * (1 - xOld) + 100 * (yOld - xOld * xOld) * (yOld - xOld * xOld); 

        if (fNew > fOld){
            double probability = exp((fOld - fNew)/initialState);
            if (probability < (double)rand() / RAND_MAX){
                continue;
            }
        }
        currentState -= 0.01;
        fOld = fNew;
        xNew = xOld;
        yNew = xOld;
    }
    printf("minum function in points x = %.2f; y = %.2f  => f = %f\n", xNew, yNew, fOld);
}
