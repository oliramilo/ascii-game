CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = map.o main.o 
EXEC = game

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : map.c 
	$(CC) -c main.c $(CLFAGS)

clean:
	rm -f game map.o main.o
