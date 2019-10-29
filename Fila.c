#include <stdio.h>

// tamanho maximo da fila
#define MAX 3

// Tipo base dos elementos da fila 
typedef struct elementos {
    char nome[50];	
} t_elemento;

typedef struct fila {
    t_elemento vetor[MAX]; // vetor que armazena a fila
    int inicio; // posicao do primeiro elemento
    int fim;    // posicao do ultimo elemento
    int quant_element;    // numero de elementos da fila
} t_fila;

t_fila criar(){
    t_fila fila;

    fila.inicio = 0;
    fila.fim = -1;
    fila.quant_element = 0;

    return fila;
}

int isVazia (t_fila * fila){
    if(fila->quant_element == 0){
			printf("Está vazia!\n");
			return 0;
		}else{
			printf("A fila não está vazia.\n");
			return 1;
		}
}

int isCheia(t_fila * fila){
    if(fila->quant_element == MAX){
			printf("A fila já está cheia!\n");
			return 1;
		}else{
			printf("A fila ainda tem espaço.\n");
			return 0;
		}
}

int inserir (t_fila * fila, t_elemento valor)
{
    if (isCheia(fila))
        return 0;

    (fila->quant_element)++;
    fila->fim = (fila->fim + 1) % MAX;
    fila->vetor[fila->fim] = valor;
    return 1;
}

t_elemento remover(t_fila * fila)
{
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor; // Erro: fila vazia

    valor = fila->vetor[fila->inicio];
    fila->vetor[fila->inicio].nome[0] = '\0';// zera, opcional
    (fila->quant_element)--;
    fila->inicio = (fila->inicio + 1) % MAX;
    return valor;
}

void mostraFila(t_fila * fila){
    int i;

    if (isVazia(fila)) {
    	printf("Fila vazia\n");
    	return;
    }

		printf("\nExibindo fila:\n");
    printf("inicio: %d\n", fila->inicio);
    printf("fim:    %d\n", fila->fim);

    for (i = fila->inicio; i != fila->fim + 1; i = (i + 1) % MAX){
				printf("%s\t", fila->vetor[i].nome);
		}
    	
}


int main(void) {
  t_fila filinha;
	t_elemento nomesLista;


	filinha = criar();//criando filinha

	//isVazia(&filinha);//está vazia?

	//isCheia(&filinha);//está cheia?

	printf("\nDigite um nome para inserir na lista: ");
	scanf("%s", nomesLista.nome);//input

	inserir(&filinha, nomesLista);//inserindo input anterior

	remover(&filinha);

  return 0;
}
