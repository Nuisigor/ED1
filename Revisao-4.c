#include <stdio.h>
#include <string.h>

struct TUDO{
    char mes[15], dia[35];
    int dia1,mes1,ano;
}data;

void conversor();

int main(){
    scanf("%d %d %d",&data.dia1,&data.mes1,&data.ano);
    conversor();
    printf("%s de %s de %d\n",data.dia,data.mes,data.ano);
}

void conversor(){
    switch (data.dia1){
        case 1 : strcpy(data.dia,"Um"); break;
        case 2 : strcpy(data.dia,"Dois"); break;
        case 3 : strcpy(data.dia,"Três"); break;
        case 4 : strcpy(data.dia,"Quatro"); break;
        case 5 : strcpy(data.dia,"Cinco"); break;
        case 6 : strcpy(data.dia,"Seis"); break;
        case 7 : strcpy(data.dia,"Sete"); break;
        case 8 : strcpy(data.dia,"Oito"); break;
        case 9 : strcpy(data.dia,"Nove"); break;
        case 10 : strcpy(data.dia,"Dez"); break;
        case 11 : strcpy(data.dia,"Onze"); break;
        case 12 : strcpy(data.dia,"Doze"); break;
        case 13 : strcpy(data.dia,"Treze"); break;
        case 14 : strcpy(data.dia,"Quatorze"); break;
        case 15 : strcpy(data.dia,"Quinze"); break;
        case 16 : strcpy(data.dia,"Dezesseis"); break;
        case 17 : strcpy(data.dia,"Dezessete"); break;
        case 18 : strcpy(data.dia,"Dezoito"); break;
        case 19 : strcpy(data.dia,"Dezenove"); break;
        case 20 : strcpy(data.dia,"Vinte"); break;
        case 21 : strcpy(data.dia,"Vinte e um"); break;
        case 22 : strcpy(data.dia,"Vinte e dois"); break;
        case 23 : strcpy(data.dia,"Vinte e três"); break;
        case 24 : strcpy(data.dia,"Vinte e quatro"); break;
        case 25 : strcpy(data.dia,"Vinte e cinco"); break;
        case 26 : strcpy(data.dia,"Vinte e seis"); break;
        case 27 : strcpy(data.dia,"Vinte e sete"); break;
        case 28 : strcpy(data.dia,"Vinte e oito"); break;
        case 29 : strcpy(data.dia,"Vinte e nove"); break;
        case 30 : strcpy(data.dia,"Trinta"); break;
        case 31 : strcpy(data.dia,"Trinta e um"); break;
    }
    switch (data.mes1){
        case 1 : strcpy(data.mes,"Janeiro"); break;
        case 2 : strcpy(data.mes,"Fevereiro"); break;
        case 3 : strcpy(data.mes,"Março"); break;
        case 4 : strcpy(data.mes,"Abril"); break;
        case 5 : strcpy(data.mes,"Maio"); break;
        case 6 : strcpy(data.mes,"Junho"); break;
        case 7 : strcpy(data.mes,"Julho"); break;
        case 8 : strcpy(data.mes,"Agosto"); break;
        case 9 : strcpy(data.mes,"Setembro"); break;
        case 10 : strcpy(data.mes,"Outubro"); break;
        case 11 : strcpy(data.mes,"Novembro"); break;
        case 12 : strcpy(data.mes,"Dezembro"); break;
    }
}