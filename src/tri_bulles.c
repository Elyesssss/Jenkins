#include <stdio.h>
#include "tri_bulles.h"

void tri_bulles(int tableau[], int taille) {
    int i, j, temp;
    int echange;
    
    for (i = 0; i < taille - 1; i++) {
        echange = 0;
        
        for (j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
                echange = 1;
            }
        }
        
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