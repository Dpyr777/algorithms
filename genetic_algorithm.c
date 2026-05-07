#include <stdlib.h>
#include "types.h"
#include "functions.h"
#include "random_in_range.h"
#include "algorithms.h"

#define SIZE_POP 100
#define GENERATIONS 1000

Point interbreeding(func_ptr function, Point parent1, Point parent2){
    Point child;
    // выбираем рандомным обзам от кого берем больше от parent1 или parent2
    double factor = (double)rand() / RAND_MAX;
    child.x = parent1.x * factor + parent2.x * (1 - factor);
    child.y = parent1.y * factor + parent2.y * (1 - factor);
    child.f = function(child.x, child.y);

    return child;
}

Point population[SIZE_POP]; 
Point newPolulation[SIZE_POP];

Point individualBest;

void find_best(){
    individualBest = population[0]; 
    double fMin = population[0].f;
    for (int i = 1; i < SIZE_POP; ++i){
        if (population[i].f < individualBest.f){
            individualBest = population[i];
        }
    }
}

Point tournament(){
    int pop1 = rand() % SIZE_POP;
    int pop2 = rand() % SIZE_POP;
    
    if (population[pop1].f < population[pop2].f){
        return population[pop1];
    }
    return population[pop2];
}

Point genetic_algorithm(func_ptr function, Point point){
    // инициализируем популяцию рандомными числами в диопозоне
    // но заполняю я одинаковыми для тестов
    for (int i = 0; i < SIZE_POP; ++i){
#if 0
        population[i].x = random_in_range(100);
        population[i].y = random_in_range(100); 
        population[i].f = function(population[i].x, population[i].y);
#endif
        population[i] = point;
    }
    for (int gen = 0; gen < GENERATIONS; ++gen){
        // ищем лучшее решение и ставим его первым
        find_best();
        // передаем в следующее поколение лучшее решение
        newPolulation[0] = individualBest;
        // создаем потомков
        for (int i = 1; i < SIZE_POP; ++i){
            // выбираем из двух случайных решений лучшее для каждого
            Point parent1 = tournament();
            Point parent2 = tournament();
            // соединяем родителей и берем от них рандомную часть
            Point child = interbreeding(function, parent1, parent2);
            // мутация с шансом 50%
            if ((rand() & 1) == 1){
                child.x += ((double)rand() / RAND_MAX - (double)rand() / RAND_MAX);
                child.y += ((double)rand() / RAND_MAX - (double)rand() / RAND_MAX);
                child.f = function(child.x, child.y);
            } 
            newPolulation[i] = child;
        }

        // обнавляем первоначальный массив
        for (int i = 0; i < SIZE_POP; ++i){
            population[i] = newPolulation[i];
        }
    }

    find_best();

   return individualBest;
}
