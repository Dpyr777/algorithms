#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "get_random_start_point.h"
#include "simulated_annealing.h"


void simulated_annealing(char* function, double xNew, double yNew){
    
    printf("Simulated annealing!\n");

    double initialState = 5000;
    double finalState = 0.0001;

    double currentState = initialState;

    double fOld = (1 - xNew) * (1 - xNew) + 100 * (yNew - xNew * xNew) * (yNew - xNew * xNew); 
    double fNew;
    printf("minum function in points x = %.2f; y = %.2f  => f = %f\n", xNew, yNew, fOld);

    double xOld = xNew;
    double yOld = yNew;

    double stepStart = 1.0;
    double step = stepStart;
    int factor = 1;
    double cooling = 0.995;

    while (currentState > finalState){
        // прибавляем или отнимаем шаг
        factor = (rand() & 1) ? -1 : 1; 
        // выбираем рандомное направление по оси X или Y 
        if (rand() & 1) {
            xNew = xOld + (double)rand() / RAND_MAX * step * factor;
        } else {
            xNew = xOld + (double)rand() / RAND_MAX * step * factor;
        }
        fNew = (1 - xNew) * (1 - xNew) + 100 * (yNew - xNew * xNew) * (yNew - xNew * xNew); 

        // уменьшаем температуру(состояние) 
        currentState *= cooling;
        // уменьшаем шаг в зависимости от текущей температуры и её начальной.
        step = stepStart * sqrt(currentState/initialState);

        // Если функция выросла, принимаем решение принять или отвергнуть, .
        if ((fNew - fOld) > 0){
            // под exp отрицательное число:
            // 1) Если стремится к нулю, то probability(вероятность) стремится к 1.0 (максимум)
            // 2) Если отдаляется от нуля, то probabitity стремится к 0.0 (минимум)
            double probability = exp((fOld - fNew)/currentState);
            if (probability < (double)rand() / RAND_MAX){
                continue;
            }
        } 
        fOld = fNew;
        xOld = xNew;
        yOld = yNew;
    }
    printf("minum function in points x = %.2f; y = %.2f  => f = %f\n", xNew, yNew, fOld);
    printf("--------------------------------------\n");
}
