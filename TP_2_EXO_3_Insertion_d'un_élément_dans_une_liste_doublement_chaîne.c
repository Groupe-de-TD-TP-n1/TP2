typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertSortedDoubly(DNode** head, int value) {
    DNode* newNode = createDNode(value);

    if (*head == NULL || (*head)->data > value) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    DNode* current = *head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next) current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
}
