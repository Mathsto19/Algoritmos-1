#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    int pot;
    float temp;

}eletro;

int main() {

    eletro e[20];

    int i, n, d;
    int consumo_total = 0;
    float consumo_relativo[20];
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%s %d %f", &e[i].nome, &e[i].pot, &e[i].temp);
    }

    scanf("%d", &d);

    for(i=1; i<=n; i++){
        consumo_total = (e[i].pot * e[i].temp * d) + consumo_total;
    }

    printf("%d\n", consumo_total);

     for(i=1; i<=n; i++){
        consumo_relativo[i] = ((e[i].pot * e[i].temp * d) / consumo_total) * 100;
        printf("%s %0.1f\n",e[i].nome, consumo_relativo[i]);
    }

    return 0;
}
