CC = gcc

# For "local installation"

# Resistance lib
RESISTANCE_LIBFLAG = -L./libs/resistance -lresistance -Wl,-rpath,'./libs/resistance'
# Power lib
POWER_LIBFLAG = -L./libs/power -lpower -Wl,-rpath,'./libs/power'
# Component lib
COMPONENT_LIBFLAG = -L./libs/component -lcomponent -Wl,-rpath,'./libs/component'



lib:		libs/resistance/resistance.c libs/power/power.c libs/component/component.c
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
			$(CC) -o electrotest main.c $(RESISTANCE_LIBFLAG) # Add rest of libs here

install: 	main.c
		 	$(CC) -o electrotest main.c $(RESISTANCE_LIBFLAG) # Add rest of libs here	

