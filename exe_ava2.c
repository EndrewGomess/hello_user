#include <stdio.h>

#define MAX 1000000
#define TRUE 1
#define FALSE 0

void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho);
void imprime_vetor(int colecao[], int tamanho);
int busca_sequencial(int file[], int inicio, int key, int fim);

struct index
{
    int key;
    int valor_posicao;
};


void main(){
	int arquivo[MAX];
	int chave, inicio, fim;
	int valor_indice;
    int i;
	
	chave = 123456;

	//DEFINIR TABELA
	carrega_vetor_ordenado(arquivo, 1, MAX);
	imprime_vetor(arquivo, MAX);
	
    struct index indice[100];

	//DEFINIR CHAVES DO INDICE
	valor_indice = 1;
	for(i=0; i!=100; i++){
		indice[i].key = valor_indice;
		indice[i].valor_posicao = arquivo[valor_indice];
		valor_indice += 10000;
	}

	//ENCONTRANDO O INDICE QUE SERÁ USADO

	for(i=0; i!=100+1 && indice[i].valor_posicao < chave; i++){
	}

	fim = indice[i].key;
	inicio = indice[i-1].key;
	

	if( busca_sequencial(arquivo, inicio, chave, fim) )
		printf("Existe a chave %d no arquivo.\n", chave);
	else
		printf("Não existe a chave %d no arquivo.\n", chave);

}


//BUSCADOR
int busca_sequencial(int file[], int inicio, int key, int fim){
    int founded = FALSE;
    for(int i = inicio; i < fim && founded == FALSE; i++){
        if(file[i] == key){
            founded = TRUE;
        }
		printf("Busca focada - Posição %d = %d\n", i, file[i]);
    }
    return founded;
}

//CARREGAR E IMPRIMIR DADOS
void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho){
	int i;
	srand( (unsigned) time(NULL) );
	for(colecao[0] = valor_inicial, i=1; i<tamanho; i++){
		colecao[i] = colecao[i-1] + (rand() % 10);
	}
}

void imprime_vetor(int colecao[], int tamanho){

	int i=0;
	for(i=0; i < tamanho; i++){
		printf("[%d] = %d\n", i, colecao[i]);
	}
	printf("\n");
}

