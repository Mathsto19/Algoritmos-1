#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int num, den;
}RAC;

RAC* criar(int num, int den);
RAC* somar(RAC *r1, RAC *r2);
RAC* subtrair(RAC *r1, RAC *r2);
RAC* dividir(RAC *r1, RAC *r2);


RAC* criar(int num, int den){
    RAC *r1 = (RAC*) malloc(sizeof(RAC));
    RAC *r2 = (RAC*) malloc(sizeof(RAC));

    r1->num = num;
    r1->den = den;
    r2->num = num;
    r2->den = den;

    return r1;
    return r2;
}

RAC* somar(RAC *r1, RAC *r2){

    int aux, aux1;

    aux = r2->den;
    aux1 = r1->den;
    int num = ((r1->num*aux + r2->num*aux1) / aux1) ;
    int den = ((r1->den*aux + r2->den*aux1) / aux);


    printf("r1+r2=%d/%d\n", num, den);
    return 0;
}

RAC* subtrair(RAC *r1, RAC *r2){
    int aux, aux1;

    aux = r2->den;
    aux1 = r1->den;
    int num = ((r1->num*aux - r2->num*aux1) / aux1) ;
    int den = ((r1->den*aux + r2->den*aux1) / aux);


    printf("r1-r2=%d/%d\n", num, den);
    return 0;
}

RAC* multiplicar(RAC *r1, RAC *r2){

    int num = r1->num * r2->num;
    int den = r1->den * r2->den;


    printf("r1*r2=%d/%d\n", num, den);
    return 0;
}

RAC* dividir(RAC *r1, RAC *r2){

    int num = r1->num * r2->den;
    int den = r1->den * r2->num;

    printf("r1/r2=%d/%d\n", num, den);
    return 0;
}

int main() {

    int num, den;

    scanf("%d %d", &num, &den);
    RAC *r1 = criar(num,den);
    scanf("%d %d", &num, &den);
    RAC *r2 = criar(num, den);

    printf("r1: %d/%d\n", r1->num, r1->den);
    printf("r2: %d/%d\n", r2->num, r2->den);

    somar(r1, r2);
    subtrair(r1, r2);
    multiplicar(r1, r2);
    dividir(r1, r2);

    return 0;
}
