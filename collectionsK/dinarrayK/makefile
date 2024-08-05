# compile .DEBUG.c to test code in dinarray_Kutils.c and dinarray_Kutils.h

debug: .DEBUG.c dinarray_Kutils.o
	gcc -o dinarray_Kutils.DEBUG .DEBUG.c dinarray_Kutils.o


# create object file for dinarray_Kutils.c and dinarray_Kutils.h
dinarray_Kutils.o: dinarray_Kutils.c dinarray_Kutils.h
	gcc -c dinarray_Kutils.c

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o