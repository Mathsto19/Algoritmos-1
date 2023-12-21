#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Lista{
    char nome[100];
    struct Lista *proximo;
};

typedef struct Lista Lista;

void inserir(Lista **topo_ref, char *novo_nome){
    Lista *novo1 = (Lista*) malloc(sizeof(Lista));
    strcpy(novo1->nome, novo_nome);
    novo1 -> proximo = NULL;
    
    Lista *ultimo = *topo_ref;
    if(*topo_ref == NULL){
        *topo_ref = novo1;
        return;
    }
    while(ultimo->proximo != NULL){
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo1;
}

void imprimir(Lista *atual){
    while(atual != NULL){
        printf("%s\n", atual->nome);
        atual = atual->proximo;
    }
}

void ordenar(Lista **topo_ref){
    Lista *i, *j;
    char temp[100];
    for(i = *topo_ref; i != NULL; i = i->proximo){
        for(j = i->proximo; j != NULL; j = j->proximo){
            if(strcmp(i->nome, j->nome) > 0){
                strcpy(temp, i->nome);
                strcpy(i->nome, j->nome);
                strcpy(j->nome, temp);
            }
        }
    }
}

int main(){
    int n, i;
    char nome[100];
    Lista *topo = NULL;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", nome);
        inserir(&topo, nome);
    }
    
    ordenar(&topo);
    imprimir(topo);
    
    return 0;
}
