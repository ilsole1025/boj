typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int N, Q;
struct edge {
	int L, R;
};
edge info[305];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int L, R; cin >> L >> R;
		info[i].L = L; info[i].R = R;
	}

	int graph[305][305] = { 0, };
	// 먼저 2중for문 돌면서 각자 친구 관계인지 확인한다
	// 친구라면 graph=1;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			// info[i]와 info[j] 관계로 파악
			bool fri = false;
			if (info[j].L <= info[i].R && info[i].L <= info[j].R) fri = true;
			if (info[i].L < info[j].R && info[j].L <= info[i].R) fri = true;
			if (fri) {
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == k) continue;
				if (graph[j][i] != 0 && graph[i][k] != 0) {
					if (graph[j][k] > graph[j][i] + graph[i][k]) {
						graph[j][k] = graph[j][i] + graph[i][k];
					}
					else if (graph[j][k] == 0) {
						graph[j][k] = graph[j][i] + graph[i][k];
					}
					else;
				}
			}
		}
	}

	cin >> Q;
	while (Q--) {
		int a, b; cin >> a >> b;
		if (graph[a][b] == 0) cout << "-1\n";
		else cout << graph[a][b] << "\n";
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
		//	cout << graph[i][j] << " ";
		}
	//	cout << endl;
	}


	return 0;
}