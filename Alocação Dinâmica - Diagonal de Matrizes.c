#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int* diagonal(int **mat, int n){
    int i, *vet = malloc(sizeof(int));

    for(i = 0 ; i < n ; i++){
        vet[i] = mat[i][i];
    }

    vet[i] = INT_MAX;

    return vet;
}

int main() {
    int n;
    int i, j;
    scanf("%d", &n);

    int **mat = malloc(n * sizeof(int*));
    int *vet = malloc(n *sizeof(int));

    for(int i = 0 ; i < n ; i++)
        mat[i] = malloc(n * sizeof(int));

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%d", &mat[i][j]);
        }
}

    vet = diagonal(mat, n);

    for(i = 0 ; vet[i] != INT_MAX ; i++){
        printf("%d ", vet[i]);
    }

    free(mat);

    return 0;
}
