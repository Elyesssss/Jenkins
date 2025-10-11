CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

all: $(BUILD_DIR) tri_bulles tri_chaines

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compiler le programme principal avec tri d'entiers
tri_bulles: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_bulles.c $(SRC_DIR)/main.c -o $(BUILD_DIR)/tri_bulles

# Compiler le programme de tri de chaînes
tri_chaines: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_chaines.c $(SRC_DIR)/main_chaines.c -o $(BUILD_DIR)/tri_chaines

# Compiler et exécuter tous les tests
test: test_bulles test_chaines

# Tests pour tri d'entiers
test_bulles: $(BUILD_DIR)
	@echo "=== Tests tri d'entiers ==="
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_DIR)/test_tri_bulles.c $(SRC_DIR)/tri_bulles.c -o $(BUILD_DIR)/test_tri_bulles
	./$(BUILD_DIR)/test_tri_bulles

# Tests pour tri de chaînes
test_chaines: $(BUILD_DIR)
	@echo ""
	@echo "=== Tests tri de chaînes ==="
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_DIR)/test_tri_chaines.c $(SRC_DIR)/tri_chaines.c -o $(BUILD_DIR)/test_tri_chaines
	./$(BUILD_DIR)/test_tri_chaines

# Exécuter le programme de tri d'entiers
run: tri_bulles
	@echo "=== Exécution tri d'entiers ==="
	./$(BUILD_DIR)/tri_bulles

# Exécuter le programme de tri de chaînes
run_chaines: tri_chaines
	@echo "=== Exécution tri de chaînes ==="
	./$(BUILD_DIR)/tri_chaines

# Exécuter les deux programmes
run_all: tri_bulles tri_chaines
	@echo "=== Exécution tri d'entiers ==="
	./$(BUILD_DIR)/tri_bulles
	@echo ""
	@echo "=== Exécution tri de chaînes ==="
	./$(BUILD_DIR)/tri_chaines

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test test_bulles test_chaines run run_chaines run_all clean