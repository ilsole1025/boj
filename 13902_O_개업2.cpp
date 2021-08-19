#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<climits>
using namespace std;
int N, M;
int s[1005];
int dp[10005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> s[i];

	if (M == 1) {
		if (N % s[0] == 0) { // 한개로 요리가능
			cout << N / s[0];
		}
		else cout << "-1";
		return 0;
	}

	sort(s, s + M);
	for (int i = 0; i <= 10000; i++) dp[i] = INT_MAX;
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			// 웍 2개 i,j를 선택함
			int a = s[i]; int b = s[j];
			dp[a] = dp[b] = 1;
			if (a + b <= N) dp[a + b] = 1;
		}
	}
	if (dp[N] != INT_MAX) {
		cout << dp[N]; return 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if (i + j > N) continue;
			if (dp[i] != INT_MAX && dp[j] != INT_MAX)
				dp[i + j] = min(dp[i + j], dp[i] + dp[j]);
		}
	}
	if (dp[N] != INT_MAX) cout << dp[N];
	else cout << "-1";
	return 0;
}