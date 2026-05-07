#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "random_in_range.h"
#include "algorithms.h"
#include "functions.h"

int main(){
    srand(time(NULL));

    func_ptr arrFunc[3] = {
        rosenbrock,
        himmelblau,
        rastrigin
    };

    char* nameFunctions[3] = {"Rosenbrock -> (1 - x)^2 + 100 * (y - x^2)^2",
                              "Himmelblau -> (x^2 + y - 11)^2 + (x + y^2 - 7)^2", 
                              "Rastrigin -> 20 + x^2 + y^2 - 10 * (cos(2 * Pi * x) + cos(2 * Pi * y))"};

    printf("Function selection (1, 2 or 3): \n1) %s\n2) %s\n3) %s\n----> ", nameFunctions[0], nameFunctions[1], nameFunctions[2]);
    int choice = 1;
    scanf("%i", &choice); 
    if (choice > 3) {
        printf("WARNING!!!\n");
        choice = 3;
    } else if (choice < 1){
        printf("WARNING!!!\n");
        choice = 1;
    }

    printf("Function %s\n", nameFunctions[choice - 1]); 

    printf("\nSelection number of starting points: ");
    int numPoint = 1;
    scanf("%i", &numPoint);
    if (numPoint < 1){
        printf("WARNING!!!\n");
        numPoint = 10;
    }

    printf("\nChoosing a range (example input '9' -> [-9, 9]): ");
    int range = 5;
    scanf("%i", &range);
    if (range < 0){
        printf("WARNING!!!\n");
        range = 5;
    }

    Point fGrad;
    Point fSim;
    Point fGen;
    Point point;

    clock_t start, end;
    double timeGrad;
    double timeSim;
    double timeGen;

    for (int i = 0; i < numPoint; ++i){
        point.x = random_in_range(range); 
        point.y = random_in_range(range);
        point.f = arrFunc[choice - 1](point.x, point.y);
        printf("\nValue function in starting points x0 = %.2f; y0 = %.2f  => f = %f\n", point.x, point.y, point.f);
        printf("--------------------------------------------------------------\n");

        start = clock();
        fGrad = grad_descent(arrFunc[choice - 1], point, choice);
        end = clock();
        timeGrad = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        fSim = simulated_annealing(arrFunc[choice - 1], point);
        end = clock();
        timeSim = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        fGen = genetic_algorithm(arrFunc[choice - 1], point);
        end = clock();
        timeGen = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("--Function--\t\t --Value--\t --x-- \t\t  --y-- \t --time-- \n");
        printf("Gradient descent:\t %f\t%f\t%f\t%f\n",fGrad.f, fGrad.x, fGrad.y, timeGrad);
        printf("Simulated annealing:\t %f\t%f\t%f\t%f\n", fSim.f, fSim.x, fGen.y, timeSim);
        printf("Genetic algorithm:\t %f\t%f\t%f\t%f\n", fGen.f, fGen.x, fGen.y, timeGen); 
        printf("==============================================================\n");
    }
    
    return 0;
}
