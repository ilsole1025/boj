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
//	printf("dfs ��:x:%d, y:%d\n", x, y);
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

	// �Է¹ޱ�
	cin >> n>>m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> be[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> af[i][j];

	// �ٸ� �κ� üũ�ؼ�
	// �ٸ� �κ��� �ϳ��� �̾����ִ���(������������) Ȯ���ϱ�
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			diff[i][j] = false; //�ʱ�ȭ

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (be[i][j] != af[i][j])
				diff[i][j] = true;
		}
	}

	int num = 0; // ������ ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (diff[i][j] && visited[i][j] == 0) {
				dfs(i, j);
				num++;
			}
		}
	}



	if (num == 0) { //���� �ٸ��� ���� ��� ����
		cout << "YES";
		return 0;
	}
	else if (num >= 2) { //������ 2���̻� ���������ִٸ� ���������
		cout << "NO";
		return 0;
	}

	bool ans = true;
	// �������� diff�� üũ�Ǿ��ִ� ������
	// ó��(be)�� �ش� ��ġ ������ ��ġ�ϴ��� üũ
	/* �������� diff�� �ִ� be[i][j]���ڸ� ������
before���¿��� dfs�� ������ �����Ѱ� ��� final�� üũ
�׷��� �ؼ� diff�� 1�� ������ final�� �ִ� ���ڰ� ��� �����Ѱ�?*/

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
	// final�� �ִ� ���ڴ� ��� ���ƾ� ��
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
	// bef�Ӹ� �ƴ϶� after���� ���ƾ� �Ѵ�
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
	// final�� 0�� �ƴ� ĭ���� after���� ��� ���ƾ� ��
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