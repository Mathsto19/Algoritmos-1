#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct lista {
    float dado;
    struct lista* prox;
};

typedef struct lista Lista;

void inserir(Lista** p, float dado) {
    if (*p == NULL) {
        *p = (Lista*)malloc(sizeof(Lista));
        (*p)->dado = dado;
        (*p)->prox = NULL;
    } else {
        inserir(&((*p)->prox), dado);
    }
}

void imprimir(Lista* p) {
    if (p != NULL) {
        printf("%.1f ", p->dado);
        imprimir(p->prox);
    }
}

void insertionSort(Lista** p) {
    if (*p == NULL || (*p)->prox == NULL) {
        return;
    }
    insertionSort(&((*p)->prox));
    Lista* atual = *p;
    while (atual->prox != NULL && atual->dado > atual->prox->dado) {
        float temp = atual->dado;
        atual->dado = atual->prox->dado;
        atual->prox->dado = temp;
        atual = atual->prox;
    }
}

int main() {
    float dado;
    Lista* lista = NULL;
    do {
        scanf("%f", &dado);
        if (dado != -1) {
            inserir(&lista, dado);
        }
    } while (dado != -1);
    insertionSort(&lista);
    imprimir(lista);
    return 0;
}
