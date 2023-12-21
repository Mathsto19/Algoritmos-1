#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Elemento {
    int valor;
    int coluna;
    struct Elemento* prox;
};

void adicionar_elem(struct Elemento** topo, int valor, int coluna) {
    struct Elemento* novo_elem = (struct Elemento*) malloc(sizeof(struct Elemento));
    novo_elem->valor = valor;
    novo_elem->coluna = coluna;
    novo_elem->prox = NULL;

    if (*topo == NULL) {
        *topo = novo_elem;
    } else {
        struct Elemento* atual = *topo;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_elem;
    }
}

void imprimir_vetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void matriz_para_vetor(int** matriz, int linhas, int colunas) {
    int* vetor = (int*) calloc(colunas, sizeof(int));

    for (int j = 0; j < colunas; j++) {
        struct Elemento* topo = NULL;
        for (int i = 0; i < linhas; i++) {
            if (matriz[i][j] != 0) {
                adicionar_elem(&topo, matriz[i][j], j);
            }
        }
        struct Elemento* atual = topo;
        while (atual != NULL) {
            vetor[j] += atual->valor;
            atual = atual->prox;
        }
        free(topo);
    }

    imprimir_vetor(vetor, colunas);
    free(vetor);
}

int main() {
    int i, j;
    int l, c;
    scanf("%d %d", &l, &c);

    int** mat = (int**) malloc(l * sizeof(int*));
    for (i = 0; i < l; i++) {
        mat[i] = (int*) malloc(c * sizeof(int));
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    matriz_para_vetor(mat, l, c);

    for (int i = 0; i < l; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
