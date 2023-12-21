#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista Lista;

Lista* criar_lista();

int lista_vazia(Lista *l);

int lista_cheia(Lista *l);

int buscar(Lista *l, int chave1, int chave2);

int inserir(Lista *l, int chave);

struct Lista{
    int item[MAX_SIZE];
    int tam;
};


Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}

int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}

int buscar(Lista *l, int chave1 , int chave2){
    int i;

    if (!lista_vazia(l)){

        for (i = 0; i < l->tam; i++){

            if(chave1 == -1){
                break;
            }
            if (l->item[i] == chave1 && l->item[i+1] == chave2){
                return i;
                break;
            }
        }
    }
    return -1;
}

int buscar2(Lista *l, int i, Lista *l2){
  
   if (!lista_vazia(l) && !lista_vazia(l2)){
        for (int j = 0;  i< l->tam ; j++, i++){
        
            if(l2->item[j] != -1 && l2->item[j] != l->item[i])
                return -1;
            
            if(l2->item[j] == -1){
                 return 0;
            }
        }

    return 0;
    }
    return -1;
}

int inserir(Lista *l, int chave){
    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++;
        return 1;
    }

    return 0;
}

int main(void){

    int i, j=0, t, x;
    Lista *l1 = criar_lista();
    Lista *l2 = criar_lista();

    for(i=0; j!=-1; i++){
        scanf("%d", &j);
    inserir(l1, j);
    }

    for(x=0; t!=-1; x++){
        scanf("%d", &t);
    inserir(l2, t);
    }

    x = buscar(l1, l2->item[0], l2->item[1]);
    if(buscar2(l1,x,l2) == 0)
            printf("%d\n", x);

    else
        printf("-1");

    return 0;
}
