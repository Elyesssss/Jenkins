#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "tri_bulles.h"

// Fonction utilitaire pour comparer deux tableaux
int tableaux_egaux(int tab1[], int tab2[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        if (tab1[i] != tab2[i]) {
            return 0;
        }
    }
    return 1;
}

void test_tri_simple() {
    printf("Test 1: Tri simple... ");
    int tableau[] = {5, 2, 8, 1, 9};
    int attendu[] = {1, 2, 5, 8, 9};
    int taille = 5;
    
    tri_bulles(tableau, taille);
    
    assert(tableaux_egaux(tableau, attendu, taille));
    printf("OK\n");
}

void test_tri_deja_trie() {
    printf("Test 2: Tableau déjà trié... ");
    int tableau[] = {1, 2, 3, 4, 5};
    int attendu[] = {1, 2, 3, 4, 5};
    int taille = 5;
    
    tri_bulles(tableau, taille);
    
    assert(tableaux_egaux(tableau, attendu, taille));
    printf("OK\n");
}

void test_tri_inverse() {
    printf("Test 3: Tableau trié en ordre inverse... ");
    int tableau[] = {5, 4, 3, 2, 1};
    int attendu[] = {1, 2, 3, 4, 5};
    int taille = 5;
    
    tri_bulles(tableau, taille);
    
    assert(tableaux_egaux(tableau, attendu, taille));
    printf("OK\n");
}

void test_tri_doublons() {
    printf("Test 4: Tableau avec doublons... ");
    int tableau[] = {3, 5, 3, 1, 5};
    int attendu[] = {1, 3, 3, 5, 5};
    int taille = 5;
    
    tri_bulles(tableau, taille);
    
    assert(tableaux_egaux(tableau, attendu, taille));
    printf("OK\n");
}

void test_tri_un_element() {
    printf("Test 5: Tableau avec un seul élément... ");
    int tableau[] = {42};
    int attendu[] = {42};
    int taille = 1;
    
    tri_bulles(tableau, taille);
    
    assert(tableaux_egaux(tableau, attendu, taille));
    printf("OK\n");
}

int main() {
    printf("=== Exécution des tests ===\n\n");
    
    test_tri_simple();
    test_tri_deja_trie();
    test_tri_inverse();
    test_tri_doublons();
    test_tri_un_element();
    
    printf("\n=== Tous les tests sont passés avec succès ! ===\n");
    return 0;
}