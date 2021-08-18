#include "pilha.h"
#include <stdlib.h>

// função responsavel pela criação da pilha
Pilha *criaPilha(){
    Pilha* geraPilha = (Pilha*) malloc(sizeof(Pilha));
    geraPilha->primeiro = NULL;
    geraPilha->ultimo = NULL;
    return geraPilha;   
}
// função responsavel por adicionar os dados na pilha
// recebe par ordenado e armazena na pilha, adiciona no topo pilha
void push(Ponto local, Pilha* p){
    Node* geraNode = (Node*) malloc(sizeof(Node));
    if (geraNode){
        geraNode->localizacao = local; 
        geraNode->proximo = NULL; 
        if (p != NULL){ // testa se tem algum elemento na lista
            if (p->primeiro == NULL && p->ultimo == NULL){ 
                p->primeiro = geraNode; 
            }
            else{
                p->ultimo->proximo = geraNode; 
            }
            p->ultimo = geraNode; 
        }
    }

}
//função responsavel por tirar o elemento do topo 
Ponto pop(Pilha* p){
    if (p){
        Node* guardapos = p->primeiro;  
        Ponto dado; 
        dado = p->ultimo->localizacao;
        if(guardapos->proximo){ 
            while (guardapos->proximo != p->ultimo){ // procura o penultimo elemento da pilha
                guardapos = guardapos->proximo;
            }
            p->ultimo = guardapos; 
            free(guardapos->proximo); 
            p->ultimo->proximo = NULL; 
        }
        else{ 
            free(guardapos); 
            p->primeiro = NULL; 
            p->ultimo = NULL; 
        }
        return dado; 
    }
    return (Ponto){0,0};  
}

//função verifica se a pilha está vazia
int isempty(Pilha* p){ 
    return(p->primeiro == NULL && p->ultimo == NULL);
}
// funçaõ responsável por desalocar a pilha quando acaba o programa
void destroi(Pilha* p){ 
    while (!isempty(p)){
        pop(p);
    }
    free(p); //desaloca a pilha
}



