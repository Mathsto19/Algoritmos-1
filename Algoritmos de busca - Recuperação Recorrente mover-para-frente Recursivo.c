#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void moverParaFrente(int vet[], int n, int chave) {
    if (n == 0) {
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        if (vet[i] == chave) {
            break;
        }
    }

    if (i == n) {
        return;
    }
    
    int temp = vet[i];
    for (int j = i; j > 0; j--) {
        vet[j] = vet[j-1];
    }
    vet[0] = temp;
    
    moverParaFrente(vet+1, n-1, chave);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int vet[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
    
    int cont;
    scanf("%d", &cont);
    
    for (int i = 0; i < cont; i++) {
        int chave;
        scanf("%d", &chave);
        
        moverParaFrente(vet, n, chave);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    
    return 0;
}
