#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "random_in_range.h"
#include "functions.h"


Point simulated_annealing(func_ptr function, Point point){
    
    double initialState = 10000;
    double finalState = 0.00000001;

    double currentState = initialState;

    double fOld = point.f;
    double fNew;

    double xNew;
    double yNew;
    double xOld = point.x;
    double yOld = point.y;

    double stepStart = 1.5;
    double step = stepStart;
    int factor = 1;
    double cooling = 0.998;

    while (currentState > finalState){
        // прибавляем или отнимаем шаг
        factor = (rand() & 1) ? -1 : 1; 
        // выбираем рандомное направление по оси X или Y 
        if (rand() & 1) {
            xNew = xOld + (double)rand() / RAND_MAX * step * factor;
        } else {
            yNew = yOld + (double)rand() / RAND_MAX * step * factor;
        }
        fNew = function(xNew, yNew);

        // Если функция выросла, принимаем решение принять или отвергнуть, .
        if ((fNew - fOld) > 0){
            // под exp отрицательное число:
            // 1) Если стремится к нулю, то probability(вероятность) стремится к 1.0 (максимум)
            // 2) Если отдаляется от нуля, то probabitity стремится к 0.0 (минимум)
            double probability = exp((fOld - fNew)/currentState);
            if (probability < (double)rand() / RAND_MAX){
                // не обновляем точку оставляем старую
                goto fail_no_update;
            }
        }
        // принимаем улучшение
        if (fNew < point.f) {
            point.f = fNew;
            point.x = xNew;
            point.y = yNew;
        }
        fOld = fNew;
        xOld = xNew;
        yOld = yNew;
fail_no_update:
        // уменьшаем температуру(состояние) 
        currentState *= cooling;
        // уменьшаем шаг в зависимости от текущей температуры и её начальной.
        step = stepStart * sqrt(currentState/initialState);
    }

    return point;
}
