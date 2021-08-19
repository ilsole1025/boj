#define MAX 500000

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

vector<int> tree[MAX + 1];
int check[MAX + 1];
int ans;

void dfs(int start, int depth) {

	if (start != 1 && tree[start].size() == 1) {
		// ��������϶�
		if (depth % 2 == 1) ans++; //��������� depth�� Ȧ��
		return;
	}
	int size = tree[start].size();
	for (int i = 0; i < size; i++) {
		if (check[start] == 0) {
			check[start] = 1; //üũ
			dfs(tree[start][i], depth + 1);
			check[start] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N,a,b;
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 0); //start�� �θ� ��忡��, depth�� ������ 0

	if (ans % 2 == 0) //¦��
		cout << "No"; 
	else cout << "Yes";

	// ������ ���� ¦���� ������ �й�
	// ������ ���� Ȧ���� ������ �¸�

	return 0;
}