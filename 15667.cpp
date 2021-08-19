#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int sum = 0;
	int k = 0;
	while (sum != N) k++, sum = 1 + k + k * k;
	cout << k;
	return 0;
}