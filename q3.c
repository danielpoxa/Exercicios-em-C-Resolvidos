#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Definição do tipo Lista como um ponteiro para Node
typedef Node* Lista;

// Função para criar um novo nó
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no final da lista
void insert(Lista *head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Função para concatenar L1 no final de L2 e retornar a lista resultante
Lista concatena(Lista L1, Lista L2) {
    if (L1 == NULL) {
        return L2;
    }
    if (L2 == NULL) {
        return L1;
    }
    Node *temp = L2;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = L1;
    return L2;
}

// Função para imprimir os elementos da lista
void printList(Lista head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Lista L1 = NULL;
    Lista L2 = NULL;

    // Inserindo elementos na lista L1
    insert(&L1, 10);
    insert(&L1, 20);
    insert(&L1, 30);

    // Inserindo elementos na lista L2
    insert(&L2, 40);
    insert(&L2, 50);
    insert(&L2, 60);

    printf("Lista L1: ");
    printList(L1);

    printf("Lista L2: ");
    printList(L2);

    // Concatenando L1 no final de L2
    Lista concatenada = concatena(L1, L2);

    printf("Lista concatenada: ");
    printList(concatenada);

    return 0;
}
