#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int dp[10002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;

	for (int i = 0; i <= k-1; i++) { // ���� ��
		int a, b; cin >> a >> b;
		for (int j = n; j >= b; j--) { // �ð�(�뷮)
			dp[j] = max(dp[j], dp[j - b] + a);
		}
	}
	
	cout << dp[n];

	return 0;
}