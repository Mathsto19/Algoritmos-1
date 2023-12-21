#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

Fila* criarFila() {
    Fila* novaFila = (Fila*)malloc(sizeof(Fila));
    novaFila->inicio = novaFila->fim = NULL;
    return novaFila;
}

int filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila* fila, int dado) {
    No* novoNo = criarNo(dado);
    if (filaVazia(fila)) {
        fila->inicio = fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

int desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        return -1; 
    }
    No* temp = fila->inicio;
    int dado = temp->dado;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return dado;
}

void inverterFila(Fila* fila) {
    No* atual = fila->inicio;
    No* anterior = NULL;
    No* proximo = NULL;
    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    fila->fim = fila->inicio; 
    fila->inicio = anterior; 
}


void concatenarInvertido(Fila* f1, Fila* f2, Fila* f3) {
    inverterFila(f1);
    inverterFila(f2);

    while (!filaVazia(f1)) {
        enfileirar(f3, desenfileirar(f1));
    }

    while (!filaVazia(f2)) {
        enfileirar(f3, desenfileirar(f2));
    }
}

int main() {
    Fila* f1 = criarFila();
    Fila* f2 = criarFila();
    Fila* f3 = criarFila();

    int dado;
    scanf("%d", &dado);
    while (dado != -1) {
        enfileirar(f1, dado);
        scanf("%d", &dado);
    }

    scanf("%d", &dado);
    while (dado != -1) {
        enfileirar(f2, dado);
        scanf("%d", &dado);
    }

    concatenarInvertido(f1, f2, f3);

    while (!filaVazia(f3)) {
        printf("%d ", desenfileirar(f3));
    }
    printf("\n");

    return 0;
}
