#include<iostream>
using namespace std;

// c++에서는 long long 범위를 초과함
// 빡쳐서 걍 파이썬으로 풀엇음

int main(void) {
	unsigned long long n, m;
	cin >> n >> m;
	unsigned long long arr[101][101] = {};
	arr[1][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i <= 100; i++) {
		arr[i][0] = 1;
		for (int j = 1; j <= 100; j++) {
			if (i == j) arr[i][j] = 1;
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cout << arr[n][m];

	return 0;
}