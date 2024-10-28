CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c18
INCLUDES = -I . -I ./
OUTPUT_DIR = ./
SRC_DIR = ./
CASE_NUM = 1

all: build run

build: pilha.o n_queens_pilha.o
	$(CC) $(CFLAGS) $(INCLUDES) $(OUTPUT_DIR)*.o -o $(OUTPUT_DIR)n_queens_pilha.exe

run:
	$(OUTPUT_DIR)n_queens_pilha.exe

clean:
	rm -f $(OUTPUT_DIR)*.o $(OUTPUT_DIR)*.exe $(OUTPUT_DIR)*.out

rebuild: clean build run

n_queens_pilha.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c n_queens_pilha.c -o $(OUTPUT_DIR)n_queens_pilha.o

pilha.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)pilha.c -o $(OUTPUT_DIR)pilha.o

run_test_case:
	$(OUTPUT_DIR)n_queens_pilha.exe < ./testCases/$(CASE_NUM).in > $(OUTPUT_DIR)test_case_output.out
