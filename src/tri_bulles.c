#include <stdio.h>
#include "tri_bulles.h"

void tri_bulles(int tableau[], int taille) {
    int i, j, temp;
    int echange;
    
    for (i = 0; i < taille - 1; i++) {
        echange = 0;
        
        for (j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                // Échange des éléments
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
                echange = 1;
            }
        }
        
        // Si aucun échange, le tableau est déjà trié
        if (echange == 0) {
            break;
        }
    }
}

void afficher_tableau(int tableau[], int taille) {
    int i;
    printf("[ ");
    for (i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("]\n");
}

int main() {
    int tableau[] = {64, 34, 25, 12, 22, 11, 90};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    
    printf("Tableau avant tri : ");
    afficher_tableau(tableau, taille);
    
    tri_bulles(tableau, taille);
    
    printf("Tableau après tri : ");
    afficher_tableau(tableau, taille);
    
    return 0;
}