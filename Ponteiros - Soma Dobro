#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float dobro(float *x, float *y, float *z){

    *x = (*x) * 2;
    *y = (*y) * 2;
    *z = (*z) * 2;
    return ((*x) + (*y) + (*z));
}

int main() {
    float a, b, c, soma;
    int n, i;
    scanf("%d", &i);

    for(n=0; n<i; n++){
    scanf("%f %f %f", &a, &b, &c);
    soma = dobro(&a, &b, &c);
    printf("A=%0.1f B=%0.1f C=%0.1f SOMA=%0.1f\n", a, b, c, soma);
    }

    return 0;
}
