# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
debug: .DEBUG.c cmp_Kutils.o
	gcc -o cmp_Kutils.DEBUG .DEBUG.c cmp_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
swap_Kutils.o: cmp_Kutils.c cmp_Kutils.h
	gcc -c cmp_Kutils.c -o cmp_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o