#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordenaLinhaDecrescente(int lin[], int tam) {
    int i, j, aux;
    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1; j < tam; j++) {
            if (lin[i] < lin[j]) {
                aux = lin[i];
                lin[i] = lin[j];
                lin[j] = aux;
            }
        }
    }
}

int main() {
    int l, c, i, j;
    scanf("%d %d", &l, &c);
    int mat[l][c];
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
        ordenaLinhaDecrescente(mat[i], c);
    }
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
