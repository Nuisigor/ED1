#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_clone(char *str){
    char *str1 = (char*) calloc(20,sizeof(char));
    strcpy(str1, str);
    return str1;
}

int main(){
    char str[20] = "ABC";
    char* copia = string_clone(str);
    printf("%s\n", copia); //"ABC"
}