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

// Função para dividir a lista em duas partes
Node* divideList(Node **head, int n) {
    Node *current = *head;
    Node *secondSublistHead = NULL;

    // Procurando o nó com o valor n
    while (current != NULL && current->data != n) {
        current = current->next;
    }

    // Se encontrou o nó com o valor n
    if (current != NULL && current->next != NULL) {
        secondSublistHead = current->next;
        current->next = NULL; // Terminando a primeira lista na posição n
    }

    return secondSublistHead; // Retorna a cabeça da segunda subdivisão
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

    int n = 30; // Valor para dividir a lista

    // Dividindo a lista a partir do valor n
    Node *secondSublistHead = divideList(&head, n);

    printf("Primeira Subdivisão (Lista Original): ");
    printList(head);
    printf("Segunda Subdivisão: ");
    printList(secondSublistHead);

    return 0;
}
