CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

all: $(BUILD_DIR) tri_bulles

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compiler le programme principal avec main.c
tri_bulles: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_bulles.c $(SRC_DIR)/main.c -o $(BUILD_DIR)/tri_bulles

# Compiler les tests (sans main.c)
test: $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_DIR)/test_tri_bulles.c $(SRC_DIR)/tri_bulles.c -o $(BUILD_DIR)/test_tri_bulles
	./$(BUILD_DIR)/test_tri_bulles

run: tri_bulles
	./$(BUILD_DIR)/tri_bulles

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test run clean