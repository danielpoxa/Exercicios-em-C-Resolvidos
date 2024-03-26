#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node *next;
} Node;

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
void insert(Node **head, int data) {
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

// Função para remover os n primeiros nós da lista
Node* removeFirstN(Node *head, int n) {
    Node *temp = head;
    Node *nextNode;

    // Remove os n primeiros nós
    for (int i = 0; i < n && temp != NULL; i++) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return temp; // Retorna o novo início da lista
}

// Função para imprimir os elementos da lista
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    // Inserindo elementos na lista original
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    printf("Lista Original: ");
    printList(head);

    // Removendo os 3 primeiros nós da lista
    int n = 3;
    head = removeFirstN(head, n);

    printf("Lista após remover os %d primeiros nós: ", n);
    printList(head);

    return 0;
}
