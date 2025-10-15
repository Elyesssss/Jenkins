CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

all: $(BUILD_DIR) tri_bulles tri_chaines tri_complet

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Programme complet (entiers + chaînes)
tri_complet: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_bulles.c $(SRC_DIR)/tri_chaines.c $(SRC_DIR)/main_complet.c -o $(BUILD_DIR)/tri_complet

# Programme tri d'entiers uniquement
tri_bulles: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_bulles.c $(SRC_DIR)/main.c -o $(BUILD_DIR)/tri_bulles

# Programme tri de chaînes uniquement
tri_chaines: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_chaines.c $(SRC_DIR)/main_chaines.c -o $(BUILD_DIR)/tri_chaines

# Tests tri d'entiers
test_bulles: $(BUILD_DIR)
	@echo "=== Tests tri d'entiers ==="
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_DIR)/test_tri_bulles.c $(SRC_DIR)/tri_bulles.c -o $(BUILD_DIR)/test_tri_bulles
	./$(BUILD_DIR)/test_tri_bulles

# Tests tri de chaînes
test_chaines: $(BUILD_DIR)
	@echo ""
	@echo "=== Tests tri de chaînes ==="
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_DIR)/test_tri_chaines.c $(SRC_DIR)/tri_chaines.c -o $(BUILD_DIR)/test_tri_chaines
	./$(BUILD_DIR)/test_tri_chaines

# Tous les tests
test: test_bulles test_chaines

# Exécuter le programme complet
run: tri_complet
	./$(BUILD_DIR)/tri_complet

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test test_bulles test_chaines run clean