#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100	//Quantidade de caracteres a serem lidos 

void topologicalSorting(int** graph, int size) {	//Ordenação topologica
	int* indegree, * flag, counter = 0;

	indegree = (int*)calloc(size, sizeof(int));
	flag = (int*)calloc(size, sizeof(int));
	if (!flag || !indegree) {
		printf("\n\tErro na alocacao");
		return;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			indegree[i] += graph[j][i];
		}
	}
	printf("\n\tOrdenacao topologica: ");
	while (counter < size) {
		for (int i = 0; i < size; i++) {
			if ((indegree[i] == 0) && (flag[i] == 0)) {
				printf("%d ", (i + 1));
				flag[i] = 1;
				for (int j = 0; j < size; j++) {
					if (graph[i][j] == 1) {
						graph[i][j] = 0;
						indegree[j]--;
					}
				}
			}
		}
		counter++;
	}
	free(indegree);
	free(flag);
}

void proposedProblem() {    //Chamada da ordenação do problema apresentado
	int** graph;

	graph = (int**)calloc(44, sizeof(int*));
	if (!graph) {
		printf("\n\tErro na alocacao");
		return;
	}
	for (int i = 0; i < 44; i++) {
		graph[i] = (int*)calloc(44, sizeof(int));
	}
	if (!graph) {
		printf("\n\tErro na alocacao");
		return;
	}
	graph[2][3] = graph[3][4] = graph[4][5] = graph[4][6] = graph[6][7] = graph[7][8] = graph[8][9] = graph[8][12] = graph[9][10] = graph[10][14] = graph[12][13] =
		graph[13][14] = graph[14][15] = graph[15][16] = graph[15][22] = graph[16][17] = graph[17][18] = graph[18][19] = graph[22][23] = graph[23][24] = graph[24][25] =
		graph[25][26] = graph[25][32] = graph[26][27] = graph[27][28] = graph[28][29] = graph[32][33] = graph[32][34] = graph[33][36] = graph[36][37] = graph[37][38] =
		graph[38][39] = graph[39][40] = graph[40][41] = graph[41][42] = graph[42][43] = 1;
	topologicalSorting(graph, 44);
	free(graph);
}

void newGraph() {	//Chamada da ordenação de um novo grafo
	int** graph;
	int size;
	char input[MAX];

	do {
		printf("\n\tDigite a quantidade de vertices: ");
		fgets(input, sizeof(input), stdin);
		size = strtol(input, NULL, 0);
		if (size < 0) {
			printf("\n\tQuantidade invalida.\n\t");
		}
	} while (size < 0);
	graph = (int**)calloc(size, sizeof(int*));
	if (!graph) {
		printf("\n\tErro na alocacao");
		return;
	}
	for (int i = 0; i < size; i++) {
		graph[i] = (int*)calloc(size, sizeof(int));
	}
	if (!graph) {
		printf("\n\tErro na alocacao");
		return;
	}
	printf("\n\tEntrada da matriz adjacente.\n\tUtilize espaco para separar os numeros de uma linha (0 1 0 1)\n\n");
	for (int i = 0; i < size; i++) {
		printf("\tDigite a linha %d: ", i + 1);
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';
		char* p = input;
		int j = 0;
		while ((*p) && (j < size)) {
			graph[i][j] = strtol(p, &p, 0);
			j++;
		}
	}
	topologicalSorting(graph, size);
	free(graph);
}

int menu() {	//Menu com seletor
	int selector;
	char input[MAX];

	do {
		system("cls");
		printf("\n\t\332\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\277");
		printf("\n\t\263\tDigite um numero de 1 a 3 para escolher a opcao desejada:\t\263\n");
		printf("\t\303\304\304\304\302\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\264");
		printf("\n\t\263 1 \263 Ordenacao topologica do problema apresentado\t\t\t\263");
		printf("\n\t\263 2 \263 Ordenacao topologica de um novo grafo aciclico dirigido (DAG)\t\263");
		printf("\n\t\263 3 \263 Sair do sistema\t\t\t\t\t\t\t\263\n");
		printf("\t\300\304\304\304\301\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\331\n\n\t");
		fgets(input, sizeof(input), stdin);
		selector = strtol(input, NULL, 0);
		if (selector < 1 || selector>3) {
			printf("\n\tOpcao invalida.\n\t");
			system("pause");
		}
	} while (selector < 1 || selector>3);

	return selector;
}


int main() {
	int selector;

	for (;;) {
		selector = menu();
		switch (selector) {
			case 1:	system("cls");
				proposedProblem();
				printf("\n\t");
				system("pause");
				break;
			case 2:system("cls");
				newGraph();
				printf("\n\t");
				system("pause");
				break;
			case 3:
				exit(0);
		}
	}

	return 0;
}
