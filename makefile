# use gcc as compiler
CC = gcc

# enable all warnings
CFLAGS = -Wall -Wextra -Werror


# name of the shared library
LIB_NAME = Kutils




# get all dirs inside the /src directory and exclude the /src directory itself
SRC_DIRS = $(shell find src -type d -not -path "src")

# get all .c files inside the /src directory
C_FILES = $(shell find src -type f -name "*.c")

# get all .h files inside the /src directory
H_FILES = $(shell find src -type f -name "*.h")

# get all .o files that will be created from the .c and .h files
O_FILES = $(C_FILES:src/%.c=build/%.o)





# default target
all: build


# compile all files to .so
build: setup_build $(O_FILES)
	$(CC) -shared -fPIC -o build/$(LIB_NAME).so $(O_FILES)


# compile files to .o from both .c and .h files
build/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@


# create /build dir and mirror the directory structure of /src in /build
setup_build: $(SRC_DIRS)
	mkdir -p build
	$(foreach dir, $(SRC_DIRS), mkdir -p build/$(dir:src/%=%);)



# clean the build directory, and all its files
clean:
	rm -rf build