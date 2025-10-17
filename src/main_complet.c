#include <stdio.h>
#include "tri_bulles.h"
#include "tri_chaines.h"

int main() {
    // ===== TRI D'ENTIERS =====
    printf("========================================\n");
    printf("       TEST TRI D'ENTIERs\n");
    printf("========================================\n");
    
    int tableau[] = {64, 34, 25, 12, 22, 11, 90};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    
    printf("Tableau avant tri : ");
    afficher_tableau(tableau, taille);
    
    tri_bulles(tableau, taille);
    
    printf("Tableau après tri : ");
    afficher_tableau(tableau, taille);
    
    // ===== TRI DE CHAINES =====
    printf("\n========================================\n");
    printf("       TEST TRI DE CHAINES\n");
    printf("========================================\n");
    
    char mots[6][MAX_LONGUEUR] = {
        "bonjour", "hello", "world", 
        "apple", "banana", "cherry"
    };
    StatsTri stats = {0, 0};
    
    printf("\nMots avant tri :\n");
    afficher_tableau_chaines(mots, 6);
    
    printf("\n--- Tri en ordre ASCENDANT ---\n");
    tri_bulles_chaines(mots, 6, 1, &stats);
    
    printf("Mots après tri :\n");
    afficher_tableau_chaines(mots, 6);
    afficher_statistiques(stats);
    
    // Reset et tri descendant
    char mots2[6][MAX_LONGUEUR] = {
        "bonjour", "hello", "world", 
        "apple", "banana", "cherry"
    };
    StatsTri stats2 = {0, 0};
    
    printf("\n--- Tri en ordre DESCENDANT ---\n");
    tri_bulles_chaines(mots2, 6, 0, &stats2);
    
    printf("Mots après tri :\n");
    afficher_tableau_chaines(mots2, 6);
    afficher_statistiques(stats2);
    
    printf("\n========================================\n");
    printf("       TOUS LES TESTS REUSSIS !\n");
    printf("========================================\n");
    
    return 0;
}