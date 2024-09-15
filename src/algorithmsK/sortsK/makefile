# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
debug: .DEBUG.c sort_Kutils.o ../../datatypehandleK/swapK/swapSTD_Kutils.o ../../datatypehandleK/cmpK/cmpSTD_Kutils.o
	gcc -o sort_Kutils.DEBUG .DEBUG.c sort_Kutils.o ../../datatypehandleK/swapK/swapSTD_Kutils.o ../../datatypehandleK/cmpK/cmpSTD_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
sort_Kutils.o: sort_Kutils.c sort_Kutils.h
	gcc -c sort_Kutils.c -o sort_Kutils.o

# compile ../../datatypehandleK/swapK/swapSTD_Kutils.c and ../../datatypehandleK/swapK/swapSTD_Kutils.h
../../datatypehandleK/swapK/swapSTD_Kutils.o: ../../datatypehandleK/swapK/swapSTD_Kutils.c ../../datatypehandleK/swapK/swapSTD_Kutils.h
	gcc -c ../../datatypehandleK/swapK/swapSTD_Kutils.c -o ../../datatypehandleK/swapK/swapSTD_Kutils.o

#compile ../../datatypehandleK/cmpK/cmpSTD_Kutils.c and ../../datatypehandleK/cmpK/cmpSTD_Kutils.h
../../datatypehandleK/cmpK/cmpSTD_Kutils.o: ../../datatypehandleK/cmpK/cmpSTD_Kutils.c ../../datatypehandleK/cmpK/cmpSTD_Kutils.h
	gcc -c ../../datatypehandleK/cmpK/cmpSTD_Kutils.c -o ../../datatypehandleK/cmpK/cmpSTD_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o
	rm -f ../../datatypehandleK/swapK/*.o
	rm -f ../../datatypehandleK/cmpK/*.o