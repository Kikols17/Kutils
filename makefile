SRC_DIR := src
BIN_DIR := bin
TARGET := $(BIN_DIR)/libmylibrary.so

# Find all source files in the src directory and its subdirectories
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRCS))

# Find all header files in the src directory and its subdirectories
HEADERS := $(shell find $(SRC_DIR) -name '*.h')

CFLAGS := -fPIC -Wall -Wextra
LDFLAGS := -shared

all: $(TARGET) copy_headers

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

# Create the necessary directories in bin/
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

copy_headers: $(HEADERS)
	@mkdir -p $(BIN_DIR)
	cp $^ $(BIN_DIR)

build: $(BIN_DIR)/$(file).o

$(BIN_DIR)/$(file).o: $(SRC_DIR)/$(file).c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean copy_headers build
create_header: $(TARGET)
	@echo "Creating header file for the library..."
	@echo "#ifndef MYLIBRARY_H" > $(BIN_DIR)/mylibrary.h
	@echo "#define MYLIBRARY_H" >> $(BIN_DIR)/mylibrary.h
	@echo "" >> $(BIN_DIR)/mylibrary.h
	@for header in $(HEADERS); do \
		cat $$header >> $(BIN_DIR)/mylibrary.h; \
		echo "" >> $(BIN_DIR)/mylibrary.h; \
	done
	@echo "#endif // MYLIBRARY_H" >> $(BIN_DIR)/mylibrary.h

all: $(TARGET) copy_headers create_header

clean:
	rm -rf $(BIN_DIR)