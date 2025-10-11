#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "tri_chaines.h"

// Fonction utilitaire pour comparer deux tableaux de chaînes
int tableaux_chaines_egaux(char tab1[][MAX_LONGUEUR], char tab2[][MAX_LONGUEUR], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        if (strcmp(tab1[i], tab2[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

void test_tri_ascendant_simple() {
    printf("Test 1: Tri ascendant simple... ");
    char tableau[5][MAX_LONGUEUR] = {"zebra", "apple", "mango", "banana", "cherry"};
    char attendu[5][MAX_LONGUEUR] = {"apple", "banana", "cherry", "mango", "zebra"};
    StatsTri stats;
    int taille = 5;
    
    tri_bulles_chaines(tableau, taille, 1, &stats);
    
    assert(tableaux_chaines_egaux(tableau, attendu, taille));
    assert(stats.nb_comparaisons > 0);
    printf("OK (comparaisons: %d, échanges: %d)\n", stats.nb_comparaisons, stats.nb_echanges);
}

void test_tri_descendant() {
    printf("Test 2: Tri descendant... ");
    char tableau[5][MAX_LONGUEUR] = {"apple", "banana", "cherry", "mango", "zebra"};
    char attendu[5][MAX_LONGUEUR] = {"zebra", "mango", "cherry", "banana", "apple"};
    StatsTri stats;
    int taille = 5;
    
    tri_bulles_chaines(tableau, taille, 0, &stats);
    
    assert(tableaux_chaines_egaux(tableau, attendu, taille));
    printf("OK (comparaisons: %d, échanges: %d)\n", stats.nb_comparaisons, stats.nb_echanges);
}

void test_deja_trie_ascendant() {
    printf("Test 3: Tableau déjà trié (ascendant)... ");
    char tableau[4][MAX_LONGUEUR] = {"apple", "banana", "cherry", "date"};
    char attendu[4][MAX_LONGUEUR] = {"apple", "banana", "cherry", "date"};
    StatsTri stats;
    int taille = 4;
    
    tri_bulles_chaines(tableau, taille, 1, &stats);
    
    assert(tableaux_chaines_egaux(tableau, attendu, taille));
    assert(stats.nb_echanges == 0);
    printf("OK (comparaisons: %d, échanges: %d)\n", stats.nb_comparaisons, stats.nb_echanges);
}

void test_doublons() {
    printf("Test 4: Tableau avec doublons... ");
    char tableau[5][MAX_LONGUEUR] = {"banana", "apple", "banana", "cherry", "apple"};
    char attendu[5][MAX_LONGUEUR] = {"apple", "apple", "banana", "banana", "cherry"};
    StatsTri stats;
    int taille = 5;
    
    tri_bulles_chaines(tableau, taille, 1, &stats);
    
    assert(tableaux_chaines_egaux(tableau, attendu, taille));
    printf("OK (comparaisons: %d, échanges: %d)\n", stats.nb_comparaisons, stats.nb_echanges);
}

void test_un_element() {
    printf("Test 5: Tableau avec un seul élément... ");
    char tableau[1][MAX_LONGUEUR] = {"seul"};
    char attendu[1][MAX_LONGUEUR] = {"seul"};
    StatsTri stats;
    int taille = 1;
    
    tri_bulles_chaines(tableau, taille, 1, &stats);
    
    assert(tableaux_chaines_egaux(tableau, attendu, taille));
    assert(stats.nb_comparaisons == 0);
    assert(stats.nb_echanges == 0);
    printf("OK (comparaisons: %d, échanges: %d)\n", stats.nb_comparaisons, stats.nb_echanges);
}

void test_exemple_prof() {
    printf("Test 6: Exemple du prof (6 mots)... ");
    char tableau[6][MAX_LONGUEUR] = {"bonjour", "hello", "world", "apple", "banana", "cherry"};
    char attendu[6][MAX_LONGUEUR] = {"apple", "banana", "bonjour", "cherry", "hello", "world"};
    StatsTri stats;
    int taille = 6;
    
    tri_bulles_chaines(tableau, taille, 1, &stats);
    
    assert(tableaux_chaines_egaux(tableau, attendu, taille));
    printf("OK (comparaisons: %d, échanges: %d)\n", stats.nb_comparaisons, stats.nb_echanges);
}

int main() {
    printf("=== Exécution des tests - Tri de chaînes ===\n\n");
    
    test_tri_ascendant_simple();
    test_tri_descendant();
    test_deja_trie_ascendant();
    test_doublons();
    test_un_element();
    test_exemple_prof();
    
    printf("\n=== Tous les tests sont passés avec succès ! ===\n");
    return 0;
}