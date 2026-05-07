#include <stdlib.h>
#include "random_in_range.h"

double random_in_range(int range){
    double random = 0.0;
    double factor = (double)rand() / RAND_MAX;
    random = range * 2 * factor - range;
    return random; 
}
