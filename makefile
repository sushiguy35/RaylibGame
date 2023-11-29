CC = gcc
MF = src/main.c
LIB = -lraylib -lm
O = main

compile:
	$(CC) $(MF) -o $(O) $(LIB)

run:
	./main
