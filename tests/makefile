# Makefile to run speed tests for .c and .cpp files

C_SOURCES := $(wildcard speed_tests/*.c)
CPP_SOURCES := $(wildcard speed_tests/*.cpp)

CC := gcc
CXX := g++
CFLAGS := 
CXXFLAGS := 

all: run_tests

run_tests:
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

clean:
	rm -f speed_tests/bin