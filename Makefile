CC = gcc
CFLAGS = -g -Wall -Werror
OBJS = main.o


PROG = electrotest
LOCALLIBDIR = /usr/lib
INSTALLDIR = /usr/bin
LDFLAGS = -L$(LOCALLIBDIR)

LIBRESISTANCE_PATH = libs/resistance
LIBPOWER_PATH = libs/power
LIBCOMPONENT_PATH = libs/component

LIBRESISTANCE = libresistance.so
LIBPOWER = libpower.so
LIBCOMPONENT = libcomponent.so

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



lib:		$(LIBRESISTANCE_PATH)/resistance.c $(LIBPOWER_PATH)/power.c $(LIBCOMPONENT_PATH)/component.c
			# Resistance
			$(CC) -c -fPIC $(LIBRESISTANCE_PATH)/resistance.c -o $(LIBRESISTANCE_PATH)/resistance.o
			$(CC) -shared -fPIC -o $(LIBRESISTANCE_PATH)/$(LIBRESISTANCE) $(LIBRESISTANCE_PATH)/resistance.o
			# Power
			$(CC) -c -fPIC $(LIBPOWER_PATH)/power.c -o $(LIBPOWER_PATH)/power.o
			$(CC) -shared -fPIC -o $(LIBPOWER_PATH)/$(LIBPOWER) $(LIBPOWER_PATH)/power.o
			# Component
			$(CC) -c -fPIC $(LIBCOMPONENT_PATH)/component.c -o $(LIBCOMPONENT_PATH)/component.o
			$(CC) -shared -fPIC -o $(LIBCOMPONENT_PATH)/$(LIBCOMPONENT) $(LIBCOMPONENT_PATH)/component.o

all:		main.c
			$(CC) $(CFLAGS) -o $(PROG) main.c $(RESISTANCE_LIBFLAG) $(COMPONENT_LIBFLAG) $(POWER_LIBFLAG)

install:
			sudo rm -f *~ *.o $(PROG) # just to be sure that $(PROG) is rebuilt later.
	 		sudo install -m 0755 $(LIBRESISTANCE) $(LIBPOWER) $(LIBCOMPONENT) $(LOCALLIBDIR)
	 		$(CC) $(CFLAGS) -o $(PROG) main.c $(RESISTANCE_LIBFLAG_PUBLIC) $(POWER_LIBFLAG_PUBLIC) $(COMPONENT_LIBFLAG_PUBLIC)
	 		sudo install -m 0755 $(PROG) $(INSTALLDIR)

uninstall:
			sudo rm -f $(INSTALLDIR)/$(PROG)
			sudo rm -f $(LOCALLIBDIR)/$(LIBRESISTANCE)
			sudo rm -f $(LOCALLIBDIR)/$(LIBPOWER)
			sudo rm -f $(LOCALLIBDIR)/$(LIBCOMPONENT)

clean:
			sudo rm -f *~ *.o $(PROG)
			sudo rm -f $(LIBRESISTANCE)
			sudo rm -f $(LIBPOWER)
			sudo rm -f $(LIBCOMPONENT)
