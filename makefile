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

# get all .so files that will be created from the .o files
SO_FILES = $(O_FILES:.o=.so)





# default target
all: build


# compile all files to .so
build: setup_build $(O_FILES) $(SO_FILES) $(H_FILES:src/%=build/%)
	# $(CC) -shared -fPIC -o build/l$(LIB_NAME).so $(O_FILES) -lc


# compile files to .o from .c files
build/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@


# compile files to .so from .o files without destroying the .o files
build/%.so: build/%.o
	$(CC) -shared -o $@ $< -lc


# copy the .h files to the /build directory
build/%.h: src/%.h
	cp $< $@


# create /build dir and mirror the directory structure of /src in /build
setup_build: $(SRC_DIRS)
	mkdir -p build
	$(foreach dir, $(SRC_DIRS), mkdir -p build/$(dir:src/%=%);)




# clean the build directory, and all its files
clean:
	rm -rf build