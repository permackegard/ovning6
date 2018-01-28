CC = gcc

libpower.so:	power.c power.h
		$(CC) -c -fPIC power.c
		$(CC) -shared -fPIC -o libpower.so power.o
