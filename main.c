#include <stdio.h>
#include "imagem.h"
#include "pilha.h"

int VerificaVizinho(char c1, char c2){ // verifica se o vizinho do ponto é 1
    return(c1 == c2 && c1 == '1');
}

int VerificaPonto(Ponto p, int x, int y){ // verifica se não está na borda 
    return(p.x > 0 && p.x < x - 1 && p.y > 0 && p.y < y - 1);
}

// função responsavel pra contar o objeto
// parametros imagem, linhas e colunas
// retorna a quantidade de objetos contados


int contaObjeto(unsigned char** imagem, int linhas, int colunas){ 
    Pilha* pilha = criaPilha(); 
    Ponto ponto;
    int objeto = 0;

    for (int i = 1; i < linhas - 1;i++){
        for (int j = 1; j < colunas - 1; j++){
            if (imagem[i][j] == '1'){
                push((Ponto){i,j},pilha);
                while (!isempty(pilha)){ 
                    ponto = pop(pilha);
                    
                    if (VerificaVizinho(imagem[ponto.x][ponto.y], imagem[ponto.x-1][ponto.y]) && VerificaPonto((Ponto){ponto.x-1, ponto.y}, linhas, colunas)){
                        push((Ponto){ponto.x-1, ponto.y}, pilha);
                    }
                    if (VerificaVizinho(imagem[ponto.x][ponto.y], imagem[ponto.x+1][ponto.y]) && VerificaPonto((Ponto){ponto.x+1, ponto.y}, linhas, colunas)){
                        push((Ponto){ponto.x+1, ponto.y}, pilha);
                    }
                    if (VerificaVizinho(imagem[ponto.x][ponto.y], imagem[ponto.x][ponto.y-1]) && VerificaPonto((Ponto){ponto.x, ponto.y-1}, linhas, colunas)){
                        push((Ponto){ponto.x, ponto.y-1}, pilha);   
                    }
                    if (VerificaVizinho(imagem[ponto.x][ponto.y], imagem[ponto.x][ponto.y+1]) && VerificaPonto((Ponto){ponto.x, ponto.y+1}, linhas, colunas)){
                        push((Ponto){ponto.x, ponto.y+1}, pilha);
                    } 
                    imagem[ponto.x][ponto.y] = '0';
                }
                objeto++;  
           }
        }
       
    }
    return objeto;
}


int main(){
    unsigned char** imagem; 
    int arqv, obj, linhas, colunas;

    printf("Informe o nome do arquivo: ");
    scanf("%d", &arqv);
    imagem = abreImg(arqv, &linhas, &colunas);

    obj = contaObjeto(imagem, linhas, colunas);
    printf("%d\n", obj);

    printf("Imagem gerada com sucesso");
    libera(imagem, linhas, colunas);
    return 0;
}   
