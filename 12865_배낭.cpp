#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int wei[100 + 5] = { 0, };
int val[100 + 5] = { 0, };
int N, K;
int dp[100+5][100000+5]; //dp[i,w]

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> wei[i] >> val[i];
	

	// i�� 0�� ���: ���� ������ ���� ��
	for (int w = 0; w <= K; w++) dp[0][w] = 0;
	// w�� 0�� ���: ���� �賶�� ���� ��
	for (int i = 0; i <= N;i++) dp[i][0] = 0;


	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= K; w++) {
			if (wei[i] <= w) {// i��° ������ ������
				dp[i][w] = max(val[i] + dp[i - 1][w - wei[i]], dp[i - 1][w]);
			}
			else { // i��° ������ ���� ������
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	cout << dp[N][K];

	// �����ڷ� https://gsmesie692.tistory.com/113

	return 0;
}