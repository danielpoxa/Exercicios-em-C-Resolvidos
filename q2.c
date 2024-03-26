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

// Função para fazer uma cópia da lista dada
Node* copyList(Node *head) {
    if (head == NULL)
        return NULL;

    Node *newHead = createNode(head->data);
    Node *current = head->next;
    Node *newCurrent = newHead;

    while (current != NULL) {
        newCurrent->next = createNode(current->data);
        newCurrent = newCurrent->next;
        current = current->next;
    }

    return newHead;
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

    printf("Lista Original: ");
    printList(head);

    // Fazendo uma cópia da lista
    Node *copiedList = copyList(head);

    printf("Cópia da Lista: ");
    printList(copiedList);

    return 0;
}
