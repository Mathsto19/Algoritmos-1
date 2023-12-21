#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct pilha1 pilha1;
typedef struct pilha pilha;

void criar_pilha(struct pilha* p);
void empilhar(struct pilha* p, char valor);
void desempilhar(struct pilha* p);
int pilha_vazia(struct pilha* p);
void pilha_cheia(struct pilha* p);
int tamanho(struct pilha* p);

struct pilha1{
    char valor;
    struct pilha1* abaixo;
};

struct pilha{
    int tamanho;
    struct pilha1* topo;
};

void criar_pilha(struct pilha* p){
    p->tamanho = 0;
    p->topo = NULL;
}

void empilhar(struct pilha* p, char valor){
    p->tamanho += 1;
    struct pilha1* novoTopo = (struct pilha1*) malloc(sizeof(struct pilha1));

    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void desempilhar(struct pilha* p){
    while(!pilha_vazia(p)){
        pilha_cheia(p);
    }
}

int pilha_vazia(struct pilha* p){
    return p->tamanho == 0;
}

void pilha_cheia(struct pilha* p){
    if(p->tamanho > 0){
        p->tamanho -= 1;
        struct pilha1* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    }
}

char obter_posicao_topo(struct pilha* p){
    return p->topo->valor;
}

int tamanho(struct pilha* p){
    return p->tamanho;
}

int main(){
    struct pilha p;
    int i, y, m;
    int siz = 0;
    int cont;
    char campo [MAX_SIZE];

    scanf("%d\n", &m);

    for(i = 0; i < m; i++){
            scanf("%s", campo);
            cont = 0;
            criar_pilha(&p);

            siz = strlen(campo);

        for(y = 0; y < siz; y++){

                if(campo[y] == '<'){
                    empilhar(&p, '<');
            }

            else if(campo[y] == '>'){

                    if(!pilha_vazia(&p)){
                    cont++;
                    pilha_cheia(&p);
                }
            }
        }

        printf("%d\n", cont);
        desempilhar(&p);
    }

    return 0;
}
