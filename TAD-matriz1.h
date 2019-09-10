#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int** mat;
    int linhas;
    int colunas;
} Matriz;

typedef struct{
    int* vetor;
    int qte_elementos;
}Vetor;

Matriz *matriz_cria(int linhas, int colunas);
void matriz_destroi(Matriz *m);
int matriz_acessa1(Matriz *m, int lin, int col);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
void matriz_imprime(Matriz *m);
int matriz_linhas(Matriz* m);
int matriz_colunas(Matriz* m);
//void matriz_map1(Matriz* m, void (*funcao)(int*));
Vetor* matriz_vetorlinha(Matriz* m, int lin);
Vetor* matriz_vetorcoluna(Matriz* m, int coluna);
Matriz* matriz_multiplica(Matriz* a, Matriz* b);
int matriz_ehQuadrada(Matriz* m);
int matriz_ehDiagonal(Matriz* m);
Matriz* matriz_transposta(Matriz* m);
Matriz* matriz_oposta(Matriz* m);

Matriz* matriz_cria(int linhas, int colunas){
    Matriz *m1 = (Matriz*) malloc(sizeof(Matriz));
    m1->mat = (int**) calloc(linhas,sizeof(int*));
    for(int i = 0; i < linhas; i++)
        m1->mat[i] = (int*) calloc(colunas, sizeof(int));
    m1->linhas = linhas;
    m1->colunas = colunas;

    return m1;
}

void matriz_destroi(Matriz *m){
    for(int i = 0; i < m->linhas; i++){
        free(m->mat[i]);
    }
    free(m->mat);
    free(m);
}

int matriz_acessa1(Matriz *m, int lin, int col){
    if(lin > m->linhas || col > m->colunas){
        return NULL;
    }
    else{
        return m->mat[lin][col];
    }
}

void matriz_acessa2(Matriz *m, int lin, int col, int *end){
    if(lin > m->linhas || col > m->colunas){}
    else{
        *end = m->mat[lin][col];
    }
}

void matriz_atribui(Matriz *m, int lin, int col, int valor){
    if(lin <= m->linhas && col <= m->colunas)
        m->mat[lin][col] = valor;
}

void matriz_imprime(Matriz *m){
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            printf("%d\t",m->mat[i][j]);
        }
        printf("\n");
    }
}

int matriz_linhas(Matriz* m){
    return m->linhas;
}

int matriz_colunas(Matriz* m){
    return m->colunas;
}


Vetor* matriz_vetorlinha(Matriz* m, int lin){
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->vetor = (int*) calloc(m->colunas,sizeof(int));
    v->qte_elementos = m->colunas;
    for(int i = 0; i < m->colunas; i++){
        v->vetor[i] = m->mat[lin][i];
    }
    return v;
}

Vetor* matriz_vetorcoluna(Matriz* m, int coluna){
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->vetor = (int*) calloc(m->linhas,sizeof(int));
    v->qte_elementos = m->linhas;
    for(int i = 0; i < m->linhas; i++){
        v->vetor[i] = m->mat[coluna][i];
    }
    return v;
}

Matriz* matriz_multiplica(Matriz* a, Matriz* b){
    Matriz* c = (Matriz*) malloc(sizeof(Matriz)); 
    if(a->colunas == b->linhas){
        //Criação da matriz
        c->mat = (int**) calloc(a->linhas,sizeof(int*));
        for(int i = 0; i < a->linhas; i++)
            c->mat[i] = (int*) calloc(b->colunas, sizeof(int));
        c->linhas = a->linhas;
        c->colunas = b->colunas;
        
        //Calculo
        int cont;
        for(int i=0; i < a->linhas ;i++){
            for(int k=0; k < b->colunas ;k++){
                cont=0;
                for(int j=0; j < a->colunas; j++){
                    cont+=a->mat[i][j]*b->mat[j][k];
                }
                c->mat[i][k]=cont;
            }
        }
        return c;
    }
    else if(b->colunas == a->linhas){
        //Criação da matriz
        c->mat = (int**) calloc(b->linhas,sizeof(int*));
        for(int i = 0; i < b->linhas; i++)
            c->mat[i] = (int*) calloc(a->colunas, sizeof(int));
        c->linhas = b->linhas;
        c->colunas = a->colunas;
        
        //Calculo
        int cont;
        for(int i=0; i < b->linhas ;i++){
            for(int k=0; k < a->colunas ;k++){
                cont=0;
                for(int j=0; j < b->colunas; j++){
                    cont+=a->mat[i][j]*b->mat[j][k];
                }
                c->mat[i][k]=cont;
            }
        }
        return c;
    }
    else{
        free(c);
        return NULL;
    }
}

int matriz_ehQuadrada(Matriz* m){
    if(m->linhas == m->colunas){
        return 1;
    }
    else{
        return 0;
    }
}

int matriz_ehDiagonal(Matriz* m){
    int contador1 = 0, contador2 = 0;
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; i++){
            if(i != j){
                contador1++;
            }
            if(i == j && m->mat[i][j] != 0){
                contador2++;
            }
        }
    }
    if(contador1 == 0 && contador2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int matriz_ehIdentidade(Matriz* m){
    int contador1 = 0, contador2 =0;
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; i++){
            if(i == j){
                contador1++;
            }
            else{
                contador2++;
            }
        }
    }
    if(contador1 == 3 && contador2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

Matriz* matriz_transposta(Matriz* m){
    Matriz* m1 = (Matriz*) malloc(sizeof(Matriz));
    m1->mat = (int**) calloc(m->colunas, sizeof(int*));
    for(int i = 0; i < m->colunas; i++){
        m1->mat[i] = (int*) calloc(m->linhas, sizeof(int));
    }
    m1->linhas = m->colunas;
    m1->colunas = m->linhas;
    for(int i = 0 ; i < m1->linhas; i++){
        for(int j = 0; j < m1->colunas; j++){
            m1->mat[i][j] = m->mat[j][i];
        }
    }
    return m1;
}

Matriz* matriz_oposta(Matriz* m){
    Matriz* m1 = (Matriz*) malloc(sizeof(Matriz));
    m1->mat = (int**) calloc(m->linhas, sizeof(int*));
    for(int i = 0; i < m->linhas; i++){
        m1->mat[i] = (int*) calloc(m->colunas, sizeof(int));
    }
    m1->linhas = m->linhas;
    m1->colunas = m->colunas;
    for(int i = 0 ; i < m1->linhas; i++){
        for(int j = 0; j < m1->colunas; j++){
            m1->mat[i][j] = -1*(m->mat[i][j]);
        }
    }
}