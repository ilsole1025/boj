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
	int n, m, k;
	cin >> n >> m >> k;
	int a[101][101];
	int s[101] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	// a[0][0] a[1][0] a[2][0] .. a[n-1][0]
	// a[1][0]... 이 순서대로 감

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			s[i] += a[i][j];
			if (s[i] >= k) {
				// break;
				cout << i + 1 << " " << j + 1;
				return 0;
			}
		}
	}


	return 0;
}