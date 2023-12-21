#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

typedef struct {
    int item[TAM_MAX];
    int ini;
    int fim;
} Fila;

void inicializar(Fila *fila) {
    fila->ini = -1;
    fila->fim = -1;
}

int estaCheia(Fila *fila) {
    return (fila->fim == TAM_MAX - 1);
}

int estaVazia(Fila *fila) {
    return (fila->ini == -1 || fila->ini > fila->fim);
}

void enfileirar(Fila *fila, int chave) {
    if (estaCheia(fila)) {
        return;
    }

    if (fila->ini == -1) {
        fila->ini = 0;
    }

    fila->fim++;
    fila->item[fila->fim] = chave;
}

void enfileirarOrdenado(Fila *fila, int chave) {
    if (estaCheia(fila)) {
        return;
    }

    Fila filaAuxiliar;
    inicializar(&filaAuxiliar);

    while (!estaVazia(fila) && fila->item[fila->fim] < chave) {
        int elemento = fila->item[fila->fim];
        enfileirar(&filaAuxiliar, elemento);
        fila->fim--;
    }

    enfileirar(fila, chave);

    while (!estaVazia(&filaAuxiliar)) {
        int elemento = filaAuxiliar.item[filaAuxiliar.fim];
        enfileirar(fila, elemento);
        filaAuxiliar.fim--;
    }
}

void imprimirFila(Fila *fila) {
    int i;
    for (i = fila->ini; i <= fila->fim; i++) {
        printf("%d ", fila->item[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializar(&fila);

    int chave;
    while (1) {
        scanf("%d", &chave);
        if (chave == -1) {
            break;
        }
        enfileirarOrdenado(&fila, chave);
    }

    imprimirFila(&fila);

    return 0;
}
