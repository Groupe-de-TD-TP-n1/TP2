typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

CNode* createCNode(int data) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion en tête
void insertHeadCircular(CNode** head, int value) {
    CNode* newNode = createCNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        CNode* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        newNode->next = *head;
        tail->next = newNode;
        *head = newNode;
    }
}

// Insertion en queue
void insertTailCircular(CNode** head, int value) {
    CNode* newNode = createCNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        CNode* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = *head;
    }
}
