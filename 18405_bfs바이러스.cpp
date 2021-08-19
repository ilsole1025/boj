#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[200][200];
int n, k, s, X, Y;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
struct virus {
	int x, y, level;
};
bool cmp(const virus& v1, const virus& v2) { return v1.level < v2.level; }
vector<virus> v;

void test() {
	printf("-------------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("-------------\n");
}

void bfs() {
	vector<virus>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		int x = (*iter).x;
		int y = (*iter).y;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
	//		printf("nx,ny:%d,%d \n", nx, ny);
			if (nx < 0 || nx >= n|| ny < 0 || ny >= n) continue;
			if (a[nx][ny] != 0) continue;
			// 이미 바이러스가 있는 경우 패스함
	//		printf("아래 nx,ny:%d,%d \n", nx, ny);
			a[nx][ny] = (*iter).level; //바이러스번호(레벨)
			if (a[X-1][Y-1] != 0)break;
		}
	//	printf("x,y:%d,%d ", x, y);
	//	test();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cin >> s >> X >> Y;
	// -------------------------------
	for (int sec = 1; sec <= s; sec++) {
		sort(v.begin(), v.end(), cmp);
		v.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 0) {
					v.push_back({ i,j,a[i][j] });
				}
			}
		}
		
		bfs();
		//printf("sec:%d ", sec);
		//test();

		if (a[X-1][Y-1] != 0)break;
	}
	

	cout << a[X-1][Y-1];

	return 0;
}