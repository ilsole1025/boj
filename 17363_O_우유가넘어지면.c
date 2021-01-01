#include<stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	char a[105][105];
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	/*
	printf("-------------\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	*/
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == 'O') a[i][j] = 'O';
			else if (a[i][j] == '-') a[i][j] = '|' ;
			else if (a[i][j] == '|') a[i][j] = '-' ;
			else if (a[i][j] == '/') a[i][j] = '\\';
			else if (a[i][j] == '\\') a[i][j] = '/';
			else if (a[i][j] == '^') a[i][j] = '<';
			else if (a[i][j] == '<') a[i][j] = 'v';
			else if (a[i][j] == 'v') a[i][j] = '>';
			else if (a[i][j] == '>') a[i][j] = '^';
			else;
		}
	}
	/*
	printf("\n"); printf("==============\n"); printf("\n"); printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}

	printf("\n"); printf("==============\n"); printf("\n");
	*/
	for (j = m-1; j >= 0; j--) {
		for (i = 0; i < n; i++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}