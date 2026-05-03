#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "genetic_algorithm.h"
#include "get_random_start_point.h"
#include "rosenbrock.h"

#define SIZE_POP 100
#define GENERATIONS 1000

struct Ind {
    double x;
    double y;
    double f;
};
struct Ind interbreeding(struct Ind parent1, struct Ind parent2){
    struct Ind child;
    // выбираем рандомным обзам от кого берем больше от parent1 или parent2
    double factor = (double)rand() / RAND_MAX;
    child.x = parent1.x * factor + parent2.x * (1 - factor);
    child.y = parent1.y * factor + parent2.y * (1 - factor);
    child.f = rosenbrock(child.x, child.y);

    return child;
}

struct Ind population[SIZE_POP]; 
struct Ind newPolulation[SIZE_POP];

struct Ind individualBest;

void find_best(){
    individualBest = population[0]; 
    double fMin = population[0].f;
    for (int i = 1; i < SIZE_POP; ++i){
        if (population[i].f < individualBest.f){
            individualBest = population[i];
        }
    }
}

struct Ind tournament(){
    int pop1 = rand() % SIZE_POP;
    int pop2 = rand() % SIZE_POP;
    
    if (population[pop1].f < population[pop2].f){
        return population[pop1];
    }
    return population[pop2];
}

double genetic_algorithm(char* function, double xNew, double yNew){
    population[0].x = xNew;
    population[0].y = yNew;
    population[0].f = rosenbrock(population[0].x, population[0].y);
    // инициализируем популяцию рандомными числами в диопозоне
    for (int i = 1; i < SIZE_POP; ++i){
        population[i].x = get_random_start_point(100, false); 
        population[i].y = get_random_start_point(100, false); 
        population[i].f = rosenbrock(population[i].x, population[i].y); 
    }
    for (int gen = 0; gen < GENERATIONS; ++gen){
        // ищем лучшее решение и ставим его первым
        find_best();
        // передаем в следующее поколение лучшее решение
        newPolulation[0] = individualBest;
        // создаем потомков
        for (int i = 1; i < SIZE_POP; ++i){
            // выбираем из двух случайных решений лучшее для каждого
            struct Ind parent1 = tournament();
            struct Ind parent2 = tournament();
            // соединяем родителей и берем от них рандомную часть
            struct Ind child = interbreeding(parent1, parent2);
            // мутация с шансом 50%
            if ((rand() & 1) == 1){
                child.x += ((double)rand() / RAND_MAX - (double)rand() / RAND_MAX);
                child.y += ((double)rand() / RAND_MAX - (double)rand() / RAND_MAX);
                child.f = rosenbrock(child.x, child.y);
            } 
            newPolulation[i] = child;
        }

        // обнавляем первоначальный массив
        for (int i = 0; i < SIZE_POP; ++i){
            population[i] = newPolulation[i];
        }
    }
    find_best();

   return individualBest.f;
}
