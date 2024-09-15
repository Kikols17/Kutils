# use gcc as compiler
CC = gcc

# enable all warnings
CFLAGS = -Wall -Wextra -Werror


# get all dirs inside the /src directory and exclude the /src directory itself
SRC_DIRS = $(shell find src -type d -not -path "src")

# get all .c files inside the /src directory
SRC_FILES = $(shell find src -type f -name "*.c")

# get all .h files inside the /src directory
HEADER_FILES = $(shell find src -type f -name "*.h")




# compile all .c files in /src and mirror the directory structure in /build
build: setup_build $(SRC_FILES)
	$(foreach file, $(SRC_FILES), $(CC) $(CFLAGS) -c $(file) -o build/$(file:src/%.c=%.o);)


# create /build dir and mirror the directory structure of /src in /build
setup_build: $(SRC_DIRS)
	mkdir -p build
	$(foreach dir, $(SRC_DIRS), mkdir -p build/$(dir:src/%=%);)



# clean the build directory, and all its files
clean:
	rm -rf build