CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

all: $(BUILD_DIR) tri_bulles tri_chaines

$(BUILD_DIR):
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# Programme tri d'entiers
tri_bulles: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_bulles.c $(SRC_DIR)/main_bulles.c -o $(BUILD_DIR)/tri_bulles

# Programme tri de chaînes
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

# Exécuter les deux programmes
run: tri_bulles tri_chaines
	@echo "=== Exécution du tri à bulles ==="
	./$(BUILD_DIR)/tri_bulles
	@echo ""
	@echo "=== Exécution du tri de chaînes ==="
	./$(BUILD_DIR)/tri_chaines

clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR) 2>nul || echo Dossier build supprimé

.PHONY: all test test_bulles test_chaines run clean