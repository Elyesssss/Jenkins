#include <stdio.h>
#include <string.h>
#include "tri_chaines.h"

// Fonction pour échanger deux chaînes
void swap_chaines(char *str1, char *str2) {
    char temp[MAX_LONGUEUR];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Fonction de tri à bulles pour chaînes avec statistiques
void tri_bulles_chaines(char tableau[][MAX_LONGUEUR], int taille, int ordre_ascendant, StatsTri *stats) {
    int i, j;
    int echange;
    
    // Initialiser les statistiques
    stats->nb_comparaisons = 0;
    stats->nb_echanges = 0;
    
    for (i = 0; i < taille - 1; i++) {
        echange = 0;
        
        for (j = 0; j < taille - i - 1; j++) {
            int comparaison = strcmp(tableau[j], tableau[j + 1]);
            stats->nb_comparaisons++;
            
            // Si ordre ascendant : échanger si tableau[j] > tableau[j+1]
            // Si ordre descendant : échanger si tableau[j] < tableau[j+1]
            int doit_echanger = (ordre_ascendant && comparaison > 0) || 
                               (!ordre_ascendant && comparaison < 0);
            
            if (doit_echanger) {
                swap_chaines(tableau[j], tableau[j + 1]);
                stats->nb_echanges++;
                echange = 1;
            }
        }
        
        // Si aucun échange n'a été fait, le tableau est déjà trié
        if (echange == 0) {
            break;
        }
    }
}

// Fonction pour afficher un tableau de chaînes
void afficher_tableau_chaines(char tableau[][MAX_LONGUEUR], int taille) {
    int i;
    printf("[ ");
    for (i = 0; i < taille; i++) {
        printf("\"%s\"", tableau[i]);
        if (i < taille - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

// Fonction pour afficher les statistiques
void afficher_statistiques(StatsTri stats) {
    printf("\n=== Statistiques du tri ===\n");
    printf("Nombre de comparaisons : %d\n", stats.nb_comparaisons);
    printf("Nombre d'échanges      : %d\n", stats.nb_echanges);
    printf("===========================\n");
}