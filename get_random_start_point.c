#include <stdlib.h>
#include <stdbool.h>

double get_random_start_point(unsigned int limit, bool isInteger){
    // для получения дробных чисел
    double factor;
    if (isInteger){
        factor = 1.0;
    } else {
        factor = (double)rand() / RAND_MAX;
    }
    double point = (rand() % (limit * 2 + 1)) * factor - limit;

    return point; 
}
