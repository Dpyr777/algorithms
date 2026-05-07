#ifndef TYPES_H
#define TYPES_H 

typedef struct{
    double x;
    double y;
    double f;
}Point;

typedef double (*func_ptr) (double x, double y);
#endif
