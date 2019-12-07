#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int linha;
    int coluna;
    int valor;
    struct node* direita;
    struct node* baixo;        
    struct node* esquerda;
    struct node* cima;
    
}Node;

typedef struct{
    Node** linhas;    //ponteiro para o vetor cujas células são ponteiros de nós
    Node** colunas;    //ponteiro para o vetor cujas células são ponteiros de nós
    int numLinhas;    //Quantidade de linhas da matriz
    int numColunas;    //Quantidade de colunas da matriz
}Matriz;

Matriz *matriz_criar(int qtdeLinhas, int qtdeColunas);
int matriz_atribuir(Matriz *m, int linha, int coluna, int valor);
int matriz_acessar(Matriz *m, int linha, int coluna);
void matriz_imprimir(Matriz *m);
void matriz_desalocar(Matriz *m);

/*
    Cria uma matriz vazia e devolve seu endereço de memória.
*/
Matriz *matriz_criar(int qtdeLinhas, int qtdeColunas){
    Matriz* m = (Matriz*) malloc(sizeof(Matriz));
    m->numColunas = qtdeColunas;
    m->numLinhas = qtdeLinhas;
    m->linhas = (Node**) calloc(qtdeLinhas,sizeof(Node*));
    for(int i = 0; i < qtdeLinhas; i++){
        Node* sentinela = (Node*) malloc(sizeof(Node));
        sentinela->direita = sentinela->esquerda = sentinela;
        m->linhas[i] = sentinela;
    }
    m->colunas = (Node**) calloc(qtdeColunas,sizeof(Node*));
    for (int i = 0; i < qtdeColunas; i++){
        Node* sentinela = (Node*) malloc(sizeof(Node));
        sentinela->baixo = sentinela->cima = sentinela;
        m->colunas[i] = sentinela;
    }
    return m;
}

/*
    Procura se existe um nó na posição
    1 - Se existir retorna o Nó
    2 - Se não existir Retorna NULL
                                        */
Node* VerificaPosicao(Matriz* m, int linha, int coluna){
    Node* aux = m->linhas[linha]->direita;
    for(int i = 0; i < m->numColunas; i++){
        if(aux->coluna == coluna && aux->linha == linha)
            return aux;
        aux = aux->direita;
    }
    return NULL;
}

/*
    Cria Nó com os ponteiros apontados para NULL
                                                */
Node* CriaNo(int linha, int coluna, int valor){
    Node* n = (Node*) malloc(sizeof(Node));
    n->valor = valor;
    n->coluna = coluna;
    n->linha = linha;
    n->baixo = n->cima = n->direita = n->esquerda = NULL;
    return n;
}

int insereLinha(Matriz* m, int linha, int coluna, Node* n){
    // Verifica quantos nós existem na linha
    Node* aux = m->linhas[linha]->direita;
    int qtde = 0;
    while(aux != m->linhas[linha]){
        aux = aux->direita;
        qtde++;
    }
    // Se não existir nenhum Apenas insere
    if(qtde == 0){
        m->linhas[linha]->direita = m->linhas[linha]->esquerda = n;
        n->direita = n ->esquerda = m->linhas[linha];
    }
    //Se não, procura a posição que deve inserir
    else{
        aux = m->linhas[linha]->direita;
        //Caso o valor da coluna já existente seja menor que o do(s) nó(s) existente(s)
        for(int i = 0 ; i < qtde; i++){
            if(aux->coluna > coluna){
                aux->esquerda->direita = n;
                n->esquerda = aux->esquerda;
                aux->esquerda = n;
                n->direita = aux;
                return 1;
            }
            if(aux->direita != m->linhas[linha])
                aux = aux->direita;
        }
        //Se não houve inserção significa que é após o ultimo nó já existente
        aux->direita->esquerda = n;
        n->direita = aux->direita;
        aux->direita = n;
        n->esquerda = aux;
        return 2;
    }
}  

