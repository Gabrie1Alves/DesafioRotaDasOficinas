#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int numArabico(){
	int numArabico;
	
	
	printf("Digite um numero entre 1 e 3999\n"); //verificando se o numero informado respeita a regra
	scanf("%d", &numArabico);
	while(numArabico > 3999 || numArabico < 1){
		printf("Digite um numero entre 1 e 3999\n");
		fflush(stdin);
		scanf("%d", &numArabico);
	}
	return numArabico;
}

void numRomano(char* valorFinal){
	char numeroRomano[20];
	char decide[7] = {'M','D','C','L','X','V','I'};
	int count = 0, verifica = 1;
	
	while(verifica != 0){
		printf("Digite o numero: \n");
		verifica = 0;
		//Pegando o array de caracter em ROMANO
		fflush(stdin);
		for(int i = 0; i<20; i++){
			scanf("%c", &numeroRomano[i]);
			if(numeroRomano[i] == '\n' || i == 19){
				numeroRomano[i] = '\0';
				break;
			}
			if(numeroRomano[i] == '\0'){
				break;
			}
		}
		
		//Convertendo string para maiusculo
		strupr(numeroRomano);
	
		//Veficando se as letras são corretas
		for(int i = 0; i < (strlen(numeroRomano)); i++){
			if(numeroRomano[i] != 'M' && numeroRomano[i] != 'D' &&numeroRomano[i] != 'C' &&numeroRomano[i] != 'L' &&numeroRomano[i] != 'X' &&numeroRomano[i] != 'V' &&numeroRomano[i] != 'I'){
				verifica++;
			}
		}
		
		//verificando a quantidade dos algarismos (max 3 repetições)
		for(int i = 0; i<7; i++){
			count = 0;
			for(int j = 0; j < (strlen(numeroRomano)); j++){
				if(decide[i] == numeroRomano[j]){
					count++;
					if(count == 3){
						if(numeroRomano[j+1] == decide[i]){
							verifica++;
						}
					}
				}
				if(count > 4){
					
					verifica++;//se verifica for != de 0, o numero romano está errado!
				}
			}
		}
		
		//verificar a ordem os caracteres do numero romano
		//cada vez que detectar 1 ordem de caracteres errada ex(DM) -> verifica++; 
		for(int i = 1; i < (strlen(numeroRomano)); i++){
			if((numeroRomano[i] == 'M' && numeroRomano[i-1] == 'D') || (numeroRomano[i] == 'M' && numeroRomano[i-1] == 'X') || (numeroRomano[i] == 'M' && numeroRomano[i-1] == 'L') || (numeroRomano[i] == 'M' && numeroRomano[i-1] == 'V') || (numeroRomano[i] == 'M' && numeroRomano[i-1] == 'I')){
				verifica++;
			}
			if((numeroRomano[i] == 'D' && numeroRomano[i-1] == 'L') || (numeroRomano[i] == 'D' && numeroRomano[i-1] == 'X') || (numeroRomano[i] == 'D' && numeroRomano[i-1] == 'V') || (numeroRomano[i] == 'D' && numeroRomano[i-1] == 'I')){
				verifica++;
			}
			if((numeroRomano[i] == 'C' && numeroRomano[i-1] == 'L') || (numeroRomano[i] == 'C' && numeroRomano[i-1] == 'V') || (numeroRomano[i] == 'C' && numeroRomano[i-1] == 'I')){
				verifica++;
			}
			if((numeroRomano[i] == 'L' && numeroRomano[i-1] == 'V') || (numeroRomano[i] == 'L' && numeroRomano[i-1] == 'I') || (numeroRomano[i] == 'X' && numeroRomano[i-1] == 'V') || (numeroRomano[i] == 'V' && numeroRomano[i-1] == 'V')){
				verifica++;
			}
		}
		
		// verificando valores com 3 caracteres ex (DDC -> verifica++;)
		if(strlen(numeroRomano) > 2){ 
			for(int i = 2; i< (strlen(numeroRomano)); i++){
				if(((numeroRomano[i-2] == 'C') && (numeroRomano[i-1] == 'C') && (numeroRomano[i] == 'M')) || ((numeroRomano[i-2] == 'C') && (numeroRomano[i-1] == 'C') && (numeroRomano[i] == 'D'))){
					verifica++;
				}
				if(((numeroRomano[i-2] == 'D') && (numeroRomano[i-1] == 'D') && (numeroRomano[i] == 'C')) || ((numeroRomano[i-2] == 'X') && (numeroRomano[i-1] == 'X') && (numeroRomano[i] == 'C'))){
					verifica++;
				}
				if(((numeroRomano[i-2] == 'D') && (numeroRomano[i-1] == 'D') && (numeroRomano[i] == 'L')) || ((numeroRomano[i-2] == 'X') && (numeroRomano[i-1] == 'X') && (numeroRomano[i] == 'L'))){
					verifica++;
				}
				if(((numeroRomano[i-2] == 'L') && (numeroRomano[i-1] == 'L') && (numeroRomano[i] == 'M')) || ((numeroRomano[i-2] == 'D') && (numeroRomano[i-1] == 'D') && (numeroRomano[i] == 'X'))){
					verifica++;
				}
				if(((numeroRomano[i-2] == 'D') && (numeroRomano[i-1] == 'D') && (numeroRomano[i] == 'I')) || ((numeroRomano[i-2] == 'L') && (numeroRomano[i-1] == 'L') && (numeroRomano[i] == 'I'))){
					verifica++;
				}
				if(((numeroRomano[i-2] == 'I') && (numeroRomano[i-1] == 'I') && (numeroRomano[i] == 'V')) || ((numeroRomano[i-2] == 'D') && (numeroRomano[i-1] == 'D') && (numeroRomano[i] == 'V')) || ((numeroRomano[i-2] == 'L') && (numeroRomano[i-1] == 'L') && (numeroRomano[i] == 'V'))){
					verifica++;
				}
			}	
		}
	}
	//passando o numero romano de volta para a main utilizando o ponteiro valorFinal
	for(int i = 0; i<(strlen(numeroRomano)); i++){
		valorFinal[i] = numeroRomano[i];
	}
}



