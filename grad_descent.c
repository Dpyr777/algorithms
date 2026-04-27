#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "derivative.h"
#include "grad_descent.h"
#include "get_random_start_point.h"


void grad_descent(char* function){
    
    printf("Gradient descent!\n");

#if 0
    char* derX = derivative(function, 'x');
    char* derY = derivative(function, 'y');
#endif
    srand(time(NULL));
    printf("derX = 2 * x - 2 - 400 * x * y + 400 * x^3\n");
    printf("derY = 200 * y - 200 * x^2\n");

    // начальные координаты
    double xNew;
    double yNew;

    // новые координаты
    double xOld;
    double yOld;

    // значение функции в начале и после шага
    double fOld; 
    double fNew;

    // начальная длина шага
    double step = 0.001f;
    // лимит изменения
    double eps = 0.0001f;

    // флаг врызва функции когда переменные переполняются или становятся не определенными
    bool blowUp = false;
    for (int i = 0; i < 10; ++i){
        xNew = get_random_start_point(10, false); 
        printf("x0 = %f\n", xNew);

        yNew = get_random_start_point(10, false);
        printf("y0 = %f\n", yNew);

        xOld = xNew + 1;
        yOld = yNew + 1;

        fOld = (1 - xNew) * (1 - xNew) + 100 * (yNew - xNew * xNew) * (yNew - xNew * xNew);
        printf("minum function in points x = %.2f; y = %.2f  => f = %f\n", xNew, yNew, fOld);

        while (fabs(xNew - xOld) > eps || fabs(yNew - yOld) > eps){
            xOld = xNew;
            yOld = yNew;
            xNew = xOld - step * (2 * xOld - 2 - 400 * xOld * yOld + 400 * powf(xOld, 3));  
            yNew = yOld - step * (200 * yOld - 200 * powf(xOld, 2));
            fNew = (1 - xNew) * (1 - xNew) + 100 * (yNew - xNew * xNew) * (yNew - xNew * xNew);
            //printf("minum function in points x = %.2f; y = %.2f  => f = %.8f\n", xNew, yNew, fNew);
#if 1
            // проверка на предел новых значений
            if (isinf(xNew) || isnan(xNew) || isnan(yNew) || isnan(yNew)){ 
                blowUp = true;
                break;
            }

            // проверяем на рост функции, если да то слишком большой шаг перепрыгнули минимум
            if (fNew > fOld){
                // уменьшаем шаг и лимит изменения;
                step /= 2;
                eps /= 2;
                // повторяем спрошлой точки с уменьшенном шагом
                xNew = xOld;
                yNew = yOld;
                xOld += 1;
                yOld += 1;
                continue;
            }
#endif
            fOld = fNew;
        }
        if (blowUp == true){
            printf("Blow-up\n");
        } else {
            printf("minum function in points x = %.2f; y = %.2f  => f = %.4f\n", xNew, yNew, fOld);
        }
        printf("--------------------------------------\n");
    }
}

