#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int coluna;
    int valor;
    struct Element* prox;
} Elemento;

typedef struct Linha {
    Elemento* cabeca;
    struct Linha* prox;
} Linha;

void adicionarElemento(Linha* linha, int coluna, int valor) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->coluna = coluna;
    novoElemento->valor = valor;
    novoElemento->prox = NULL;

    if (linha->cabeca == NULL) {
        linha->cabeca = novoElemento;
    } else {
        Elemento* atual = linha->cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoElemento;
    }
}

Linha* criarLinha() {
    Linha* novaLinha = (Linha*)malloc(sizeof(Linha));
    novaLinha->cabeca = NULL;
    novaLinha->prox = NULL;
    return novaLinha;
}

void liberarMatrizEsparsa(Linha* matriz, int l) {
    Linha* linhaAtual = matriz;
    while (linhaAtual != NULL) {
        Elemento* elementoAtual = linhaAtual->cabeca;
        while (elementoAtual != NULL) {
            Elemento* elementoAnterior = elementoAtual;
            elementoAtual = elementoAtual->prox;
            free(elementoAnterior);
        }
        Linha* linhaAnterior = linhaAtual;
        linhaAtual = linhaAtual->prox;
        free(linhaAnterior);
    }
}

int busca_matriz_esparsa(int l, int c, Linha* matriz, int vetor[]) {
    Linha* linhaAtual = matriz;
    int posicao = 0;

    while (linhaAtual != NULL) {
        Elemento* elementoAtual = linhaAtual->cabeca;
        int i;
        for (i = 0; i < c; i++) {
            if (elementoAtual == NULL || elementoAtual->coluna > i) {
                if (vetor[i] != 0) {
                    break;
                }
            } else if (elementoAtual->coluna == i) {
                if (vetor[i] != elementoAtual->valor) {
                    break;
                }
                elementoAtual = elementoAtual->prox;
            } else {
                if (vetor[i] != 0) {
                    break;
                }
            }
        }

        if (i == c) {
            return posicao;
        }

        linhaAtual = linhaAtual->prox;
        posicao++;
    }

    return -1;
}

int main() {
    int l, c;
    scanf("%d %d", &l, &c);

    Linha* matriz = NULL;
    Linha* linhaAtual = NULL;

    for (int i = 0; i < l; i++) {
        Linha* novaLinha = criarLinha();
        linhaAtual = novaLinha;

        for (int j = 0; j < c; j++) {
            int valor;
            scanf("%d", &valor);

            if (valor != 0) {
                adicionarElemento(linhaAtual, j, valor);
            }
        }

        if (matriz == NULL) {
            matriz = linhaAtual;
        } else {
            linhaAtual = matriz;
            while (linhaAtual->prox != NULL) {
             linhaAtual = linhaAtual->prox;
        }
        linhaAtual->prox = novaLinha;
    }
}

int vetor[c];
for (int i = 0; i < c; i++) {
    scanf("%d", &vetor[i]);
}

int posicao = busca_matriz_esparsa(l, c, matriz, vetor);
printf("%d\n", posicao);

liberarMatrizEsparsa(matriz, l);

return 0;
}
