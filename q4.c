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

// Função para construir uma lista encadeada a partir de um vetor
Node* buildListFromArray(int arr[], int n) {
    if (n == 0)
        return NULL;

    Node *head = createNode(arr[0]);
    Node *current = head;

    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
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
    int arr[] = {4, 1, 5, 9, 13, 26};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = buildListFromArray(arr, n);

    printf("Lista Encadeada construída a partir do vetor: ");
    printList(head);

    return 0;
}
