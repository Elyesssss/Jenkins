#ifndef TRI_CHAINES_H
#define TRI_CHAINES_H

#define MAX_MOTS 100
#define MAX_LONGUEUR 100

// Structure pour stocker les statistiques de tri
typedef struct {
    int nb_comparaisons;
    int nb_echanges;
} StatsTri;

// Fonction pour échanger deux chaînes
void swap_chaines(char *str1, char *str2);

// Fonction de tri avec ordre et statistiques
void tri_bulles_chaines(char tableau[][MAX_LONGUEUR], int taille, int ordre_ascendant, StatsTri *stats);

// Fonction pour afficher un tableau de chaînes
void afficher_tableau_chaines(char tableau[][MAX_LONGUEUR], int taille);

// Fonction pour afficher les statistiques
void afficher_statistiques(StatsTri stats);

#endif