#include <stdio.h>
#include "tri_bulles.h"

int main() {
    printf("========================================\n");
    printf("       PROGRAMME TRI À BULLES\n");
    printf("========================================\n");
    
    int tableau[] = {64, 34, 25, 12, 22, 11, 90};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    
    printf("Tableau avant tri : ");
    afficher_tableau(tableau, taille);
    
    tri_bulles(tableau, taille);
    
    printf("Tableau après tri : ");
    afficher_tableau(tableau, taille);
    
    printf("\n========================================\n");
    printf("       TRI À BULLES TERMINÉ !\n");
    printf("========================================\n");
    
    return 0;
}
