# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
debug: .DEBUG.c swapSTD_Kutils.o
	gcc -o swapSTD_Kutils.DEBUG .DEBUG.c swapSTD_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
swapSTD_Kutils.o: swapSTD_Kutils.c swapSTD_Kutils.h
	gcc -c swapSTD_Kutils.c -o swapSTD_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o