int insereColuna(Matriz* m, int linha, int coluna, Node* n){
    // Verifica quantos nós existem na coluna
    Node* aux = m->colunas[coluna]->baixo;
    int qtde = 0;
    while(aux != m->colunas[coluna]){
        aux = aux->baixo;
        qtde++;
    }
    // Se não existir nenhum Apenas insere
    if(qtde == 0){
        m->colunas[coluna]->baixo = m->colunas[coluna]->cima = n;
        n->baixo = n ->cima = m->colunas[coluna];
    }
    //Se não, procura a posição que deve inserir
    else{
        aux = m->colunas[coluna]->baixo;
        //Caso o valor da coluna já existente seja menor que o do(s) nó(s) existente(s)
        for(int i = 0 ; i < qtde; i++){
            if(aux->linha > linha){
                aux->baixo->cima = n;
                n->cima = aux->cima;
                aux->cima = n;
                n->baixo = aux;
                return 1;
            }
            if(aux->baixo != m->colunas[coluna])
                aux = aux->baixo;
        }
        //Se não houve inserção significa que é após o ultimo nó já existente
        aux->baixo->cima = n;
        n->baixo = aux->baixo;
        aux->baixo = n;
        n->cima = aux;
        return 2;
    }
}


/*
    Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. 
    Caso a posição já exista, substitua o valor da célula.
*/
/*

    PARA A ATRIBUIÇÃO

    1 - Verifica se existe a posição
        2.1 Se existir substitui
        2.2 Se não existir cria e insere 
            3 Verifica quantos nós existem na Linha/Coluna
                3.1 Se não existir Apenas insere
                3.2 Se existir
                    4.1 Verifica onde deve inserir
                    4.2 Insere
*/
int matriz_atribuir(Matriz *m, int linha, int coluna, int valor){
    if(linha >= m->numLinhas || linha < 0 || coluna >= m->numColunas || coluna < 0) return 0;
    if(m == NULL)   return 0;

    Node* aux;
    if(VerificaPosicao(m,linha,coluna) != NULL){
        aux = VerificaPosicao(m,linha,coluna);
        aux->valor = valor;
        return 1;
    }
    else{
        aux = CriaNo(linha,coluna,valor);
        int  a = insereLinha(m,linha,coluna,aux);
        int  b = insereColuna(m,linha,coluna,aux);
        return 1;
    }
}

/*
    Devolve o valor correspondente a linha e coluna solicitada. 
    Faça a validação dos índices. 
    Caso a posição solicitada esteja fora do intervalo, devolva zero.
*/
int matriz_acessar(Matriz *m, int linha, int coluna){
    if(linha >= m->numLinhas || linha < 0 || coluna >= m->numColunas || coluna < 0) return 0;
    if(m == NULL)   return 0;

    if(VerificaPosicao(m,linha,coluna) != NULL)
        return VerificaPosicao(m,linha,coluna)->valor;
    else
        return 0;
}

/*
    Imprime os valores da matriz na tela.
*/
void matriz_imprimir(Matriz *m){
    Node* aux;
    for(int i = 0; i < m->numLinhas; i++){
        aux = m->linhas[i]->direita;
        for(int j = 0; j < m->numColunas; j++){
                if(aux->coluna == j){
                    printf("%d\t",aux->valor);
                    aux = aux->direita;
                }
                else
                    printf("0\t");
                }
        printf("\n");
    }
}
/*
    Libera toda memória alocada dinamicamente para a matriz.
*/
void matriz_desalocar(Matriz *m){
    Node* aux;
    // Desaloca linha
    for(int i = 0; i < m->numLinhas; i++){
        aux = m->linhas[i]->direita;
        while(aux != m->linhas[i]){
            aux = aux->direita;
            free(aux->esquerda->baixo);
            free(aux->esquerda->cima);
            free(aux->esquerda->direita);
            free(aux->esquerda->esquerda);
            free(aux->esquerda);
        }
        free(aux->direita);
        free(aux->esquerda);
        free(aux);
        free(m->linhas[i]);
    }
    free(m->linhas);

    // Desaloca coluna
    for(int i = 0; i < m->numColunas; i++){
        aux = m->colunas[i]->baixo;
        while(aux != m->colunas[i]){
            aux = aux->baixo;
            free(aux->cima->baixo);
            free(aux->cima->cima);
            free(aux->cima->direita);
            free(aux->cima->esquerda);
            free(aux->cima);
        }
        free(aux->baixo);
        free(aux->cima);
        free(aux);
        free(m->colunas[i]);
    }
    free(m->colunas);

    //Desaloca matriz
    free(m);
}