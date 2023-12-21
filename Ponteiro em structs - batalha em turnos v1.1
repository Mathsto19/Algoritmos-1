#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Jogador Jogador;

struct Jogador{
    char *nome;
    int energia;
    int defesa;
    int forca;
    int *As;
};

Jogador* carregar_struct(){
    Jogador *jogador = malloc(2* sizeof(Jogador));

    for(int i = 0 ; i <= 1 ; i++){
        jogador[i].nome = malloc(sizeof(char));
        jogador[i].As = malloc(3* sizeof(int));
        jogador[i].energia = INT_MIN;
        jogador[i].defesa = INT_MIN;
        jogador[i].forca = INT_MIN;
        jogador[i].As[0] = INT_MIN;
        jogador[i].As[1] = INT_MIN;
        jogador[i].As[2] = INT_MIN;
    }

    return jogador;
}

int montar_ficha(Jogador *jogador, int i){
    int j = 0;

    scanf("%s", jogador[i].nome);
    if(jogador[i].nome == NULL){
        j++;
    }

    scanf("%d", &jogador[i].energia);
    if(jogador[i].energia == INT_MIN){
        j++;
    }

    scanf("%d", &jogador[i].defesa);
    if(jogador[i].defesa == INT_MIN){
        j++;
    }
    scanf("%d", &jogador[i].forca);
    if(jogador[i].forca == INT_MIN){
        j++;
    }

    scanf("%d", &jogador[i].As[0]);
    if(jogador[i].As[0] == INT_MIN){
        j++;
    }

    scanf("%d", &jogador[i].As[1]);
    if(jogador[i].As[1] == INT_MIN){
        j++;
    }

    scanf("%d", &jogador[i].As[2]);
    if(jogador[i].As[2] == INT_MIN){
        j++;
    }
    return j;
}

void reduz_dano(Jogador *jogador, int aux, int aux2){
    int dano;

    dano = jogador[aux].forca + jogador[aux].As[aux2];
    aux++;

    if(aux == 2){
        aux -= 2;
    }

    dano -= jogador[aux].defesa;

    if(dano < 0){
        jogador[aux].energia -= 1;
    }

    else{
        jogador[aux].energia -= dano;
    }
}

int turnos(Jogador *jogador, int n){
    int aux, aux2, i;
    char acao;

    for(i = 0 ; i < n ; i++){
        fflush(stdin);
        scanf("%d %c", &aux, &acao);

        if(aux == 1 || aux == 2){
            aux--;

            if(jogador[aux].energia > 0){

                if(acao == 'A' || acao == 'a'){
                    scanf("%d", &aux2);

                    if(aux2 >= 1 && aux2 <= 3){
                        reduz_dano(jogador, aux, aux2 -=1);
                    }
                }
                  else if(acao == 'C' || acao == 'c'){
                      if(jogador[aux].energia <= 800){
                        jogador[aux].energia += 200;
                      }
                }
            }

            else{
                return 0;
            }
        }
    }

    return -1;
}

void resultado(Jogador *jogador){
    printf("%s ", jogador[0].nome);
    printf("%d\n", jogador[0].energia);
    printf("%s ", jogador[1].nome);
    printf("%d\n", jogador[1].energia);

    if(jogador[0].energia > jogador[1].energia){
        printf("%s\n", jogador[0].nome);
    }

    else if(jogador[0].energia < jogador[1].energia){
        printf("%s\n", jogador[1].nome);
    }

    else{
        printf("empate\n");
    }
}

int main() {
    Jogador *jogador = carregar_struct();
    int n = 0;

    n += montar_ficha(jogador, 0);
    n += montar_ficha(jogador, 1);

    if(n == 0){
        scanf("%d", &n);
        turnos(jogador, n);
        resultado(jogador);
    }

    free(jogador);

    return 0;
}
