#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <time.h>
#include<vector>
#include <locale.h>
using namespace std;
vector<int> adjList[100];
vector<int> adjList2[100];
int main(void) {
	setlocale(LC_ALL, "Rus");
	int** a;
	int** c;
	int** G;

	int N, u, u0, v, k;
	printf("������� N: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	c = (int**)malloc(N * sizeof(int));
	G = (int**)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* b = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			b[j] = 0;
		}
		a[i] = b;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 2;
				a[i][j] = num;
				a[j][i] = num;
			}
		}
	}
	printf("����������������� ���� 1");
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (a[i][j] == 1) {
					adjList[i].push_back(j);
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << i << " -->";
		for (int j = 0; j < adjList[i].size(); j++)
		{
			cout << adjList[i][j] << " ";
		}
		cout << endl;
	}
	
	printf("�������� ��������: 1- �������������� 2- ���������� 3-����������� 4-����������� 5- ����������� 6- ��������� ����� ");
	printf("\n");
	scanf("%d", &k);
	if (k == 1) {
		printf("��������������:");
		printf("\n");
		printf("������� ������� u � v ��� ��������������:");
		printf("\n");
		scanf("%d", &u);
		scanf("%d", &v);
		for (int i = 0; i < N; i++) {
			if (i == u) {
				printf("%d%d |", u, v);
			}
			else if (i != v) {
				printf("%d  |", i);
			}

			for (int j = 0; j < N; j++) {

				if (a[u][j] == 1 | a[v][j] == 1) {
					a[u][j] = 1;
					a[v][j] = 1;
				}
				else {
					a[u][j] = 0;
					a[v][j] = 0;
				}
				if (a[i][u] == 1 | a[i][v] == 1) {
					a[i][u] = 1;
					a[i][v] = 1;
				}
				else {
					a[i][u] = 0;
					a[i][v] = 0;
				}
				a[u][u] = 1;
				if ((i != v) && (j != v)) {
					printf("%d ", a[i][j]);
				}

			}
			if (i != v) {
				printf("\n");
			}
		}
	}
	if (k == 2) {
		printf("����������:");
		printf("\n");
		printf("������� ������� u � v ��� ����������:");
		printf("\n");
		scanf("%d", &u);
		scanf("%d", &v);
		if (a[u][v] == 1) {
			for (int i = 0; i < N; i++) {
				if (i == u) {
					printf("%d%d |", u, v);
				}
				else if (i != v) {
					printf("%d  |", i);
				}

				for (int j = 0; j < N; j++) {
					if (a[u][j] == 1 | a[v][j] == 1) {
						a[u][j] = 1;
						a[v][j] = 1;
					}
					else {
						a[u][j] = 0;
						a[v][j] = 0;
					}
					if (a[i][u] == 1 | a[i][v] == 1) {
						a[i][u] = 1;
						a[i][v] = 1;
					}
					else {
						a[i][u] = 0;
						a[i][v] = 0;
					}
					a[u][u] = 0;
					if ((i != v) && (j != v)) {
						printf("%d ", a[i][j]);
					}
				}
				if (i != v) {
					printf("\n");
				}

			}
		}
		else printf("������� �� ������");
	}
	if (k == 3) {
		printf("�����������");
		printf("\n");
		printf("������� ������� ��� �����������");
		scanf("%d", &u0);
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < N + 1; j++) {
				// ��������
				printf("\n");
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int* d = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			d[j] = 0;
		}
		c[i] = d;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 2;
				c[i][j] = num;
				c[j][i] = num;
			}
		}
	}
	if (k == 4) {
		printf("����������������� ���� 2");
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < N; i++) {
			int* f = (int*)malloc(N * sizeof(int));
			for (int j = 0; j < N; j++) {
				f[j] = 0;
			}
			G[i] = f;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j) {
					if (c[i][j] == 1) {
						adjList2[i].push_back(j);
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			cout << i << " -->";
			for (int j = 0; j < adjList2[i].size(); j++)
			{
				cout << adjList2[i][j] << " ";
			}
			cout << endl;
		}
		printf("\n");
		printf("��������� ����������� ����� 1 � ����� 2:");
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (a[i][j] == 0 && c[i][j] == 0) {
					G[i][j] = 0;
				}
				if (a[i][j] == 1 && c[i][j] == 0) {
					G[i][j] = 1;
				}
				if (a[i][j] == 0 && c[i][j] == 1) {
					G[i][j] = 1;
				}
				if (a[i][j] == 1 && c[i][j] == 1) {
					G[i][j] = 1;
				}
				printf("%d ", G[i][j]);
			}
			printf("\n");
		}

	}
	if (k == 5) {
		printf("�����������");
		printf("����������������� ���� 2");
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < N; i++) {
			int* f = (int*)malloc(N * sizeof(int));
			for (int j = 0; j < N; j++) {
				f[j] = 0;
			}
			G[i] = f;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j) {
					if (c[i][j] == 1) {
						adjList2[i].push_back(j);
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			cout << i << " -->";
			for (int j = 0; j < adjList2[i].size(); j++)
			{
				cout << adjList2[i][j] << " ";
			}
			cout << endl;
		}
		printf("\n");
		printf("��������� ����������� ����� 1 � ����� 2:");
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i][j] == 0 && c[i][j] == 0) {
					G[i][j] = 0;
				}
				if (a[i][j] == 1 && c[i][j] == 0) {
					G[i][j] = 0;
				}
				if (a[i][j] == 0 && c[i][j] == 1) {
					G[i][j] = 0;
				}
				if (a[i][j] == 1 && c[i][j] == 1) {
					G[i][j] = 1;
				}
				printf("%d ", G[i][j]);
			}
			printf("\n");
		}

	}
	if (k == 6) {
		printf("��������� �����");
		printf("����������������� ���� 2");
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < N; i++) {
			int* f = (int*)malloc(N * sizeof(int));
			for (int j = 0; j < N; j++) {
				f[j] = 0;
			}
			G[i] = f;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j) {
					if (c[i][j] == 1) {
						adjList2[i].push_back(j);
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			cout << i << " -->";
			for (int j = 0; j < adjList2[i].size(); j++)
			{
				cout << adjList2[i][j] << " ";
			}
			cout << endl;
		}
		printf("\n");
		printf("��������� ��������� �����:");
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i][j] == 0 && c[i][j] == 0) {
					G[i][j] = 0;
				}
				if (a[i][j] == 1 && c[i][j] == 0) {
					G[i][j] = 1;
				}
				if (a[i][j] == 0 && c[i][j] == 1) {
					G[i][j] = 1;
				}
				if (a[i][j] == 1 && c[i][j] == 1) {
					G[i][j] = 0;
				}
				printf("%d ", G[i][j]);
			}
			printf("\n");
		}

	}
}


