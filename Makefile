all: algo

algo: main.o grad_descent.o simulated_annealing.o genetic_algorithm.o functions.o random_in_range.o derivative.o
	gcc $^ -o $@ -lm

main.o: main.c
	gcc -c $<

grad_descent.o: grad_descent.c
	gcc -c $<

simulated_annealing.o: simulated_annealing.c
	gcc -c $<

genetic_algorithm.o: genetic_algorithm.c
	gcc -c $<

functions.o: functions.c
	gcc -c $<

random_in_range.o: random_in_range.c
	gcc -c $<

derivative.o: derivative.c
	gcc -c $<


clean:
	rm -rf *.o algo

run: algo
	./$<



