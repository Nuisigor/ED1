#include <stdio.h>

int inversao(int num){
    int inverso = 0;
    if(num >= 1000){
        inverso += num/1000;
        num = num % 1000;
        inverso += (num/100) * 10;
        num = num % 100;
        inverso += (num/10) * 100;
        num = num % 10;
        inverso += num * 1000;
    }
    else if(num >= 100){
        inverso += (num/100);
        num = num % 100;
        inverso += (num/10) * 10;
        num = num % 10;
        inverso += num * 100;
    }
    else if(num >= 10){
        inverso += (num/10);
        num = num % 10;
        inverso += num * 10;
    }
    else{return num;}
        return inverso;
}


int main(){
    printf("1521 : %d\n",inversao(1521));
    printf("2586 : %d\n",inversao(2586));
    printf("123 : %d\n",inversao(123));
    printf("25 : %d\n",inversao(25));
    printf("5 : %d\n",inversao(5));
}