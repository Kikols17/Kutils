# use gcc as compiler
CC = gcc

# enable all warnings
CFLAGS = -Wall -Wextra -Werror


# name of the shared library
LIB_NAME = Kutils



# get all the src c files
SRC_CFILES = $(shell find src -type f -name "*.c")

# get all the src h files
SRC_HFILES = $(shell find src -type f -name "*.h")

# get all the .so files that need to be created
SO_FILES = $(patsubst src/%.c, build/%.so, $(SRC_CFILES))

# get all the .o files that need to be created
O_FILES = $(patsubst src/%.c, build/%.o, $(SRC_CFILES))





# set target
all: build


# compile all the c files
build/%.o: src/%.c src/%.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@
	cp src/$*.h build/$*.h

# turn .o files into shared libraries
build/%.so: build/%.o
	mkdir -p $(dir $@)
	$(CC) -shared -o $@ $<

# compile all files
build: $(SO_FILES) $(O_FILES)
	@echo "\033[0;32mAll files compiled\033[0m"



# clean the build directory, and all its files
clean:
	rm -rf build