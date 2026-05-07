#include <math.h>
#include "types.h"
#include "derivative.h"
#include "functions.h"
#include "random_in_range.h"


Point grad_descent(func_ptr function, Point point, int choice){
    // новые координаты
    double xNew = point.x;
    double yNew = point.y;
    double xOld = xNew + 1;
    double yOld = yNew + 1;

    // значение функции в начале и после шага
    double fOld = point.f; 
    double fNew;

    // начальная длина шага
    double step = 0.001;
    // лимит изменения
    double eps = 0.000001;

    while (fabs(xNew - xOld) > eps || fabs(yNew - yOld) > eps){
        xOld = xNew;
        yOld = yNew;
        // для новых координат из старых координат вычитаем производную умноженную на величину шага(обратный градиентный спуск)
        Point deriv = derivative(xOld, yOld, choice);

        xNew = xOld - step * deriv.x;
        yNew = yOld - step * deriv.y;

        fNew = function(xNew, yNew);
        
        // проверка на предел новых значений
        if (!isfinite(xNew) || !isfinite(yNew) || !isfinite(yNew)){ 
            step /= 10;
            xNew = xOld;
            yNew = yOld;
            // чтобы не пройти условие цикла
            xOld = xNew + 1;
        }

        // проверяем на рост функции, если да то слишком большой шаг перепрыгнули минимум
        if (fNew > fOld){
            // уменьшаем шаг;
            if (step > 0.0000000001){
                step /= 1.5;
            }
            // повторяем с прошлой точки, с уменьшенным шагом
            xNew = xOld;
            yNew = yOld;
            // чтобы не пройти условие цикла
            xOld += 1;
            continue;
        }
        point.x = xNew;
        point.y = yNew;
        point.f = fNew;
        fOld = fNew;
    }

    return point;
}
