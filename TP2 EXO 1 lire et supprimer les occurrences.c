#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour afficher la liste
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Supprime toutes les occurrences d'une valeur donnée
void removeAllOccurrences(Node** head, int value) {
    // Suppression en tête
    while (*head && (*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node* current = *head;
    while (current && current->next) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Fonction pour lire une valeur et supprimer toutes ses occurrences
void readAndRemoveAllOccurrences(Node** head) {
    int value;
    printf("Entrez la valeur à supprimer : ");
    scanf("%d", &value);
    removeAllOccurrences(head, value);
    printf("Toutes les occurrences de %d ont été supprimées.\n", value);
}
