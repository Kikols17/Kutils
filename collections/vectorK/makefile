# compile .DEBUG.c to test code in dinarray_Kutils.c and dinarray_Kutils.h

debug: .DEBUG.c vector_Kutils.o ../dinarrayK/dinarray_Kutils.o
	gcc -o vector_Kutils.DEBUG .DEBUG.c vector_Kutils.o ../dinarrayK/dinarray_Kutils.o


# create object file for vector_Kutils.c and vector_Kutils.h
vector_Kutils.o: vector_Kutils.c vector_Kutils.h
	gcc -c vector_Kutils.c

# create object file for dinarray_Kutils.c and dinarray_Kutils.h
../dinarrayK/dinarray_Kutils.o: ../dinarrayK/dinarray_Kutils.c ../dinarrayK/dinarray_Kutils.h
	gcc -c ../dinarrayK/dinarray_Kutils.c -o ../dinarrayK/dinarray_Kutils.o

# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o
	rm -f ../dinarrayK/*.o