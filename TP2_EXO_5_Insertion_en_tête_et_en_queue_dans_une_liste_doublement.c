#include <stdio.h>
#include <stdlib.h>

// Définition de la structure pour un nœud de la liste doublement chaînée circulaire
typedef struct LDC {
    int val;
    struct LDC *prec;
    struct LDC *suiv;
} LDC;

// Fonction pour insérer un élément en tête de la liste
void insertion_tete(LDC **tete, int v) {
    // 1. Allouer de la mémoire pour le nouveau nœud
    LDC *new_node = (LDC*)malloc(sizeof(LDC));
    if (new_node == NULL) {
        // Gérer l'échec de l'allocation mémoire
        perror("Allocation de mémoire a échoué");
        return;
    }
    new_node->val = v;

    // 2. Gérer le cas où la liste est vide
    if (*tete == NULL) {
        *tete = new_node;
        new_node->prec = new_node; 
        new_node->suiv = new_node; 
    } else {
        // 3. Gérer le cas où la liste n'est pas vide
        LDC* queue = (*tete)->prec; 

        new_node->suiv = *tete;    
        new_node->prec = queue;     
        queue->suiv = new_node;      
        (*tete)->prec = new_node;  

        *tete = new_node;          
    }
}

// Fonction pour insérer un élément en queue de la liste
void insertion_queue(LDC **tete, int v) {
    // 1. Allouer de la mémoire pour le nouveau nœud
    LDC *new_node = (LDC*)malloc(sizeof(LDC));
    if (new_node == NULL) {
        perror("Allocation de mémoire a échoué");
        return;
    }
    new_node->val = v;

    // 2. Si la liste est vide, c'est le même cas que l'insertion en tête
    if (*tete == NULL) {
        *tete = new_node;
        new_node->prec = new_node;
        new_node->suiv = new_node;
    } else {
        // 3. Gérer le cas où la liste n'est pas vide
        LDC* queue = (*tete)->prec; 

        new_node->suiv = *tete;     
        new_node->prec = queue;       
        queue->suiv = new_node;       
        (*tete)->prec = new_node;   
     
    }
}

// Fonction pour afficher la liste
void affichage(LDC *tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    LDC *courant = tete;
    printf("Liste : ");
    do {
        printf("%d -> ", courant->val);
        courant = courant->suiv;
    } while (courant != tete);
    printf("(tête)\n");
}

int main() {
    LDC *l = NULL; // Initialiser la liste à NULL
    int n, v, choix;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                printf("Entrer la valeur à ajouter en tête : ");
                scanf("%d", &v);
                insertion_tete(&l, v); // On passe l'adresse de l
                affichage(l);
                break;
            }
            case 2: {
                printf("Entrer la valeur à ajouter en queue : ");
                scanf("%d", &v);
                insertion_queue(&l, v); // On passe l'adresse de l
                affichage(l);
                break;
            }
            case 3: {
                affichage(l);
                break;
            }
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 0);
    if (l != NULL) {
        LDC* courant = l->suiv;
        while (courant != l) {
            LDC* temp = courant;
            courant = courant->suiv;
            free(temp);
        }
        free(l);
    }

    return 0;
}