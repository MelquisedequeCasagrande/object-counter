// Autor: Melquisedeque Casagrande

// Cabeçalho da pilhas

// struct responsável por armazenar as coordenadas de um ponto na imagem
typedef struct ponto{
    int x;
    int y;
} Ponto;

// struct com os nós da pilha, vai conter a localização do proximo elemento
typedef struct node{
    struct ponto localizacao;
    struct node* proximo;
} Node;

// pilha vai conter a posição o primeiro e do ultimo elemento
typedef struct pilha{
    struct node* primeiro;
    struct node* ultimo;
} Pilha;


// prototipo das funçoes
Pilha *criaPilha();
void push(Ponto , Pilha*);
Ponto pop(Pilha*);
void destroi(Pilha*);
int isempty(Pilha*);
