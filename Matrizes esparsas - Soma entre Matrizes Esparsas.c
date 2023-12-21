#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int coluna;
    int valor;
    struct Elemento* prox;
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

Linha* soma_matrizes_esparsas(int l1, int c1, Linha* matriz1, int l2, int c2, Linha* matriz2) {
    Linha* matrizResultado = NULL;
    Linha* linhaAtual1 = matriz1;
    Linha* linhaAtual2 = matriz2;
    Linha* linhaResultado = NULL;
    
    while (linhaAtual1 != NULL || linhaAtual2 != NULL) {
        Linha* novaLinha = criarLinha();
        linhaResultado = novaLinha;
        
        Elemento* elementoAtual1 = linhaAtual1 != NULL ? linhaAtual1->cabeca : NULL;
        Elemento* elementoAtual2 = linhaAtual2 != NULL ? linhaAtual2->cabeca : NULL;
        
        int coluna = 0;
        
        while (elementoAtual1 != NULL || elementoAtual2 != NULL) {
            int valor = 0;
            
            if (elementoAtual1 != NULL && elementoAtual1->coluna == coluna) {
                valor += elementoAtual1->valor;
                elementoAtual1 = elementoAtual1->prox;
            }
            
            if (elementoAtual2 != NULL && elementoAtual2->coluna == coluna) {
                valor += elementoAtual2->valor;
                elementoAtual2 = elementoAtual2->prox;
            }
            
            if (valor != 0) {
                adicionarElemento(linhaResultado, coluna, valor);
            }
            
            coluna++;
        }
        
        if (matrizResultado == NULL) {
            matrizResultado = linhaResultado;
        } else {
            linhaResultado = matrizResultado;
            while (linhaResultado->prox != NULL) {
                linhaResultado = linhaResultado->prox;
            }
            linhaResultado->prox = novaLinha;
        }
        
        if (linhaAtual1 != NULL) {
linhaAtual1 = linhaAtual1->prox;
}
    if (linhaAtual2 != NULL) {
        linhaAtual2 = linhaAtual2->prox;
    }
}

return matrizResultado;
}

void imprimirMatrizEsparsa(Linha* matriz, int l, int c) {
 Linha* linhaAtual = matriz;
     for (int i = 0; i < l; i++) {
 Elemento* elementoAtual = linhaAtual->cabeca;
    for (int j = 0; j < c; j++) {
   if (elementoAtual != NULL && elementoAtual->coluna == j) {
 printf("%d ", elementoAtual->valor);
 elementoAtual = elementoAtual->prox;
}   else {
 printf("0 ");
 }
}
 printf("\n");
 linhaAtual = linhaAtual->prox;
 }
}

int main() {
 int l1, c1;
    scanf("%d %d", &l1, &c1);
    Linha* matriz1 = NULL;
  Linha* linhaAtual1 = NULL;

    for (int i = 0; i < l1; i++) {
    Linha* novaLinha = criarLinha();
    linhaAtual1 = novaLinha;

    for (int j = 0; j < c1; j++) {
        int valor;
        scanf("%d", &valor);

        if (valor != 0) {
            adicionarElemento(linhaAtual1, j, valor);
        }
    }

    if (matriz1 == NULL) {
        matriz1 = linhaAtual1;
    } else {
        linhaAtual1 = matriz1;
        while (linhaAtual1->prox != NULL) {
            linhaAtual1 = linhaAtual1->prox;
        }
        linhaAtual1->prox = novaLinha;
    }
}

 int l2, c2;
 scanf("%d %d", &l2, &c2);

  Linha* matriz2 = NULL;
  Linha* linhaAtual2 = NULL;

for (int i = 0; i < l2; i++) {
    Linha* novaLinha = criarLinha();
    linhaAtual2 = novaLinha;

    for (int j = 0; j < c2; j++) {
        int valor;
        scanf("%d", &valor);

        if (valor != 0) {
            adicionarElemento(linhaAtual2, j, valor);
        }
    }

    if (matriz2 == NULL) {
        matriz2 = linhaAtual2;
    } else {
        linhaAtual2 = matriz2;
        while (linhaAtual2->prox != NULL) {
            linhaAtual2 = linhaAtual2->prox;
        }
        linhaAtual2->prox = novaLinha;
    }
}

    Linha* matrizResultado = soma_matrizes_esparsas(l1, c1, matriz1, l2, c2, matriz2);
  imprimirMatrizEsparsa(matrizResultado, l1, c1);

    liberarMatrizEsparsa(matriz1, l1);
    liberarMatrizEsparsa(matriz2, l2);
    liberarMatrizEsparsa(matrizResultado, l1);

return 0;
}
