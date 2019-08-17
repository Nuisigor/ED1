#include <stdio.h>

char conversor(float nota);

int main(){
    float nota1;
    scanf("%f",&nota1);
    char conceito;
    conceito = conversor(nota1);
    printf("Conceito : %c\n",conceito);
}

char conversor(float nota){
    if(nota <=10 && nota >=0){
        if(nota >= 9){return 'A';}
        else if(nota >=7){return 'B';}
        else if(nota >=6){return 'C';}
        else{return 'I';}
    }
    else{return -1;}
}