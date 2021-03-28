//#include "pch.h" //n�o roda em vers�es anteriores a VS 2019 ou DEV C++
#include<stdio.h>							 
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define qtdcadastro 2;//constante

//declara��o das fun��es
void BubbleSort(char vet[10]);
void Listar();

//estrutura definida para o cadastro
struct Lista_Cadastro {

	char nome[60];
	int ano_nasc;

} cadastro[10];

int main() {

	//declara��o da vari�vel
	char vet[10];
		
	printf("***************Inicie o cadastro**************\n\n\n\n");

	//la�o de repeti��o at� completar o cadastro
	for (int i = 0; i < qtdcadastro i++) {
		printf("Digite o nome do cadastro:\t");
		fflush(stdin);
		scanf_s("%s", &cadastro[i].nome, sizeof(cadastro[i].nome));
		printf("Digite o ano de nascimento:\t");
		fflush(stdin);
		scanf_s("%d", &cadastro[i].ano_nasc, sizeof(cadastro[i].ano_nasc));
	}
	//chamada da fun��o de ordena��o
	printf("Ordenando cadastro.\n");
	BubbleSort(vet);

	system("pause");

	//chamada da fun��o de listagem
	printf("Apresentando o cadastro.\n");
	Listar();

	system("pause");
	return(0);
}
//fun��o de ordena��o
void BubbleSort(char vet[10]) {
	
	int aux;
	
	for (int n = 1; n <= qtdcadastro n++) {
		for (int i = 0; i < qtdcadastro - 1, i++)
		{
			if (vet[i] > vet[i + 1]) {
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}
		}
	}
}
//fun��o para listar os dados do cadastro
void Listar()
{
	if (cadastro == NULL) {
		return;
	}
	for (int i = 0; i < qtdcadastro i++) {
		printf("Nome: ");
		printf("%s", cadastro[i].nome);
		printf(" - ");
		printf("Ano Nascimento: ");
		printf("%d", cadastro[i].ano_nasc);
		printf("\n");
	}

	printf("\n");
	
	return;
}