CC = gcc

libresistance.so:	resistance.c resistance.h 
		$(CC) -c -fPIC resistance.c
		$(CC) -shared -fPIC -o libresistance.so resistance.o
