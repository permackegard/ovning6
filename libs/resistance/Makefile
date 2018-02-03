CC = gcc
CFLAGS = -g -Wall -Werror
PROG = testProg

# Resistance lib
RESISTANCE_LIBFLAG = -L. -lresistance -Wl,-rpath,.

testProg:			main.c
					$(CC) $(CFLAGS) -o $(PROG) main.c $(RESISTANCE_LIBFLAG)

lib:				resistance.c resistance.h 
					$(CC) $(CFLAGS) -c -fPIC resistance.c
					$(CC) $(CFLAGS) -shared -fPIC -o libresistance.so resistance.o
