
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<int> price, p2;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		price.push_back(tmp);
	}

	// �� ������ ���ؼ� �����ʿ� �ִ� ���߿� ���� ��� �������� �ȱ�

	// �����ʿ��� ��..�����鼭 �� ���������� �ִ� ���� ����
	int M[100001];
	int max = price[n-1];
	for (int i = n - 1; i >= 0; i--) {
		if (max < price[i]) max = price[i];
		M[i] = max;
	}
	
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		ans += (M[i] - price[i]);
	}

	cout << ans;

	return 0;
}