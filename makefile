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

# get all the folders in src
SRC_DIRS = $(shell find src -type d -not -path "src")



# get all the build o files
BUILD_OFILES = $(patsubst src/%.c, build/%.o, $(SRC_CFILES))

# get all the build so files
BUILD_SOFILES = $(patsubst build/%.o, build/%lib%.so, $(BUILD_OFILES))

# get all the build h files
BUILD_HFILES = $(SRC_HFILES:src/%=build/%)

# get all the build folders
BUILD_DIRS = $(SRC_DIRS:src/%=build/%)





# set target
all: build



# setup the build directory, and mirror the src dirs structure
build_setup:
	mkdir -p build
	$(foreach dir, $(BUILD_DIRS), mkdir -p $(dir);)



# create the headers in the build directory
build/%.h: src/%.h
	cp $< $@

# create the object files in the build directory
build/%.o: src/%.c build/%.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# create the .so files in the build directory
build/%lib%.so: build/%.o
	$(CC) -shared -o $@ $<


# compile all the source files
build: build_setup $(BUILD_HFILES) $(BUILD_SOFILES)
	# $(CC) -shared -o build/lib$(LIB_NAME).so $(BUILD_SOFILES)




# clean the build directory, and all its files
clean:
	rm -rf build