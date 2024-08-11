# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
debug: .DEBUG.c sort_Kutils.o ../../datatypehandleK/swapK/swap_Kutils.o ../../datatypehandleK/cmpK/cmp_Kutils.o
	gcc -o sort_Kutils.DEBUG .DEBUG.c sort_Kutils.o ../../datatypehandleK/swapK/swap_Kutils.o ../../datatypehandleK/cmpK/cmp_Kutils.o

# compile .DEBUG.c to test code in sort_Kutils.c and sort_Kutils.h
sort_Kutils.o: sort_Kutils.c sort_Kutils.h
	gcc -c sort_Kutils.c -o sort_Kutils.o

# compile ../../datatypehandleK/swapK/swap_Kutils.c and ../../datatypehandleK/swapK/swap_Kutils.h
../../datatypehandleK/swapK/swap_Kutils.o: ../../datatypehandleK/swapK/swap_Kutils.c ../../datatypehandleK/swapK/swap_Kutils.h
	gcc -c ../../datatypehandleK/swapK/swap_Kutils.c -o ../../datatypehandleK/swapK/swap_Kutils.o

#compile ../../datatypehandleK/cmpK/cmp_Kutils.c and ../../datatypehandleK/cmpK/cmp_Kutils.h
../../datatypehandleK/cmpK/cmp_Kutils.o: ../../datatypehandleK/cmpK/cmp_Kutils.c ../../datatypehandleK/cmpK/cmp_Kutils.h
	gcc -c ../../datatypehandleK/cmpK/cmp_Kutils.c -o ../../datatypehandleK/cmpK/cmp_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o
	rm -f ../../datatypehandleK/swapK/*.o
	rm -f ../../datatypehandleK/cmpK/*.o