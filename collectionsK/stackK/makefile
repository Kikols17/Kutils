# compile .DEBUG.c to test code in dinarray_Kutils.c and dinarray_Kutils.h

debug: .DEBUG.c stack_Kutils.o ../dinarrayK/dinarray_Kutils.o ../vectorK/vector_Kutils.o
	gcc -o stack_Kutils.DEBUG .DEBUG.c stack_Kutils.o ../dinarrayK/dinarray_Kutils.o ../vectorK/vector_Kutils.o


# create object file for vector_Kutils.c and vector_Kutils.h
stack_Kutils.o: stack_Kutils.c stack_Kutils.h
	gcc -c stack_Kutils.c

# create object file for dinarray_Kutils.c and dinarray_Kutils.h
../dinarrayK/dinarray_Kutils.o: ../dinarrayK/dinarray_Kutils.c ../dinarrayK/dinarray_Kutils.h
	gcc -c ../dinarrayK/dinarray_Kutils.c -o ../dinarrayK/dinarray_Kutils.o

# create object file for vector_Kutils.c and vector_Kutils.h
../vectorK/vector_Kutils.o: ../vectorK/vector_Kutils.c ../vectorK/vector_Kutils.h
	gcc -c ../vectorK/vector_Kutils.c -o ../vectorK/vector_Kutils.o


# remove the executable file
clean:
	rm -f *.DEBUG
	rm -f *.o
	rm -f ../dinarrayK/*.o
	rm -f ../vectorK/*.o