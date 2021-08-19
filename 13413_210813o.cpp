#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;
void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	string x, y; cin >> x >> y;
	
	// �ٲ�� �ϴ� B�� W ���� ����
	// c1= 0B->W�� ���� c2 = W->B�� ���� ����
	// c1,c2�� �� ���� ����ŭ ans������Ű��, �ش����ŭ �ٲ۴�
	// ��������ŭ ������Ų��

	int c1=0, c2=0;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'B' && y[i] == 'W') c1++;
		if (x[i] == 'W' && y[i] == 'B') c2++;
	}
	int ans = 0;
	if (c1 > c2) {
		ans += c2;
		ans += (c1 - c2);
	}
	else {
		ans += c1;
		ans += (c2 - c1);
	}
	cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}