#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int** somam(int **mat1, int **mat2, int l, int c){
    int i, j;
    int **vet = malloc(l * sizeof(int*));

    for(i = 0 ; i < c ; i++){
        vet[i] = malloc(c * sizeof(int));
    }

    for(i = 0 ; i < l ; i++){
        for(j = 0 ; j < c ; j++){
        vet[i][j] = (mat1[i][j] + mat2[i][j]);
    }
}

    return vet;
}

int main() {
    int l, c;
    int i, j;
    scanf("%d %d", &l, & c);

    int **mat1 = malloc(l * sizeof(int*));
    int **mat2 = malloc(l * sizeof(int*));
    int **vet;

    for(int i = 0 ; i < c ; i++){
        mat1[i] = malloc(c * sizeof(int));
        mat2[i] = malloc(c * sizeof(int));
    }

    for(i = 0 ; i < l ; i++){
        for(j = 0 ; j < c ; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    for(i = 0 ; i < l ; i++){
        for(j = 0 ; j < c ; j++){
            scanf("%d", &mat2[i][j]);
        }
}

vet = somam(mat1, mat2, l, c);

    for(i = 0 ; i < l ; i++){
        for(j = 0 ; j < c ; j++){
        printf("%d ", vet[i][j]);
    }
    printf("\n");
}

    free(mat1);
    free(mat2);

    return 0;
}
