typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x; cin >> x;
	int order = 0, n=1;
	while (1) {
		order = n * (n + 1) / 2;
		n++;
		if (x <= order) break;
		// 1 3 6 10 15...
	}
	order -= (n-1);

	// x - order��ŭ �� ������ ����� �ϰ� �̰� ����
	// �и� ������ ���� n
	
	if (n % 2 == 0) { //n�� ¦���� �����
		int b = x - order;
		int a = n - b;
		cout << a << "/" << b;
	}
	else { // n�� Ȧ���� ������
		int a = x - order;
		int b = n - a;
		cout << a << "/" << b;
	}
	

	return 0;
}