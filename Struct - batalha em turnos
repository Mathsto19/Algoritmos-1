#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    int energia;
    int defesa;
    int forca;
    int energia_final;
}lutador;

void cadastro (lutador p1, lutador p2)
{
    int i, n;
    scanf("%s %d %d %d", &p1.nome, &p1.energia, &p1.defesa, &p1.forca);
    scanf("%s %d %d %d", &p2.nome, &p2.energia, &p2.defesa, &p2.forca);
    scanf("%d", &i);

        for(n=1; n<=i; n++)
        {
            p2.energia_final = p2.energia - ((p1.forca*n) - (p2.defesa*n));

            if(p2.energia_final <=0)
            {
                p1.energia_final = p1.energia;
                break;
            }

           p1.energia_final = p1.energia - ((p2.forca*n) - (p1.defesa*n));

            if(p1.energia_final <=0)
            {
                break;
            }

            if((p2.defesa - p1.forca) >= 0)
            {
                p2.energia_final = p2.energia - i;
            }

            if((p1.defesa - p2.forca) >= 0)
            {
                p1.energia_final = p1.energia - i;
            }
        }

        if(p1.energia_final < 0)
        {
            p1.energia_final = 0;
        }

        if(p2.energia_final < 0)
        {
            p2.energia_final = 0;
        }

        printf("%s %d\n", p1.nome, p1.energia_final);
        printf("%s %d\n", p2.nome, p2.energia_final);

    if(p1.energia_final > p2.energia_final)
    {
        printf("%s", p1.nome);
    }

    if(p1.energia_final < p2.energia_final)
    {
        printf("%s", p2.nome);
    }

    if(p1.energia_final == p2.energia_final)
    {
        printf("empate");
    }
}
int main(void){

    lutador p1;
    lutador p2;
    cadastro(p1, p2);

return 0;
}
