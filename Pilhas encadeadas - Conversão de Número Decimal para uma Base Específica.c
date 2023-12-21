#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct pilha{
    int dado;
    struct pilha *prox;
} pilha;

typedef struct pilha1 {
    pilha *topo;
} pilha1;

void inicializaPilha(pilha1 *p) {
    p->topo = NULL;
}

int pilhaVazia(pilha1 *p) {
    return p->topo == NULL;
}

void empilha(pilha1 *p, int dado) {
    pilha *novo = (pilha*)malloc(sizeof(pilha));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilha(pilha1 *p) {
    int dado = p->topo->dado;
    pilha *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    return dado;
}

void converteBase(int n, int b, pilha1 *p) {
    while (n > 0) {
        empilha(p, n % b);
        n /= b;
    }
}

char converteDigito(int d) {
    if (d < 10) {
        return d + '0';
    } else {
        return d - 10 + 'a';
    }
}

int main() {
    pilha1 p;
    inicializaPilha(&p);
    int n, b;
    scanf("%d %d", &n, &b);
    converteBase(n, b, &p);
    while (!pilhaVazia(&p)) {
        printf("%c", converteDigito(desempilha(&p)));
    }
    printf("\n");
    return 0;
}
