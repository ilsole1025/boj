#define MOD 1000000007
#include<iostream>
#include<vector>
using namespace std;

int n, m;
long long dp[1002][1002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	dp[1][1] = 1;
	for (int i = 2; i <= 1000; i++) dp[i][1] = 1;
	for (int i = 2; i <= 1000; i++) dp[1][i] = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j <= 1000; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	cout << dp[n][m];

	return 0;
}