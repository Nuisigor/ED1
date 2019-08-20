#include <stdio.h>

int conversao(int valor, int *notas){
    if(valor%10 == 3 || valor%10 == 1) return 0;
    notas[0] = valor/100;
    valor = valor%100;
    notas[1] = valor/50;
    valor = valor%50;
    notas[2] = valor/20;
    valor = valor%20;
    notas[3] = valor/10;
    valor = valor%10;
    notas[4] = valor/5;
    valor= valor%5;
    notas[5] = valor/2;
    return 1;
}

int main(){
    int valor = 587, notas1[6];
    if(valor >= 0){
        if(!conversao(valor,notas1))
            printf("Impossível retirar esse valor\n");
        else{
        conversao(valor,notas1);
        printf("Notas de 100 : %d\n",notas1[0]);
        printf("Notas de 50 : %d\n",notas1[1]);
        printf("Notas de 20 : %d\n",notas1[2]);
        printf("Notas de 10 : %d\n",notas1[3]);
        printf("Notas de 5 : %d\n",notas1[4]);
        printf("Notas de 2 : %d\n",notas1[5]);
        }
    }
    else
        printf("Impossível retirar esse valor\n");
}