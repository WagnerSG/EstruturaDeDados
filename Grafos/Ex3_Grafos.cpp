/*Estrutura de Dados Semipresencial
Semana 5 - Exerc�cio
Vinicius Pozzobon Borin
�
19:45 Editado �s 19 : 58
100 pontos
Data de entrega : 30 de mar. 23 : 59
Este exerc�cio comp�e a nota da Atividade Pr�tica de voc�s(25 %).

Utilizando o MAPA DE WESTEROS do jogo de tabuleiro do Game of Thrones, implemente o mapa de Westeros em um grafo utilizando lista de adjac�ncias.Na tela deve - se listar, para uma regi�o selecionada, a lista de regi�es vizinhas a mesma.
Sempre que houver um rio / mar n�o deve existir conex�o entre as regi�es, ao menos que exista uma ponte.

Altere a estrutura do grafo para aceitar os nomes das regi�es nos v�rtices.Ao mostrar o grafo, fa�a a impress�o na tela dos nomes das regi�es ao inv�s dos n�meros dos v�rtices.

mapa_westeros.png
Imagem

ListaAdj.txt
Texto
Coment�rios da turma
Seus trabalhos
Atribu�do
Coment�rios particulares*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Cidades
{
	int vertice;
	char nome[30];
	Cidades* prox;
	
};

struct Grafo
{
	int TotalVertices;
	char nome[30];
	struct Cidades** ListaAdj; //Ser� um ponteiro para um vetor do tamanho do numero de v�rtices
									   //alocado dinamicamente, por isso o **
};

struct Grafo* CriarGrafo(char* vertices);
void AdicionarAresta(struct Grafo* Grafo, int origem, char city1[], int destino, char city[]);
void MostrarGrafo(struct Grafo* Grafo);

int main()
{
	
	Grafo* GrafoTeste = CriarGrafo(34);

	AdicionarAresta(GrafoTeste, 0, (char*)"Castle_Black", 1, (char*)"Karhold");
	AdicionarAresta(GrafoTeste, 0, (char*)"Castle_Black", 2, (char*)"Winterfell");
	AdicionarAresta(GrafoTeste, 2, (char*)"Winterfell", 3, (char*)"The Stony Shore");
	AdicionarAresta(GrafoTeste, 2, (char*)"Winterfell", 4, (char*)"White Harbor");
	AdicionarAresta(GrafoTeste, 2, (char*)"Winterfell", 8, (char*)"Moat Calin");
	AdicionarAresta(GrafoTeste, 4, (char*)"White Harbor", 5, (char*)"Widows Watch");
	AdicionarAresta(GrafoTeste, 8, (char*)"Moat Calin", 6, (char*)"Greywater Watch");
	AdicionarAresta(GrafoTeste, 8, (char*)"Moat Calin", 9, (char*)"Seagard");
	AdicionarAresta(GrafoTeste, 8, (char*)"Moat Calin", 10, (char*)"The Twins");
	AdicionarAresta(GrafoTeste, 6, (char*)"Greywater Watch", 7, (char*)"Funts Finger");
	AdicionarAresta(GrafoTeste, 6, (char*)"Greywater Watch", 9, (char*)"Seagard");
	AdicionarAresta(GrafoTeste, 9, (char*)"Seagard", 10, (char*)"The Twins");
	AdicionarAresta(GrafoTeste, 10, (char*)"The Twins", 11, (char*)"The Fingers");
	AdicionarAresta(GrafoTeste, 10, (char*)"The Twins", 12, (char*)"The Mountains of the Moon");
	AdicionarAresta(GrafoTeste, 11, (char*)"The Fingers", 12, (char*)"The Mountains of the Moon");
	AdicionarAresta(GrafoTeste, 12, (char*)"The Mountains of the Moon", 13, (char*)"The Eyrie1");
	AdicionarAresta(GrafoTeste, 12, (char*)"The Mountains of the Moon", 18, (char*)"Crackclaw Point");
	AdicionarAresta(GrafoTeste, 18, (char*)"Crackclaw Point", 14, (char*)"Harrenhal");
	AdicionarAresta(GrafoTeste, 14, (char*)"Harrenhal", 15, (char*)"Riverrun");
	AdicionarAresta(GrafoTeste, 15, (char*)"Riverrun", 17, (char*)"Stoney Sept");
	AdicionarAresta(GrafoTeste, 15, (char*)"Riverrun", 16, (char*)"Lannisport");
	AdicionarAresta(GrafoTeste, 16, (char*)"Lannisport", 17, (char*)"Stoney Sept");
	AdicionarAresta(GrafoTeste, 14, (char*)"Harrenhal", 17, (char*)"Stoney Sept");
	AdicionarAresta(GrafoTeste, 14, (char*)"Harrenhal", 20, (char*)"Black Water");
	AdicionarAresta(GrafoTeste, 14, (char*)"Harrenhal", 18, (char*)"Crackclaw Point");
	AdicionarAresta(GrafoTeste, 17, (char*)"Stoney Sept", 21, (char*)"Searoad Marches");
	AdicionarAresta(GrafoTeste, 17, (char*)"Stoney Sept", 20, (char*)"Black Water");
	AdicionarAresta(GrafoTeste, 18, (char*)"Crackclaw Point", 20, (char*)"Black Water");
	AdicionarAresta(GrafoTeste, 18, (char*)"Crackclaw Point", 19, (char*)"Kings Landing");
	AdicionarAresta(GrafoTeste, 20, (char*)"Black Water", 21, (char*)"Searoad Marches");
	AdicionarAresta(GrafoTeste, 20, (char*)"Black Water", 23, (char*)"The Reach");
	AdicionarAresta(GrafoTeste, 19, (char*)"Kings Landing", 23, (char*)"The Reach");
	AdicionarAresta(GrafoTeste, 19, (char*)"Kings Landing", 22, (char*)"Kings Wood");
	AdicionarAresta(GrafoTeste, 21, (char*)"Searoad Marches", 24, (char*)"High Garden");
	AdicionarAresta(GrafoTeste, 24, (char*)"High Garden", 23, (char*)"The Reach");
	AdicionarAresta(GrafoTeste, 24, (char*)"High Garden", 29, (char*)"Oldtown");
	AdicionarAresta(GrafoTeste, 24, (char*)"High Garden", 25, (char*)"Dornish Marches");
	AdicionarAresta(GrafoTeste, 23, (char*)"The Reach", 25, (char*)"Dornish Marches");
	AdicionarAresta(GrafoTeste, 23, (char*)"The Reach", 26, (char*)"The Boneway");
	AdicionarAresta(GrafoTeste, 22, (char*)"Kings Wood", 27, (char*)"Storms End");
	AdicionarAresta(GrafoTeste, 22, (char*)"Kings Wood", 26, (char*)"The Boneway");
	AdicionarAresta(GrafoTeste, 22, (char*)"Kings Wood", 23, (char*)"The Reach");
	AdicionarAresta(GrafoTeste, 25, (char*)"Dornish Marches", 29, (char*)"Oldtown");
	AdicionarAresta(GrafoTeste, 25, (char*)"Dornish Marches", 28, (char*)"Prince Pass");
	AdicionarAresta(GrafoTeste, 25, (char*)"Dornish Marches", 30, (char*)"The Boneway");
	AdicionarAresta(GrafoTeste, 29, (char*)"Oldtown", 30, (char*)"Three Towers");
	AdicionarAresta(GrafoTeste, 27, (char*)"Storms End", 26, (char*)"The Boneway");
	AdicionarAresta(GrafoTeste, 26, (char*)"The Boneway", 28, (char*)"Prince Pass");
	AdicionarAresta(GrafoTeste, 30, (char*)"Three Towers", 28, (char*)"Prince Pass");
	AdicionarAresta(GrafoTeste, 28, (char*)"Prince Pass", 32, (char*)"Starfall");
	AdicionarAresta(GrafoTeste, 28, (char*)"Prince Pass", 31, (char*)"Yronwood");
	AdicionarAresta(GrafoTeste, 32, (char*)"Starfall", 31, (char*)"Yronwood");
	AdicionarAresta(GrafoTeste, 31, (char*)"Yronwood", 34, (char*)"Sunspear");
	AdicionarAresta(GrafoTeste, 31, (char*)"Yronwood", 33, (char*)"Saltshore");
	AdicionarAresta(GrafoTeste, 33, (char*)"Saltshore", 34, (char*)"Sunspear");

	MostrarGrafo(GrafoTeste);
	system("pause");
	
	return 0;
}

struct Grafo* CriarGrafo(char TotalVertices)
{
	Grafo* Grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
	Grafo->TotalVertices = TotalVertices;
	Grafo->ListaAdj = (struct Cidades**)malloc(TotalVertices * sizeof(struct Cidades*));

	for (int i = 0; i < TotalVertices; i++)
		Grafo->ListaAdj[i] = NULL;

	return Grafo;
}

void AdicionarAresta(struct Grafo* Grafo, int origem, char city1[], int destino, char city[])
{ //INSER��O NO INICIO DA LISTA 
  // Adiciona uma aresta da origem para o  destino
	struct Cidades* NovoElemento = (struct Cidades*)malloc(sizeof(struct Cidades));
	NovoElemento->vertice = destino;
	strcpy(NovoElemento->nome, city);
	NovoElemento->prox = NULL;

	NovoElemento->prox , Grafo->ListaAdj , city1;
	Grafo->ListaAdj , city1, NovoElemento;

	// Adiciona uma aresta do destino para a origem
	NovoElemento = (struct Cidades*)malloc(sizeof(struct Cidades));
	NovoElemento->vertice = origem;
	strcpy(NovoElemento->nome , city1);
	NovoElemento->prox = NULL;

	NovoElemento->prox , Grafo->ListaAdj, city;
	Grafo->ListaAdj, city , NovoElemento;
}

void MostrarGrafo(struct Grafo* Grafo)
{
	int v;
	for (v = 0; v < Grafo->TotalVertices; v++)
	{
		struct Cidades* ElementoVarredura = Grafo->ListaAdj[v];
		printf("\n Lista de adjacencias do vertice %d:\n ", v);
		puts(Grafo->ListaAdj[v]->nome);
		while (ElementoVarredura != NULL)
		{
			printf("%d -> ", ElementoVarredura->vertice);
			printf("%29s ->", ElementoVarredura->nome);
			ElementoVarredura = ElementoVarredura->prox;

		}
		printf("\n");
	}
}
