# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
debug: .DEBUG.c swap_Kutils.o
	gcc -o swap_Kutils.DEBUG .DEBUG.c swap_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
swap_Kutils.o: swap_Kutils.c swap_Kutils.h
	gcc -c swap_Kutils.c -o swap_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o