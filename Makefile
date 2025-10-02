CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Cibles principales
all: $(BUILD_DIR) tri_bulles

# Créer le dossier build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compiler le programme principal
tri_bulles: $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/tri_bulles.c -o $(BUILD_DIR)/tri_bulles

# Compiler et exécuter les tests
test: $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_DIR)/test_tri_bulles.c $(SRC_DIR)/tri_bulles.c -DTEST_MODE -o $(BUILD_DIR)/test_tri_bulles
	./$(BUILD_DIR)/test_tri_bulles

# Exécuter le programme
run: tri_bulles
	./$(BUILD_DIR)/tri_bulles

# Nettoyer les fichiers compilés
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test run clean