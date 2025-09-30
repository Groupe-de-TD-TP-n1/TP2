#include <stdio.h>
#include <stdlib.h>

// Définition d'une cellule de la liste
typedef struct Cellule {
    int valeur;
    struct Cellule* suivant;
} Cellule;

// Fonction pour créer une nouvelle cellule
Cellule* creerCellule(int val) {
    Cellule* nouveau = (Cellule*)malloc(sizeof(Cellule));
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    return nouveau;
}

// Fonction pour insérer un élément à la fin
Cellule* insererFin(Cellule* tete, int val) {
    Cellule* nouveau = creerCellule(val);

    if (tete == NULL) {
        return nouveau; 
    }

    Cellule* courant = tete;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    courant->suivant = nouveau;
    return tete;
}

// Fonction pour afficher la liste
void afficherListe(Cellule* tete) {
    Cellule* courant = tete;
    printf("\nLISTE : ");
    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

// Fonction pour supprimer toutes les occurrences d'une valeur
Cellule* supprimerValeur(Cellule* tete, int val, int* compteur) {
    Cellule* courant;

    // Cas particulier : la tête contient la valeur
    while (tete != NULL && tete->valeur == val) {
        courant = tete;
        tete = tete->suivant;
        free(courant);
        (*compteur)++; 
    }

    // Maintenant, on traite le reste de la liste
    Cellule* precedent = tete;
    if (tete != NULL) {
        courant = tete->suivant;
    } else {
        courant = NULL;
    }

    while (courant != NULL) {
        if (courant->valeur == val) {
            precedent->suivant = courant->suivant;
            free(courant);
            courant = precedent->suivant;
            (*compteur)++; 
        } else {
            precedent = courant;
            courant = courant->suivant;
        }
    }

    return tete;
}

int main() {
    Cellule* tete = NULL;
    int n;
    int val;
    int nbr;
    int compteur = 0;

    printf("COMBIEN D'ELEMENTS VOULEZ-VOUS INSERER ? : \t");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("ENTRER LA VALEUR %d : ", i + 1);
        scanf("%d", &val);
        tete = insererFin(tete, val);
    }

    printf("\n LISTE INITIALE :\n");
    afficherListe(tete);

    printf("\n ENTRER LA VALEUR A SUPPRIMER : ");
    scanf("%d", &nbr);

    tete = supprimerValeur(tete, nbr, &compteur);

    if (compteur > 0) {
        printf("\n LA VALEUR %d APPARAISSAIT %d FOIS DANS LA LISTE.\n", nbr, compteur);
    } else {
        printf("\nLA VALEUR %d N'APPARAIT PAS DANS LA LISTE.\n", nbr);
    }

    printf("LA NOUVELLE LISTE EST :\n");
    afficherListe(tete);

    return 0;
}
