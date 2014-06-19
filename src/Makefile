.PHONY: all clean

FLAGS = -Wall -pedantic -error -lm -g -m32
CC = gcc
OBJ = main.o jvm.o logger.o scheduler.o utils/map.o

jvm: $(OBJ)
	$(CC) -o $@ $^ $(FLAGS)

all:
	cd utils; make all;
	cd ../classfile; make all;
	cd ..;

.c.o:
	$(CC) -c $< $(FLAGS)

clean:
	rm *.o jvm