void tranformaEmRomano(int a){
	char romano[20];
	int mil, cem, dez, um, valor = a, i=0;
	
	
	mil = a/1000;
	a = a - mil*1000; //acaba com as colunas de milhar
	if(mil != 0){
		if(mil == 1){
			romano[i] = 'M';
			i++;
		}else if(mil == 2){
			romano[i] = 'M';
			romano[i+1] = 'M';
			i += 2;
		}else if(mil == 3){
			romano[i] = 'M';
			romano[i+1] = 'M';
			romano[i+2] = 'M';
			i += 3;
		}
	}

	if(a >=900){ 
		romano[i] = 'C';
		romano[i+1] = 'M';
		i+=2;
		a = a-900;
	}else if (a >=500){
		if(a >=800){
			romano[i] = 'D';
			romano[i+1] = 'C';
			romano[i+2] = 'C';
			romano[i+3] ='C';
			i+=4;
			a = a-800;
		}else if(a >=700){
			romano[i] = 'D';
			romano[i+1] ='C';
			romano[i+2] = 'C';
			i+=3;
			a = a-700;
		}else if(a >=600){
			romano[i] = 'D';
			romano[i+1] = 'C';
			i+=2;
			a = a-600;
		}else if(a >=500){
			romano[i] = 'D';
			i++;
			a = a -500;
		}
	}
	
	if(a >= 100 && a < 500){
		cem = a/100;
		if(cem == 4){
			romano[i] = 'C';
			romano[i+1] = 'D';
			i+=2;
			a = a -400;
		}else if(cem == 3){
			romano[i] = 'C';
			romano[i+1] = 'C';
			romano[i+2] = 'C';
			i+=3;
			a = a-300;
		}else if(cem == 2){
			romano[i] = 'C';
			romano[i+1] = 'C';
			i+=2;
			a = a - 200;
		}else if(cem == 1){
			romano[i] = 'C';
			i++;
			a = a - 100;
		}
	}
	
	if(a>=90 && a<100){
		romano[i] = 'X';
		romano[i+1] = 'C';
		i+=2;
		a = a-90;
	}else if (a<90 && a >=50){
		if(a >=80){
			romano[i] = 'L';
			romano[i+1] = 'X';
			romano[i+2] = 'X';
			romano[i+3] ='X';
			i+=4;
			a = a-80;
		}else if(a >=70){
			romano[i] = 'L';
			romano[i+1] = 'X';
			romano[i+2] = 'X';
			i+=3;
			a = a-70;
		}else if(a >= 60){
			romano[i] = 'L';
			romano[i+1] = 'X';
			i+=2;
			a = a-60;
		}else if(a >=50){
			romano[i] = 'L';
			i++;
			a = a -50;
		}
	}
	//valor restante menor que 50 e >=10
	if(a>=10 && a <50){
		dez = a/10;
		if(dez == 4){
			romano[i] = 'X';
			romano[i+1] = 'L';
			i+=2;
			a = a -40;
		}else if(dez == 3){
			romano[i] = 'X';
			romano[i+1] = 'X';
			romano[i+2] = 'X';
			i+=3;
			a = a-30;
		}else if(dez == 2){
			romano[i] = 'X';
			romano[i+1] = 'X';
			i+=2;
			a = a - 20;
		}else if(dez == 1){
			romano[i] = 'X';
			i++;
			a = a - 10;
		}
	}
	
	//valor restante menor ou igual a 9
	if(a>=9){
		romano[i] = 'I';
		romano[i+1] = 'X';
		i+=2;
		a = a-9;
	}else{
		um = a/1;
		if(um == 8){
			romano[i] = 'V';
			romano[i+1] = 'I';
			romano[i+2] = 'I';
			romano[i+3] = 'I';
			i+=4;
	
		}else if(um == 7){
			romano[i] = 'V';
			romano[i+1] = 'I';
			romano[i+2] = 'I';
			i+=3;
		}else if(um == 6){
			romano[i] = 'V';
			romano[i+1] = 'I';
			i+=2;
		}else if(um == 5){
			romano[i] = 'V';
			i+=1;
		}else if(um == 4){
			romano[i] = 'I';
			romano[i+1] = 'V';
			i+=2;
			
		}else if(um == 3){
			romano[i] = 'I';
			romano[i+1] = 'I';
			romano[i+2] = 'I';
			i+=3;
		}else if(um == 2){
			romano[i] = 'I';
			romano[i+1] = 'I';
			i+=2;
		}else if(um == 1){
			romano[i] = 'I';
			i+=1;

		}
	}
	romano[i] = '\0';
	system("cls");
	printf("\n         O numero arabico: %d Convertido para numero romano -> %s\n", valor, romano);
}

