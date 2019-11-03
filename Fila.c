/*Fila Encadeada com Cabeça Especial
Implementação das operações:
1.criarFila();
2.isVazia();
3.inserir();
4.remover();
5.exibir();
6.esvaziar().
*/

#include <stdio.h>
#include <stdlib.h>


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
    if (novo == NULL){
				printf("\nErro: Memória Insuficiente!");
        return 0; // Erro: memoria insuficiente
		}

    novo->dado = valor;

    if (isVazia(fila)){
        fila->inicio = novo;
		}else{
        (fila->final)->prox = novo;
		}

    fila->final = novo;
    fila->quant_element++;
    return 1;
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

t_elemento esvaziar(t_fila * fila){
	int i;
	t_no *aux;
	t_elemento valor = { "" } ;
	while(isVazia(fila)){
		valor = remover(fila);
	}
	return valor;
}

int main(void) {
  t_fila filinha;
	t_elemento nomesLista;
	t_no umNo;

	int contador;

	/*
	criarFila() == criaCabeca()
	Criando a cabeça e o nó da filinha:
	*/
	filinha = *criaCabeca();
	umNo = *criaNo();

	//Usando isVazia() para verificar se a lista está vazia:
	if (isVazia(&filinha) == 1){
		printf("\nA fila está vazia!\n");
	}else{
		printf("\nA fila não está vazia!\n");
	}//Como a fila foi criada recentemente a mensagem deverá ser "A fila está vazia!"
		
	//Usando função inserir() para inserir x (nesse caso 5) valores ou até memória insuficiente:
	for(contador = 0;(contador < 5)  || ((inserir(&filinha, nomesLista)) == 0);contador++){
		printf("\nInsira um nome para adicionar a lista: ");
		scanf("%s", nomesLista.nome);
		inserir(&filinha, nomesLista);
	}

	//Usando isVazia() para verificar novamente se a lista está vazia:
	if (isVazia(&filinha) == 1){
		printf("\nA fila está vazia!\n");
	}else{
		printf("\nA fila não está vazia!\n");
	}//Como a fila recebeu 5 nomes a mensagem deverá ser "A fila não está vazia!"
	
	//Usando função remover() para remover o primeiro valor da lista, depois mostrando o nome removido:
	nomesLista = remover(&filinha);
	printf("\n%s removido da lista!", nomesLista.nome);

	//exibir(&filinha);
	//Exibindo valores em filinha:
	for(contador = 0;contador >= filinha.quant_element;contador++){
		printf("\n%s", filinha.inicio->prox);
	}

	//esvaziar():
	esvaziar(&filinha);

	//Usando isVazia() para verificar se a lista está vazia:
	if (isVazia(&filinha) == 1){
		printf("\nA fila está vazia!\n");
	}else{
		printf("\nA fila não está vazia!\n");
	}//A mensagem deverá ser "A fila está vazia!"
  return 0;
}
