#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[20];
}Cliente;

typedef struct{
	char nome[20];
	float preco;
}Produto;

void preencheCliente(Cliente* cliente, int c){
	for(int i = 0; i<c; i++){
		printf("\nDigite o Nome do cliente numero %d: ", i+1);
		fflush(stdin);
		scanf("%s", cliente[i].nome);
		system("cls");
	}	
}
void preencheProduto(Produto* produto, int p){
	for(int i=0; i<p; i++){
		printf("\nDigite o nome do produto %d:", i+1);
		fflush(stdin);
		scanf("%s", produto[i].nome);
		printf("\nDigite o preco do produto '%s':", produto[i].nome );
		scanf("%f", &produto[i].preco);
		printf("%f", produto[i].preco);
		system("cls");
	}
}
void calculaValor(Cliente* cliente, Produto* produto, int** tabelaGeral, int c, int p){
	int quantidade[p], total = 0, pagar = 0, taxa, taxaTotal;
	float valorPorPessoa[p], valorCliente[c];

	for(int i = 0; i<p; i++){
		for(int j = 0; j<c; j++){
			total = total + tabelaGeral[i][j];
		}
		quantidade[i] = total;
		printf("\n %d pessoas consumiram o produto %s", quantidade[i], produto[i].nome);
		total = 0;
	}

	//dividir o preço pelos clientes que usaram do mesmo
	for(int i = 0; i<p; i++){
		valorPorPessoa[i] = produto[i].preco /quantidade[i];
		printf("\n %f reais para cada pessoa, produto %s", valorPorPessoa[i], produto[i].nome);
	}
	
	//concluir a soma dos valores de cada cliente
	for(int i = 0; i<p; i++){
		for(int j = 0; j<c; j++){
			if(tabelaGeral[i][j] == 1){
				valorCliente[j] += valorPorPessoa[i];
			}
		}
	}
	
	printf("\n*Por favor, informe quem ira pagar a taxa de 10 por cento*\n");
	printf("Pressione 1           -> todos irao pagar\nPressione outra tecla -> Informar o id de 1 cliente para pagar\n  : ");
	scanf("%d", &pagar);
	system("cls");
	
	if(pagar == 1){
		for(int i = 0; i<c; i++){
			valorCliente[i] = valorCliente[i] * 1.1 ;
			printf("\nCliente: %s valor: %f", cliente[i].nome, valorCliente[i]);
		}
	}else{
		for(int i =0; i<c; i++){
			printf("\n%d -> %s", cliente[i].nome);
			printf("\nPessione id correspondente ao da tabela acima: ");
			scanf("%d", &taxa);
			for(int i = 0; i<c; i++){
				if(taxa == i){
					for(int j =0; j<c; j++){
						taxaTotal = valorCliente[j] * 0.1;
					}
					printf("\nCliente: %s valor: %f", cliente[i].nome, valorCliente[i] + taxaTotal);
				}else{
					printf("\nCliente: %s valor: %f", cliente[i].nome, valorCliente[i]);
				}
				
			}
		}
	}	
}

void tabela(Cliente* cliente, Produto * produto, int** tabelaGeral, int c, int p){
	int valor = 0;
	for(int i=0; i<p; i++){
		for(int j=0; j<c; j++){
			printf("\n*Digite 1 para sim    Digite outro valor para nao!*\n");
			printf("\nO cliente %s consumiu o produto %s? ", cliente[j].nome, produto[i].nome);
			fflush(stdin);
			scanf("%d", &valor);
			if(valor == 1){
				tabelaGeral[i][j] = valor;
			}else{
				tabelaGeral[i][j] = 0;
			}
			system("cls");
		}
	}
}

int main(){
	Cliente * cliente;
	Produto * produto;
	int** tabelaGeral;
	int c = 0, p = 0, verifica = 0;
	while(verifica == 0){
		printf("Quantos clientes participaram? E quantos produtos foram consumidos?\n");
		scanf("%d%d", &c, &p);
	
		while(c<0 && p<0){
			printf("*Valores invalidos!*");
			printf("Quantos clientes participaram? E quantos produtos foram consumidos?\n");
			scanf("%d%d", &c, &p);
		}
	
		cliente = (Cliente*)malloc(c * sizeof(Cliente));
		produto = (Produto*)malloc(p * sizeof(Produto));
		if(cliente == NULL){
			printf("\n*Erro de memoria*\n");
			exit(1);
		}
		if(produto == NULL){
			printf("\n*Erro de memoria*\n");
			exit(1);
		}
		//produtoxcliente
		tabelaGeral =(int**)malloc(sizeof(int*)*p);
		if(tabelaGeral == NULL){
			printf("\n*Erro de memoria*\n");
			exit(1);
		}
		for(int i=0; i<p; i++){
			tabelaGeral[i] = (int*)malloc(sizeof(int)*c);
			if(tabelaGeral[i] == NULL){
			printf("\n*Erro de memoria*\n");
			exit(1);
			}
		}
	
	
		preencheCliente(cliente, c);
		preencheProduto(produto, p);
		tabela(cliente, produto, tabelaGeral, c, p);
		calculaValor(cliente, produto, tabelaGeral, c, p);
	
	
		//desalocando memória
		free(cliente);
		free(produto);
		for(int i = 0; i<p;i++){
			free(tabelaGeral[i]);
		}
		free(tabelaGeral);
		
		printf("\n\n\nDeseja fazer outra divisao?\n");
		printf("Digite 0 para sim, ou outro valor para sair!");
		fflush(stdin); // nao dar loop com char
		scanf("%d", &verifica);
	}
	return 0;
}
