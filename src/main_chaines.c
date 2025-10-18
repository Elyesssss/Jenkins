#include <stdio.h>
#include <string.h>
#include "tri_chaines.h"

int main() {
    printf("========================================\n");
    printf("       PROGRAMME TRI DE CHAÎNES\n");
    printf("========================================\n");
    
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
    
    printf("\n========================================\n");
    printf("       TRI DE CHAÎNES TERMINÉ !\n");
    printf("========================================\n");
    
    return 0;
}