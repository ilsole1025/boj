#include<iostream>
#include<vector>
using namespace std;

long long n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	long long tmp;
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 0) tmp++;
		ans *= tmp;
		ans %= m;
	}

	// n, m�� 0,1�̸� �� 0�̰� 0,(1���� �ٸ� ��) �̸� �� 1�� 

	cout << (ans % m);

	return 0;
}