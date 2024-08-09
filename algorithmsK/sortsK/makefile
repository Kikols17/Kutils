# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
debug: .DEBUG.c sort_Kutils.o
	gcc -o sort_Kutils.DEBUG .DEBUG.c sort_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
sort_Kutils.o: sort_Kutils.c sort_Kutils.h
	gcc -c sort_Kutils.c -o sort_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o