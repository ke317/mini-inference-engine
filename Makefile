
CC = gcc


.PHONY: run
run: main.c
	$(CC) -O3 -o main main.c -lm


.PHONY: debug
debug: main.c
	$(CC) -g -o main_debug main.c -lm


.PHONY: fast
fast: main.c
	$(CC) -Ofast -o main_fast main.c -lm


.PHONY: omp
omp: main.c
	$(CC) -Ofast -fopenmp -march=native main.c -lm -o main_omp


.PHONY: gnu
gnu: main.c
	$(CC) -Ofast -std=gnu11 -o main_gnu main.c -lm


.PHONY: test
test:
	pytest


.PHONY: clean
clean:
	rm -f main main_debug main_fast main_omp main_gnu
