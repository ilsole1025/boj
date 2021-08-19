#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include <iomanip>
using namespace std;

int n, m;
int a[105];
int ans;

void solve(int cur, int size, int time) {
	if (time <= 0 || cur == n ) {
		if (ans < size) ans = size;
		return;
	}

	if (cur + 1 <= n) {
		solve(cur + 1, size + a[cur + 1], time - 1);
	}
	if (cur + 2 <= n) {
		solve(cur + 2, size/2 + a[cur+2], time - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	solve(0, 1, m);
	cout << ans;

	return 0;
}