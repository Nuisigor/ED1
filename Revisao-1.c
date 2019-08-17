#include <stdio.h>

unsigned long int potencia(int num,int pot);

int main(){
    int numero, n;
    scanf("%d %d",&numero , &n);
    unsigned long int res;
    res = potencia(numero,n);
    printf("%ld\n",res);
}

unsigned long int potencia(int num,int pot){
    unsigned long int resultado = 1;
    for(int i = 0; i < pot; i++){
        resultado*=num;
    }
    return resultado;
}