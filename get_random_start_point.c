#include <stdlib.h>
#include <stdbool.h>

double get_random_start_point(unsigned int limit, bool isInteger){
    double point = 0.0;
    if (isInteger){
        point = rand() % (limit * 2 + 1) - limit; 
    } else {
        double factor = (double)rand() / RAND_MAX;
        point = limit * 2 * factor - limit;
    }
    return point; 
}
