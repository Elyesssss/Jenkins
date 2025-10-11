#include <stdio.h>
#include <string.h>
#include "tri_chaines.h"

int main() {
    char mots[6][MAX_LONGUEUR] = {
        "bonjour",
        "hello",
        "world",
        "apple",
        "banana",
        "cherry"
    };
    int taille = 6;
    StatsTri stats;
    
    printf("=== Programme de tri de chaînes ===\n\n");
    
    // Afficher le tableau original
    printf("Tableau original : ");
    afficher_tableau_chaines(mots, taille);
    
    // TRI ASCENDANT
    printf("\n--- Tri par ordre alphabétique ASCENDANT ---\n");
    char mots_asc[6][MAX_LONGUEUR];
    memcpy(mots_asc, mots, sizeof(mots));
    
    tri_bulles_chaines(mots_asc, taille, 1, &stats);
    
    printf("Tableau trié (ascendant) : ");
    afficher_tableau_chaines(mots_asc, taille);
    afficher_statistiques(stats);
    
    // TRI DESCENDANT
    printf("\n--- Tri par ordre alphabétique DESCENDANT ---\n");
    char mots_desc[6][MAX_LONGUEUR];
    memcpy(mots_desc, mots, sizeof(mots));
    
    tri_bulles_chaines(mots_desc, taille, 0, &stats);
    
    printf("Tableau trié (descendant) : ");
    afficher_tableau_chaines(mots_desc, taille);
    afficher_statistiques(stats);
    
    return 0;
}