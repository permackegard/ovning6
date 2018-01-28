CC = gcc

libcomponent.so:	component.c component.h 
		$(CC) -c -fPIC component.c
		$(CC) -shared -fPIC -o libcomponent.so component.o
