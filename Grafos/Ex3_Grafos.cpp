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

struct Lista
{
	char nome_city1[20] = "CastleBlock";
	char nome_city2[20] = "Karhold";
	char nome_city3[20] = "Winterfell";
	char nome_city4[20] = "The Stony Shore";
	char nome_city5[20] = "White Harbor";
	char nome_city6[20] = "Window's Watch";
	char nome_city7[20] = "Moat Cailin";
	char nome_city8[20] = "Greywater Watch";
	char nome_city9[20] = "Segard";
	char nome_city10[20] = "Funt's Finger";
	char nome_city11[20] = "The Twins";
	char nome_city12[20] = "Pyke";
	char nome_city13[20] = "The Finger's";
	char nome_city14[30] = "The Montains of the Moon";
	char nome_city15[20] = "The Erye";
	char nome_city16[20] = "Riverrun";
	char nome_city17[20] = "Clackclaw Point";
	char nome_city18[20] = "Dragonstone";
	char nome_city19[20] = "Harrenhal";
	char nome_city20[20] = "Lannisport";
	char nome_city21[20] = "Blackwater";
	char nome_city22[20] = "Stoney Sept";
	char nome_city23[20] = "King's Landing";
	char nome_city24[20] = "Searoad Marches";
	char nome_city25[20] = "The Reach";
	char nome_city26[20] = "Kingwood";
	char nome_city27[20] = "Highgarden";
	char nome_city28[20] = "The Boneway";
	char nome_city29[20] = "Dornish Marches";
	char nome_city30[20] = "Storms End";
	char nome_city31[20] = "Oldtown";
	char nome_city32[20] = "Prince's Pass";
	char nome_city33[20] = "Yronwood";
	char nome_city34[20] = "Three Towers";
	char nome_city35[20] = "Starfall";
	char nome_city36[20] = "Salt Shore";
	char nome_city37[20] = "Sunspear";
	char nome_city38[20] = "The Arbor";
};

typedef struct Lista* Lista;

struct Cidades
{
	int vertice;
	Cidades* prox;
};

struct Grafo
{
	int TotalVertices;
	struct Cidades** ListaAdj; //Ser� um ponteiro para um vetor do tamanho do numero de v�rtices
									   //alocado dinamicamente, por isso o **
};

struct Grafo* CriarGrafo(char* vertices);
void AdicionarAresta(struct Grafo* Grafo, int origem, int destino);
void MostrarGrafo(struct Grafo* Grafo);

int main()
{
	char nome_city36[20] = "Salt Shore";
	char nome_city37[20] = "Sunspear";
	char nome_city38[20] = "The Arbor";

	Grafo* GrafoTeste = CriarGrafo(3);
	AdicionarAresta(GrafoTeste, 0, 1);
	AdicionarAresta(GrafoTeste, 0, 2);
	AdicionarAresta(GrafoTeste, 1, 3);
	//AdicionarAresta(GrafoTeste, 2, 3);
	//AdicionarAresta(GrafoTeste, 3, 4);
	//AdicionarAresta(GrafoTeste, 3, 5);
	//AdicionarAresta(GrafoTeste, 4, 6);

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

void AdicionarAresta(struct Grafo* Grafo, int origem, int destino)
{ //INSER��O NO INICIO DA LISTA 
  // Adiciona uma aresta da origem para o  destino
	struct Cidades* NovoElemento = (struct Cidades*)malloc(sizeof(struct Cidades));
	NovoElemento->vertice = destino;
	NovoElemento->prox = NULL;

	NovoElemento->prox = Grafo->ListaAdj[origem];
	Grafo->ListaAdj[origem] = NovoElemento;

	// Adiciona uma aresta do destino para a origem
	NovoElemento = (struct Cidades*)malloc(sizeof(struct Cidades));
	NovoElemento->vertice = origem;
	NovoElemento->prox = NULL;

	NovoElemento->prox = Grafo->ListaAdj[destino];
	Grafo->ListaAdj[destino] = NovoElemento;
}

void MostrarGrafo(struct Grafo* Grafo)
{
	int v;
	for (v = 0; v < Grafo->TotalVertices; v++)
	{
		struct Cidades* ElementoVarredura = Grafo->ListaAdj[v];
		printf("\n Lista de adjacencias do vertice %d:\n ", v);
		while (ElementoVarredura != NULL)
		{
			printf("%d -> ", ElementoVarredura->vertice);
			ElementoVarredura = ElementoVarredura->prox;

		}
		printf("\n");
	}
}
//ListaAdj.txt
//Exibindo ListaAdj.txt.