#SRC_DIR := src
#BUILD_DIR := build
#
## Find all .h files in SRC_DIR and its subdirectories
#HEADERS := $(shell find $(SRC_DIR) -name '*.h')
#
## Create a list of target files in the BUILD_DIR root
#TARGETS := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(HEADERS))
#
## Update the list of targets to include combined .h files
#COMBINED_HEADERS := $(foreach dir,$(shell find $(SRC_DIR) -type d),$(BUILD_DIR)/$(notdir $(dir)).h)
#
#
## Update the default target
#all: $(TARGETS) $(COMBINED_HEADERS)
#	echo $(COMBINED_HEADERS)
#
#
## Rule to copy .h files to the build directory root
#$(BUILD_DIR)/%: $(SRC_DIR)/% | $(BUILD_DIR)
#	cp $(SRC_DIR)/$* $(BUILD_DIR)/$(notdir $@)
#
## Ensure the build directory exists
#$(BUILD_DIR):
#	@mkdir -p $(BUILD_DIR)
#
## Rule to create a combined .h file for each directory
#$(BUILD_DIR)/%.h: $(SRC_DIR)/%/ $(shell find $(SRC_DIR)/* -name '*.h') | $(BUILD_DIR)
#	@mkdir -p $(dir $@)
#	cat $(shell find $(SRC_DIR)/$* -name '*.h') > $@
#
#
#
#
#
## Clean target to remove the build directory
#clean:
#	rm -rf $(BUILD_DIR)
#
#
#.PHONY: all clean


SRC_DIR := src
BUILD_DIR := build

# find all directories in SRC_DIR
DIRS := $(shell find $(SRC_DIR) -type d)

# find all .h files in SRC_DIR and its subdirectories
HEADERS := $(shell find $(SRC_DIR) -name '*.h')


all: $(DIRS)


# for all directories in DIRS, create a combined .h file. Do not preserve the directory structure, and call the combined .h file the name of the directory
$(DIRS): $(BUILD_DIR)
	@if [ -n "$(shell find $@ -name '*.h')" ]; then \
		if [ "$(notdir $@)" = "src" ]; then \
			echo "cat $(shell find $@ -name '*.h') > $(BUILD_DIR)/Kutils.h"; \
			cat $(shell find $@ -name '*.h') > $(BUILD_DIR)/Kutils.h; \
		else \
			echo "cat $(shell find $@ -name '*.h') > $(BUILD_DIR)/$(notdir $@).h"; \
			cat $(shell find $@ -name '*.h') > $(BUILD_DIR)/$(notdir $@).h; \
		fi \
	fi

# ensure the build directory exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)


clean:
	rm -rf $(BUILD_DIR)