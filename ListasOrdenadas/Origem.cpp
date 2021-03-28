//#include "pch.h" //não roda em versões anteriores a VS 2019 ou DEV C++
#include<stdio.h>							 
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define qtdcadastro 2;//constante

//declaração das funções
void BubbleSort(char vet[10]);
void Listar();

//estrutura definida para o cadastro
struct Lista_Cadastro {

	char nome[60];
	int ano_nasc;

} cadastro[10];

int main() {

	//declaração da variável
	char vet[10];
		
	printf("***************Inicie o cadastro**************\n\n\n\n");

	//laço de repetição até completar o cadastro
	for (int i = 0; i < qtdcadastro i++) {
		printf("Digite o nome do cadastro:\t");
		fflush(stdin);
		scanf_s("%s", &cadastro[i].nome, sizeof(cadastro[i].nome));
		printf("Digite o ano de nascimento:\t");
		fflush(stdin);
		scanf_s("%d", &cadastro[i].ano_nasc, sizeof(cadastro[i].ano_nasc));
	}
	//chamada da função de ordenação
	printf("Ordenando cadastro.\n");
	BubbleSort(vet);

	system("pause");

	//chamada da função de listagem
	printf("Apresentando o cadastro.\n");
	Listar();

	system("pause");
	return(0);
}
//função de ordenação
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
//função para listar os dados do cadastro
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