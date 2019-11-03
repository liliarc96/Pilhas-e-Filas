#include <stdio.h>
#include <stdlib.h>

// tamanho maximo da fila
#define MAX 3

// Tipo base dos elementos da lista 
typedef struct elementos {
    char nome[50];
} t_elemento;

typedef struct no {
    t_elemento dado;
    struct no * prox;
} t_no;

typedef struct fila {
    t_no* inicio;
    int quant_element;
    t_no* final;
} t_fila;


/**
 * Cria uma fila vazia, ou seja um no cabeca.
 * inicializa os ponteiros ini e fim para NULL,
 * e seta quant_element para zero.
 * 
 * @return no cabeca alocado e inicializado
 */
t_fila * criaCabeca ()
{
    t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

    if (fila) {
        fila->inicio = fila->final = NULL;
        fila->quant_element=0;
    }

    return fila;
}

/**
 * Cria um novo no, aloca a sua regiao de memoria,
 * inicializa o ponteiro prox, e retorna o ponteiro para a pilha criada.
 * 
 * @return No alocada e inicializada
 */
t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    // verifica se houve memoria suficiente para alocar
    if (no)
        no->prox = NULL;

    return no;
}

/**
 * Verifica se a fila esta vazia ou nao. Isto so acontece quando ela eh nula
 * 
 * @param fila ponteiro para a fila
 *
 * @return Verdadeiro (1) se a fila estiver vazia, ou falso (0) caso contrario.
 */
int isVazia (t_fila * fila)
{
    return (fila->quant_element == 0);
}

/**
 * Insere um elemento (valor) no fim da fila.
 * 
 * @param fila ponteiro para a fila
 * @param valor  elemento a ser inserido na fila
 *
 * @return Falso(0) se a fila estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int inserir (t_fila *fila, t_elemento valor) {
    t_no *novo;
    novo = criaNo();
    if (novo == NULL)
        return 0; // Erro: memoria insuficiente
    novo->dado = valor;
    if (isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;
    fila->final = novo;
    fila->quant_element++;
    return 1;
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

/**
 * Remove um elemento do inicio da fila.
 * 
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return o elemento removido.
 */
t_elemento remover (t_fila *fila)
{
    t_no *aux;
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor; // Erro: fila vazia 
    valor = (fila->inicio)->dado;
    if (fila->inicio == fila->final)
        fila->final = NULL;
    aux = fila->inicio;
    fila->inicio = (fila->inicio)->prox;
    free(aux);
    fila->quant_element--;
    return valor;
}


int main(void) {
  t_fila filinha;
	t_elemento nomesLista;
	t_no umNo;

	//Criando a cabeça e o nó da filinha:
	filinha = *criaCabeca();
	umNo = *criaNo();

	

  return 0;
}
