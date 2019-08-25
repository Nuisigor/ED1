#include <stdio.h>

float potencia(int num,int exp){
    int exp1 = (exp >= 0 ? exp : exp*-1);
    float res = 1;
    for(int i = 0; i < exp1; i++){
        res*=num;
    }
    return (exp >=0 ? res : 1/res);
}

void potencia1(int num,int exp, float *res){
    int exp1 = (exp >= 0 ? exp : exp * -1);
    float res1 = 1;
    for (int i = 0; i < exp1; i++)
    {
        res1*=num;
    }
    *res= (exp >= 0 ? res1 : 1/res1); 
}
int main(){
    //Testes caso 1
    printf("9^3: %.2f\n", potencia(9, 3));
    printf("(-5)^4: %.2f\n", potencia(-5, 4));
    printf("5^-2: %.2f\n", potencia(5, -2));

    printf("\n\n\n\n\n");
    
    //Testes caso 2
    float res;
    potencia1(8, 4, &res);
    printf("8^4: %.2f\n", res);
    potencia1(-5, 4, &res);
    printf("(-5)^4: %.2f\n", res);
    potencia1(5, -2, &res);
    printf("5^-2: %.2f\n", res);
}