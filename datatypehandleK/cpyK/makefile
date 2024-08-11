# compile .DEBUG.c to test code in cpy_Kutils.c and cpy_Kutils.h
debug: .DEBUG.c cpy_Kutils.o
	gcc -o cpy_Kutils.DEBUG .DEBUG.c cpy_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
swap_Kutils.o: cpy_Kutils.c cpy_Kutils.h
	gcc -c cpy_Kutils.c -o cpy_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o