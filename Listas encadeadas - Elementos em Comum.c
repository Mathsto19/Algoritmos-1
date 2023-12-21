#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
    
typedef struct encad{
    int valor;
    struct encad *prox;
} Encadeada;

typedef Encadeada *Lista;

void insereOrdenado(Lista *l, int valor) {
    Encadeada *novo = (Encadeada*) malloc(sizeof(Encadeada));
    novo->valor = valor;
    novo->prox = NULL;

    if (*l == NULL || valor < (*l)->valor) {
        novo->prox = *l;
        *l = novo;
    } else {
        Encadeada *atual = *l;
        while (atual->prox != NULL && atual->prox->valor <= valor) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

Lista intercala(Lista l1, Lista l2){
    Lista l3 = NULL;

    Encadeada *p1 = l1, *p2 = l2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->valor == p2->valor) {
            insereOrdenado(&l3, p1->valor);
            p1 = p1->prox;
            p2 = p2->prox;
        } else if (p1->valor < p2->valor) {
            p1 = p1->prox;
        } else {
            p2 = p2->prox;
        }
    }

    return l3;
}

int main() {
    Lista l1 = NULL, l2 = NULL;
    int valor;

    scanf("%d", &valor);
    while (valor != -1) {
        insereOrdenado(&l1, valor);
        scanf("%d", &valor);
    }

    scanf("%d", &valor);
    while (valor != -1) {
        insereOrdenado(&l2, valor);
        scanf("%d", &valor);
    }

    Lista l3 = intercala(l1, l2);
    while (l3 != NULL) {
        printf("%d ", l3->valor);
        l3 = l3->prox;
    }
    printf("\n");

    return 0;
}
