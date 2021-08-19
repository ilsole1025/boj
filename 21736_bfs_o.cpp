#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<math.h>
#include <iomanip>
using namespace std;

int n, m;
char map[601][601];
bool check[601][601];
queue<pair<int, int>>q;
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
int ans = 0;
void bfs(int x, int y) {
	// q.push({ x,y });
	
		check[y][x] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) 
				continue;
			if (check[ny][nx]) continue;
			if (map[ny][nx] =='X') continue;

			if (map[ny][nx] == 'P') ans++;
			check[ny][nx] = true;
			
			bfs(nx, ny);
		}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				a = i; b = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = false;
		}
	}
	
	bfs(b,a);
	if(ans!=0) cout << ans;
	else cout << "TT";

	return 0;
}