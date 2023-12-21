#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float altura;
    float largura;
    float comprimento;
    float *area;
    float *volume;
    float *diagonal;
}lelepi;

void receba(lelepi le);

int main(void){
    lelepi le;
    receba(le);

    return 0;
}

void receba (lelepi le){
    float ar;
    float vol;
    float diag;

    scanf("%f", &le.altura);
     scanf("%f", &le.largura);
      scanf("%f", &le.comprimento);


    ar = (2 * le.altura * le.largura + 2 * le.altura * le.comprimento + 2 * le.largura * le.comprimento);
    vol = (le.altura * le.largura * le.comprimento);
    diag = sqrt(le.altura * le.altura + le.largura * le.largura + le.comprimento * le.comprimento);

    le.area = &ar;
    le.volume = &vol;
    le.diagonal = &diag;

    printf("area: %0.1f\n", *le.area);
    printf("volume: %0.1f\n", *le.volume);
    printf("comprimento da diagonal: %0.1f\n", *le.diagonal);
}
