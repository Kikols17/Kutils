# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
debug: .DEBUG.c cmpSTD_Kutils.o
	gcc -o cmpSTD_Kutils.DEBUG .DEBUG.c cmpSTD_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
cmpSTD_Kutils.o: cmpSTD_Kutils.c cmpSTD_Kutils.h
	gcc -c cmpSTD_Kutils.c -o cmpSTD_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o