#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca(int item, int v[], int n, int m) {
    int esq = 0;
    int dir = n - 1;
    int meio;
    
    while (dir - esq + 1 > m) {
        meio = (esq + dir) / 2;
        if (v[meio] == item) {
            return meio;
        } else if (v[meio] > item) {
            dir = meio - 1;
        } else {
            esq = meio + 1;
        }
    }
    
    for (int i = esq; i <= dir; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    for (int i = esq; i <= dir; i++) {
        if (v[i] == item) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int item, n, m;
    scanf("%d %d", &item, &n);
    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    scanf("%d", &m);
    
    int pos = busca(item, v, n, m);
    printf("%d\n", pos);
    
    return 0;
}
