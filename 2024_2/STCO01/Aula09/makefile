CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c18
INCLUDES = -I . -I ./
OUTPUT_DIR = ./
SRC_DIR = ./

all: build run

build: fila.o main.o
	$(CC) $(CFLAGS) $(INCLUDES) $(OUTPUT_DIR)*.o -o $(OUTPUT_DIR)main.exe

run:
	$(OUTPUT_DIR)main.exe

clean:
	rm $(OUTPUT_DIR)*.o $(OUTPUT_DIR)*.exe

rebuild: clean build run

main.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c -o $(OUTPUT_DIR)main.o

fila.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)fila.c -o $(OUTPUT_DIR)fila.o
