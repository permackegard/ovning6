CC = gcc
CFLAGS = -g -Wall -Werror
OBJS = main.o


PROG = electrotest
LOCALLIBDIR = /usr/lib
INSTALLDIR = /usr/bin
LDFLAGS = -L$(LOCALLIBDIR)

LIBRESISTANCE = libs/resistance/libresistance.so
LIBCOMPONENT = libs/component/libcomponent.so

# For "local installation"

# Resistance lib
RESISTANCE_LIBFLAG = -L./libs/resistance -lresistance -Wl,-rpath,'./libs/resistance'
# Power lib
POWER_LIBFLAG = -L./libs/power -lpower -Wl,-rpath,'./libs/power'
# Component lib
COMPONENT_LIBFLAG = -L./libs/component -lcomponent -Wl,-rpath,'./libs/component'


# For "public installation"

# Resistance lib
RESISTANCE_LIBFLAG_PUBLIC = -L$(LOCALLIBDIR) -lresistance -Wl,-rpath,'$(LOCALLIBDIR)'
# Power lib
POWER_LIBFLAG_PUBLIC = -L$(LOCALLIBDIR) -lpower -Wl,-rpath,'$(LOCALLIBDIR)'
# Component lib
COMPONENT_LIBFLAG_PUBLIC = -L$(LOCALLIBDIR) -lcomponent -Wl,-rpath,'$(LOCALLIBDIR)'



lib:		libs/resistance/resistance.c #libs/power/power.c libs/component/component.c
			# Resistance
			$(CC) -c -fPIC libs/resistance/resistance.c -o libs/resistance/resistance.o
			$(CC) -shared -fPIC -o libs/resistance/libresistance.so libs/resistance/resistance.o
			# Power
			$(CC) -c -fPIC libs/power/power.c -o libs/power/power.o
			$(CC) -shared -fPIC -o libs/power/libpower.so libs/power/power.o
			# Component
			$(CC) -c -fPIC libs/component/component.c -o libs/component/component.o
			$(CC) -shared -fPIC -o libs/component/libcomponent.so libs/component/component.o


all:		main.c
			$(CC) $(CFLAGS) -o $(PROG) main.c $(RESISTANCE_LIBFLAG) $(COMPONENT_LIBFLAG) $(POWER_LIBFLAG) # Add rest of libs here

install:
			sudo rm -f *~ *.o $(PROG) # just to be sure that $(PROG) is rebuilt later. Is this necessary?
	 		sudo install -m 0755 $(LIBRESISTANCE) $(LIBCOMPONENT) $(POWER_LIBFLAG) $(LOCALLIBDIR) # copies the libraries. Add your libs here
	 		$(CC) $(CFLAGS) -o $(PROG) main.c $(RESISTANCE_LIBFLAG_PUBLIC) $(COMPONENT_LIBFLAG_PUBLIC) $(POWER_LIBFLAG_PUBLIC) # add your libs here
	 		sudo install -m 0755 $(PROG) $(INSTALLDIR)

uninstall:
			sudo rm -f $(INSTALLDIR)/$(PROG)

clean:
			sudo rm -f *~ *.o $(PROG)