void transformaEmArabico(char* num){

	int total = 0;

	//fazendo a transformacao
	//1° verifico se comeca com M
	//2° verifico as restrições como CM, CD... pois são valores diferentes
	//3° verifico os valores normais como D, C ...
	for(int j = 0; j < (strlen(num)); j++){
		if(num[j] == 'M'){ // M
			total+= 1000;
		}else if(num[j] == 'C' && num[j+1] == 'M'){ //CM
			total+=900;
			j++;
		}else if(num[j] == 'C' && num[j+1] == 'D'){ //CD
			total+= 400;
			j++;
		}else if(num[j] == 'X' && num[j+1] == 'C'){//XC
			total += 90;
			j++;
		}else if(num[j] == 'X' && num[j+1] == 'L'){//XL
			total+= 40;
			j++;
		}else if(num[j] == 'I' && num[j+1] == 'X'){//IX
			total += 9;
			j++;
		}else if(num[j] == 'I' && num[j+1] == 'V'){//IV
			total += 4;
			j++;
		}else if(num[j] == 'D'){
			total += 500;
		}else if(num[j] == 'C'){
			total += 100;
		}else if(num[j] == 'L'){
			total += 50;
		}else if(num[j] == 'X'){
			total += 10;
		}else if(num[j] == 'V'){
			total += 5;
		}else if(num[j] == 'I'){
			total += 1;
		}
	}
	system("cls");
	printf("\n         O numero romano: %s Convertido para arabico: %d \n", num, total);
}


int main(){
	/*Para nao dar loop com entrada de char em lugares indevidos 
	utilizei a função fflush(stdin)*/
	int arabico, controle = 1, num = 0 ;
	char romano[20];
	
	while(controle != 0){
		printf("\n  ->  Deseja transformar para romano  - Digite 1\n");
		printf("  ->  Deseja transformar para arabico - Digite 2 \n");
		flush(stdin);
		scanf("%d", &num);
		system("cls");
		while(num != 1 && num!=2){
			
			printf("\n       **Escolha nao permitida!!**\n");
			
			printf("\n  ->  Deseja transformar para numero romano  - Digite 1\n");
			printf("  ->  Deseja transformar para numero arabico - Digite 2 \n");
			fflush(stdin);
			scanf("%d", &num);
			system("cls");
		}
		if(num == 1){
			arabico = numArabico();
			tranformaEmRomano(arabico);
		}else{
			numRomano(romano);
			transformaEmArabico(romano);
		}
		printf("\nDigite 0 para sair ou outra tecla para utilizar a funcao de transformcao:");
		fflush(stdin); 
		scanf("%d", &controle);	
	}
	return 0;
}
