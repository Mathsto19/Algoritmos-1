#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;

void Paparazzo_CRF(Aluno *vetor, int esquerda, int meio, int direita){
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    Aluno *E = (Aluno*)malloc(n1 * sizeof(Aluno));
    Aluno *D = (Aluno*)malloc(n2 * sizeof(Aluno));

    for(int i = 0; i < n1; i++){
        E[i] = vetor[esquerda + i];
    }
    for(int j = 0; j < n2; j++){
        D[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;

    while(i < n1 && j < n2){
        int cmp = strcmp(E[i].nome, D[j].nome);
        if(cmp < 0 || (cmp == 0 && E[i].matricula <= D[j].matricula)){
            vetor[k] = E[i];
            i++;
        }else{
            vetor[k] = D[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        vetor[k] = E[i];
        i++;
        k++;
    }
    while(j < n2){
        vetor[k] = D[j];
        j++;
        k++;
    }

    free(E);
    free(D);
}

void mergeSort(Aluno *vetor, int esquerda, int direita){
    if(esquerda < direita){
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);

        Paparazzo_CRF(vetor, esquerda, meio, direita);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Aluno *alunos = (Aluno*)malloc(n * sizeof(Aluno));
    for(int i = 0; i < n; i++){
        alunos[i].nome = (char*)malloc(50 * sizeof(char));
        alunos[i].curso = (char*)malloc(50 * sizeof(char));
        scanf("%d %s %s %f", &alunos[i].matricula, alunos[i].nome, alunos[i].curso, &alunos[i].coef);
    }

    mergeSort(alunos, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%s %d %s %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].curso, alunos[i].coef);
    }

    for(int i = 0; i < n; i++){
        free(alunos[i].nome);
        free(alunos[i].curso);
    }
    free(alunos);

    return 0;
}
