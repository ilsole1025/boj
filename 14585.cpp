typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

ll candy[302][302];
ll ans[302][302];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		candy[x][y] = m;
	}
	// 좌표가 x,y면 사탕개수 x+y만큼 빼기
	candy[0][0] = 0;
	for (int y = 0; y <= 300; y++) {
		for (int x = 0; x <= 300; x++) {
			if (x == 0 && y == 0) continue;
			else if (x == 0) {
				if (candy[0][y])
					ans[x][y] = ans[x][y - 1] + m - (x + y);
				else ans[x][y] = ans[x][y - 1];
			}
			else if (y == 0) {
				if (candy[x][y])
					ans[x][y] = ans[x - 1][y] + m - (x + y);
				else ans[x][y] = ans[x - 1][y];
			}
			else if (candy[x][y] != 0) {
				// 사탕이 있는 경우
				int plus = candy[x][y] - (x + y);
				if (plus < 0) plus = 0;
				ans[x][y] = max(ans[x][y - 1], ans[x - 1][y]);
				ans[x][y] += plus;
			}
			else {
				// 사탕이 없는 경우
				ans[x][y] = max(ans[x][y - 1], ans[x - 1][y]);
			}
		}
	}

	cout << ans[300][300];

	return 0;
}