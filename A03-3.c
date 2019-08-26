#include <stdio.h>

char conversor(float nota){
    if(nota <=10 && nota >=0){
        if(nota >= 9){return 'A';}
        else if(nota >=7){return 'B';}
        else if(nota >=6){return 'C';}
        else{return 'I';}
    }
    else 
        return 'X';
}

void conversor1(float nota, char *conceito){
    if(nota <=10 && nota >=0){
        if(nota >= 9){*conceito = 'A';}
        else if(nota >=7){*conceito = 'B';}
        else if(nota >=6){*conceito = 'C';}
        else{*conceito = 'I';}
    }
    else 
        *conceito = 'X';
}


int main(){
    //Teste 1
    printf("9.8: %c \n", conversor(9.8));
    printf("7.9: %c \n", conversor(7.9));
    printf("6.7: %c \n", conversor(6.7));
    printf("5.9: %c \n", conversor(5.9));
    printf("-1: %c \n", conversor(-1));
    printf("14: %c \n", conversor(14));

    printf("\n\n\n\n");

    //Teste 2

    char conceito;
    conversor1(9.8, &conceito);
    printf("9.8: %c \n", conceito);
    conversor1(7.9, &conceito);
    printf("7.9: %c \n", conceito);
    conversor1(6.7, &conceito);
    printf("6.7: %c \n", conceito);
    conversor1(5.9, &conceito);
    printf("5.9: %c \n", conceito);
    conversor1(-1, &conceito);
    printf("-1: %c \n", conceito);
    conversor1(14, &conceito);
    printf("14: %c \n", conceito);
}

