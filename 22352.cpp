#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int visited[35][35] = { 0, };
int n, m;
int be[35][35];//before
int af[35][35];//after
bool diff[35][35];
int final[35][35] = { 0, };
int final_visited[35][35] = { 0, };

void dfs(int x, int y) {
//	printf("dfs 안:x:%d, y:%d\n", x, y);
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || nx >= n || ny >= m)
			continue;

		if (diff[nx][ny] && visited[nx][ny] == 0) {
		//	printf("nx:%d,ny:%d\n", nx, ny);
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}
void dfs_final(int x, int y) {
	final_visited[x][y] = 1;
	final[x][y] = be[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || nx >= n || ny >= m)
			continue;

		if (be[x][y] == be[nx][ny] && final_visited[nx][ny] == 0) {
			//	printf("nx:%d,ny:%d\n", nx, ny);
			final[nx][ny] = be[nx][ny];
			final_visited[nx][ny] = 1;
			dfs_final(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력받기
	cin >> n>>m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> be[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> af[i][j];

	// 다른 부분 체크해서
	// 다른 부분이 하나로 이어져있는지(같은구역인지) 확인하기
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			diff[i][j] = false; //초기화

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (be[i][j] != af[i][j])
				diff[i][j] = true;
		}
	}

	int num = 0; // 구역의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (diff[i][j] && visited[i][j] == 0) {
				dfs(i, j);
				num++;
			}
		}
	}



	if (num == 0) { //모든게 다른거 없이 모두 같다
		cout << "YES";
		return 0;
	}
	else if (num >= 2) { //구역이 2개이상 나뉘어져있다면 만들수없음
		cout << "NO";
		return 0;
	}

	bool ans = true;
	// 마지막에 diff가 체크되어있는 구역과
	// 처음(be)의 해당 위치 구역이 일치하는지 체크
	/* 마지막에 diff에 있는 be[i][j]숫자를 가지고
before상태에서 dfs를 돌려서 인접한거 모두 final에 체크
그렇게 해서 diff에 1이 있을때 final에 있는 숫자가 모두 동일한가?*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (diff[i][j]) {
				if (final_visited[i][j] == 0) {
					dfs_final(i, j);
				}
			}
		}
	}

	int check = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (final[i][j] != 0) {
				check = final[i][j];
				break;
			}
		}
		if (check != 0) break;
	}
	// final에 있는 숫자는 모두 같아야 함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (final[i][j] != 0) {
				if (final[i][j] != check) {
					ans = false;
					break;
				}
			}
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (diff[i][j]==false) {
				if (final[i][j] != 0) {
					ans = false;
					break;
				}
			}
		}
	}
	// bef뿐만 아니라 after값도 같아야 한다
	check = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (final[i][j] != 0) {
				check = af[i][j];
				break;
			}
		}
		if (check != 0) break;
	}
	// final이 0이 아닌 칸에서 after값은 모두 같아야 함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (final[i][j] != 0) {
				if (af[i][j] != check) {
					ans = false;
					break;
				}
			}
		}

	}


	
	if (ans==true) cout << "YES";
	else cout << "NO";

	/*
	printf("\nbefore-----------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", be[i][j]);
		}
		printf("\n");
	}

	printf("\nvisited-----------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	printf("\nfinal visited-----------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", final_visited[i][j]);
		}
		printf("\n");
	}
	printf("diff-----------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", diff[i][j]);
		}
		printf("\n");
	}
	printf("final-----------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", final[i][j]);
		}
		printf("\n");
	}
	*/
	
	return 0;
}