#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // contém os protótipos para manipular arquivos
#include "imagem.h"

unsigned char** abreImg(int n, int* l, int* c) {

    FILE *fp;  // ponteiro para arquivo
    unsigned char **img;
    char id[3];
    char dir[10];
    int colunas, linhas, maximo;
    unsigned char r, g, b; 
    unsigned char rf, gf, bf;
    int i, j, k;
    int posicao;
    
    
    sprintf(dir, ((n < 10) ? "0%d.ppm" : "%d.ppm"), n);
    fp = fopen(dir, "rb"); // abrir arquivo para r - Read no modo b - Binario

    if (fp == NULL) {  // retorna NULL se deu algum problema na abertura
        printf("Houve um problema na abertura do arquivo!");    
        exit(EXIT_FAILURE);  // sai com código de falha
    }
    
    //le os dados dos arquivos e armazena
    fscanf (fp, "%s", id);        // identificador do formato PPM - P6
    fscanf (fp, "%d", &colunas);  // largura da imagem = total de colunas
    fscanf (fp, "%d", &linhas);   // altura da imagem = total de linhas
    fscanf (fp, "%d", &maximo);   // máximo de intensidade (neste trabalho, sempre 256)
    fscanf (fp, "%c", &r);        // consumir um quebra de linha no arquivo

    *c = colunas;
    *l = linhas;

    posicao = ftell(fp); // pegar a posicao fisica no arquivo antes de ler dados da imagem
    // le o pixel 0,0 que é o pixel com a cor do fundo
    fscanf (fp, "%c%c%c", &rf, &gf, &bf);
    fseek(fp, posicao, SEEK_SET); // voltando ao início da imagem

    // alocação da matriz bidimensional
    img = (unsigned char**) calloc(linhas, sizeof(unsigned char*));
    for (k = 0; k < linhas; k++){
        img[k] = (unsigned char*)calloc(colunas, sizeof(unsigned char));
    }

    // lendo os pixels da imagem, para cada pixel ler 3 valores, Red Green Blue (a cor em RGB), e colocando na matriz alocada anteriormente
    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            fscanf (fp, "%c%c%c", &r, &g, &b);
            if ((r!=rf) || (g!=gf)  || (b!=bf)  ){  // houve mudanca de cor em relacao ao fundo
                img[i][j] = '1';       // colocar 1 na matriz alocada
            }
            else{
                img[i][j] = '0';
            }
            
        }
    } 
    //fechando o arquivo da imagem
    fclose(fp);
    return img;
}

// desaloca a matriz
void libera(unsigned char** img , int x, int y){
    for(int i = 0; i < x; i++){
        free(img[i]);            
    }    
    free(img);
}
