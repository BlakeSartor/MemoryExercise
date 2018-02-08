CFLAGS = -Wall -g
CC = gcc $(CFLAGS)

lab2: lab2.o lab2.h
	$(CC) -o lab2 lab2.o

lab2.o: lab2.c
	$(CC) -c $<


clean:
	rm -f *.o

clean_all:
	rm -f *.o lab2
