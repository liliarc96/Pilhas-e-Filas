/*Funcionalidades da Pilha:
1.Criar uma pilha;
2.Testar se a pilha está vazia;
3.Testar se a pilha está cheia;
4.Obter o elemento do topo (sem eliminar);
5.Empilhar um novo elemento (push);
6.Desempilhar o elemento do topo (pop);
7.Exibir os elementos da pilha.
*/

#include <stdio.h>
#define MAX 3

// Tipo base dos elementos da pilha 
typedef struct elementos {
    char nome[50];   
} t_elemento;

// Estrutura da pilha
typedef struct pilha {
    t_elemento vetor[MAX];
    int topo;
} t_pilha;

/**
 * Cria uma nova pilha, aloca a sua regiao de memoria,
 * inicializa o topo, e retorna a pilha criada.
 * 
 * @return Pilha inicializada
 */
t_pilha criar() {
    t_pilha pilha;

    pilha.topo = -1;

    return pilha;
}

/**
 * Verifica se a pilha esta vazia ou nao.
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a pilha estiver vazia, ou falso (0) caso contrario.
 */
int isVazia(t_pilha * pilha) {
		if(pilha->topo == -1){
			//printf("\nA pilha está vazia!");
			return 1;
		}else{
			//printf("\nA pilha não está vazia!");
			return 0;
		}
}

/**
 * Verifica se a pilha esta cheia ou nao.
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a pilha estiver cheia, ou falso (0) caso contrario.
 */
int isCheia(t_pilha * pilha) {
		if(pilha->topo == MAX-1){
			//printf("\nA pilha está cheia!");
			return 1;
		}else{
			//printf("\nA pilha ainda não está cheia!");
			return 0;
		}
}

/*
 * Obter o elemento do topo da pilha (sem eliminar)
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return o elemento desejado, caso a posicao seja invalida retorna vazio.
 */    

t_elemento getElementoTopo(t_pilha * pilha)
{
    t_elemento vazio = { "" } ;

    if (isVazia(pilha))
        return vazio; // erro
    else
        return pilha->vetor[pilha->topo];
}

/**
 * Remove o elemento do topo da pilha (desempilhar), retornando o elemento removido
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 *
 * @return Uma copia do elemento do topo.
 */
t_elemento pop(t_pilha * pilha)
{
    t_elemento vazio = { "" };

    if (isVazia(pilha))
        return vazio; // erro
    else

        return pilha->vetor[pilha->topo--];
}

/**
 * Inserir um novo elemento no topo da pilha (empilhar)
 * 
 * @param pilha ponteiro para a pilha, a pilha ja deve ter sido inicializada
 * @param dado  elemento a ser inserido na pilha
 *
 * @return Falso(0) se a posição for invalida ou se a pilha estiver cheia, caso contrario, retorna Verdadeiro(1)
 */
int push(t_pilha *pilha, t_elemento valor)
{
    if (isCheia(pilha))
        return 0; // erro

    pilha->vetor[++pilha->topo] = valor;
    return 1; // sucesso
}


int main(void) {
  t_pilha umaPilha;
	t_elemento elementoPilha;
	int contador = 0;

	//Criando uma pilha chamada umaPilha, topo começa com valor -1:
	umaPilha = criar();

	//Inserindo elementos na lista (deixando a lista cheia):
	for(;contador <= (MAX-1);contador++){
		printf("\nDigite um nome para inserir na pilha: ");
		scanf("%s", elementoPilha.nome);//input
		push(&umaPilha, elementoPilha);
	}

	if(isCheia(&umaPilha) == 1){
		printf("\nPilha está cheia!");
	}else{
		printf("\nAinda tem espaço na pilha!");
	}//Deve mostrar que a fila está cheia
	
	//Obtendo e mostrando o elemento do topo:
	elementoPilha = getElementoTopo(&umaPilha);
	printf("\nO elemento do topo é: %s", elementoPilha.nome);
	
	//Retira o elemento do topo:
	printf("\nRetirando %s da pilha!", elementoPilha.nome);
	pop(&umaPilha);

	if(isCheia(&umaPilha) == 1){
		printf("\nPilha está cheia!");
	}else{
		printf("\nAinda tem espaço na pilha!");
	}//Deve mostrar que a fila não está mais cheia

	//Mostrando o novo elemento do topo:
	elementoPilha = getElementoTopo(&umaPilha);
	printf("\nO elemento do topo é: %s", elementoPilha.nome);

	//Mostrando toda a lista(deve ter 2 elementos agora):

	printf("\n\nItens da pilha:");
	for(contador = 0; contador <= umaPilha.topo;contador++){
		printf("\n-> %s", umaPilha.vetor[contador].nome);
	}
  return 0;
}
