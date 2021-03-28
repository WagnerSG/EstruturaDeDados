#include<stdlib.h>
#include<stdio.h>
#include <string.h>

struct Info{
	int data;
	char nome[40];
};

typedef struct Info Info;

struct Cadastro {
	Info dado;
	struct Cadastro* esquerda;
	struct Cadastro* direita;
};

typedef struct Cadastro Cad;

int menu();
void Inserir(Cad** Elemento,int num, char* nome);
Cad* Buscar(Cad** Elemento, int num);
void Consultar_EmOrdem(Cad* Elemento);

int main() {
	int op, num, c;
	char nome_cad[40];
	Cad* root;
	root = (Cad*)malloc(sizeof(Cad));
	root = NULL;

	Cad* ElementoBusca;
	ElementoBusca = (Cad*)malloc(sizeof(Cad));

	while (1) {
		op = menu();
		switch (op) {
		case 1:

			printf("Digite o Nome do Cadastro: ");
			scanf_s("%39s", &nome_cad, sizeof(nome_cad));
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o Ano de Nascimento: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			
			Inserir(&root, num, nome_cad);
			break;
		case 2:
			printf("Digite o Nome da busca: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			ElementoBusca = Buscar(&root, num);
			if (ElementoBusca != 0)
				printf("Valor localizado.\n");
			else
				printf("Valor nao encontrado na arvore.\n");
			system("pause");
			break;
		case 3:
			printf("\n\n");
			Consultar_EmOrdem(root);
			printf("\n\n");
			system("pause");
			break;
		case 4:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls");

	printf("1.Inserir Nome e Ano de Nascimento\n");
	printf("2.Buscar Dados Cadatrados\n");
	printf("3.Consultar Dados Cadastrados\n");
	printf("4.Sair\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("Cls");
	return op;
}

void Inserir(Cad** Elemento, int num, char* nome) {

	if (*Elemento == NULL)
	{ //SE ESTÁ VAZIO, COLOCA NA ÁRVORE
		Cad* NovoElemento = NULL;
		NovoElemento = (Cad*)malloc(sizeof(Cad));
		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;

		NovoElemento->dado.data = num;
		strcpy_s(NovoElemento->dado.nome, nome);
		*Elemento = NovoElemento;
		return;
	}

	if (num < (*Elemento)->dado.data)
	{
		Inserir(&(*Elemento)->esquerda, num, nome);
	}
	else
	{
		if (num > (*Elemento)->dado.data)
		{
			Inserir(&(*Elemento)->direita, num, nome);
		}
	}
}

Cad* Buscar(Cad** Elemento, int num)
{
	if (*Elemento == NULL)
		return NULL;

	if (num < (*Elemento)->dado.data)
	{
		Buscar(&((*Elemento)->esquerda), num);
	}
	else
	{
		if (num > (*Elemento)->dado.data)
		{
			Buscar(&((*Elemento)->direita), num);
		}
		else
		{
			if (num == (*Elemento)->dado.data)
				return *Elemento;
		}
	}
}

void Consultar_EmOrdem(Cad* Elemento)
{
	if (Elemento)
	{
		Consultar_EmOrdem(Elemento->esquerda);
		printf("%s\n", Elemento->dado.nome);
		printf("%d\t", Elemento->dado.data);
		Consultar_EmOrdem(Elemento->direita);
	}
}