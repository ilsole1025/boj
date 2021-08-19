#define MAX 328000
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<math.h>
#include <iomanip>
using namespace std;

int N, S, P;
vector<int> v[MAX + 1];
queue<pair<int, int>> q;
bool check[MAX + 1];
int ans_cnt = 0;
int ans;

void bfs(int n, int cur) {
	q.push({ n, cur });
	check[cur] = true; //방문 체크

	while (!q.empty()) {
		int now_num = q.front().first;
		int now_cur = q.front().second;
		q.pop();

		if (now_cur <= S) { // 지지대 얼음
			ans -= now_num;
			ans_cnt++;
			if (ans_cnt == 2) return;
		}
		
		for (auto a : v[now_cur]) {
			if (check[a] == true) continue;
			else {
				check[a] = true;
				q.push({ now_num + 1, a });
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> P;
	int x, y;
	for(int i=0; i<N-1; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < N - 1; i++) {
	//	check[i] = false; //초기화
	}

	ans = N - 1; //초기값

	bfs(0, P);

	cout << ans;

	return 0;
}