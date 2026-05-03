#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "derivative.h"
#include "grad_descent.h"
#include "get_random_start_point.h"
#include "rosenbrock.h"


double grad_descent(char* function, double xNew, double yNew){
    
    //printf("Gradient descent!\n");

#if 0
    char* derX = derivative(function, 'x');
    char* derY = derivative(function, 'y');
#endif
    //printf("derX = 2 * x - 2 - 400 * x * y + 400 * x^3\n");
    //printf("derY = 200 * y - 200 * x^2\n");

    // новые координаты
    double xOld = xNew + 1;
    double yOld = yNew + 1;

    // значение функции в начале и после шага
    double fOld; 
    double fNew;

    // начальная длина шага
    double step = 0.001;
    // лимит изменения
    double eps = 0.000001;


    fOld = rosenbrock(xNew, yNew); 

    while (fabs(xNew - xOld) > eps || fabs(yNew - yOld) > eps){
        xOld = xNew;
        yOld = yNew;
        // для новых координат из старых координат вычитаем производную умноженную на величину шага(обратный градиентный спуск)
        xNew = xOld - step * (2 * xOld - 2 - 400 * xOld * yOld + 400 * powf(xOld, 3));  
        yNew = yOld - step * (200 * yOld - 200 * powf(xOld, 2));

        // проверка на предел новых значений
        if (isinf(xNew) || isnan(xNew) || isnan(yNew) || isnan(yNew)){ 
            fOld = -666.666;
            printf("Blow-up\n");
            break;
        }

        fNew = rosenbrock(xNew, yNew);
        //printf("minum function in points x = %.2f; y = %.2f  => f = %.8f\n", xNew, yNew, fNew);

        // проверяем на рост функции, если да то слишком большой шаг перепрыгнули минимум
        if (fNew > fOld){
            // уменьшаем шаг и лимит изменения;
            step /= 1.5;
            // повторяем спрошлой точки с уменьшенном шагом
            xNew = xOld;
            yNew = yOld;
            xOld += 1;
            yOld += 1;
            continue;
        }
        fOld = fNew;
    }
    //printf("Minum value function in points x = %.2f; y = %.2f  => f = %f\n", xNew, yNew, fOld);
    return fOld;
}

