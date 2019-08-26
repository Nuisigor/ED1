#include <stdio.h>

int inverso(int num){
    int inv = 0;
    while(num != 0){
        inv = inv*10 + num%10;
        num-= num%10;
        num/=10;
    }
    return inv;
}

void inverso1(int num,int *inver){
    while (num != 0)
    {
        *inver = *inver * 10 + num % 10;
        num -= num % 10;
        num /= 10;
    }
}

int main(){
    //Teste 1
    printf("123: %d\n", inverso(123));
    printf("1376: %d\n", inverso(1376));
    printf("1000: %d\n", inverso(1000));
    printf("5104: %d\n", inverso(5104));
    printf("25603: %d\n", inverso(25603));
    printf("10010: %d\n", inverso(10010));

    printf("\n\n\n\n\n");
    
    //Teste 2
    int inverso = 0;
    inverso1(123, &inverso);
    printf("123: %d\n", inverso);
    inverso = 0;
    inverso1(1376, &inverso);
    printf("1376: %d\n", inverso);
    inverso = 0;
    inverso1(1000, &inverso);
    printf("1000: %d\n", inverso);
    inverso = 0;
    inverso1(5104, &inverso);
    printf("5104: %d\n", inverso);
    inverso = 0;
    inverso1(25603, &inverso);
    printf("25603: %d\n", inverso);
    inverso = 0;
    inverso1(10010, &inverso);
    printf("10010: %d\n", inverso);
}