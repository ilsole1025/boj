#include<stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	int solve[15];
	solve[0] = 0;
	solve[1] = 1; solve[2] = 2; solve[3] = 4;

	for (int j = 4; j <= 11; j++) {
		solve[j] = solve[j - 1] + solve[j - 2] + solve[j - 3];
	}

	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		printf("%d\n", solve[n]);
	}

	return 0;
}