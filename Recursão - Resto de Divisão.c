#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int resto_divisao(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return resto_divisao(a-b, b);
    }
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", resto_divisao(a, b));
    }
    return 0;
}
