# Makefile to run speed tests for .c and .cpp files

C_SOURCES := $(wildcard speed_tests/*.c)
CPP_SOURCES := $(wildcard speed_tests/*.cpp)

CC := gcc
CXX := g++
CFLAGS := 
CXXFLAGS := 

all: speed_tests

# tests speed by running the STD and Kutils versions of the same test, and comparing
speed_tests:
	@for test in $(C_SOURCES:.c=); do \
		echo "Running $$test:"; \
		for input in `cat $$test.txt`; do \
			echo -n "\t$$input:\t"; \
			$(CC) $(CFLAGS) -o bin $$test.c -I ../build/; \
			time -p ./bin $$input 2>&1 | grep real | awk '{print $$2 "s"}' | tr -d '\n'; \
			echo -n " - "; \
			$(CXX) $(CXXFLAGS) -o bin $$test.cpp; \
			time -p ./bin $$input 2>&1 | grep real | awk '{print $$2 "s"}' | tr -d '\n'; \
			echo ""; \
		done; \
		echo "\n"; \
	done
	rm -f bin


# tests the validity of the STD and Kutils versions of the same test and comparing outputs
validity_tests:
	@for test in $(C_SOURCES:.c=); do \
		echo "Running $$test:"; \
		for input in `cat $$test.txt`; do \
			echo -n "\t$$input:\t"; \
			$(CC) $(CFLAGS) -o bin $$test.c -I ../build/; \
			./bin $$input > std_output.txt; \
			$(CXX) $(CXXFLAGS) -o bin $$test.cpp; \
			./bin $$input > kutils_output.txt; \
			diff std_output.txt kutils_output.txt; \
		done; \
		echo "\n"; \
	done
	

clean:
	rm -f bin