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
	
	// 바꿔야 하는 B와 W 값을 센다
	// c1= 0B->W인 값과 c2 = W->B인 값을 센다
	// c1,c2중 더 작은 값만큼 ans증가시키고, 해당수만큼 바꾼다
	// 남은수만큼 증가시킨다

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