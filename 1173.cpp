#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int N, m, M, T, R;
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> m >> M >> T >> R;
	
	if (M - m < T) {
		cout << "-1"; return 0;
	}
	
	// �ð��ʰ� ���� ������ -1 ó���� �� ���༭.
	
	int X = m;
	while (N != 0) {
		if (X + T <= M) { //�
			X += T; //X�� �ɹڼ�
			N--;
		}
		else { // �޽�
			X -= R;
			if (X < m) X = m;
		}
		ans++;
	}
	cout << ans;
	
	/*
	int X = m;
	while (N != 0) {
		tmp = (M - X) / T; //��� �� �� �� �ִ� Ƚ��
		
		if (tmp == 0) { // �޽��� ���ؾ� �Ѵ�
			// �޽��� ���ϴ� Ƚ���� �ִ밪�� ���� ���� ��ð� N��
			// m�� �� ������ �޽��� �Ѵ�
			// �̶� �޽�Ƚ������ N
		}

		if (X + T <= M) { //�
			X += T; //X�� �ɹڼ�
			N--;
		}
		else { // �޽�
			X -= R;
			if (X < m) X = m;
		}
		ans++;
	}
	cout << ans;
	*/

	/*
	// ����� �غ���.
	int total = N * T; // �� ��ϸ鼭 �ö󰡴� �ɹڼ� total
	int low = (m + total) - M; //�̸�ŭ�� ������ ��
	
	int rest = ceil((double)low / (double)R); // �޽� Ƚ��
	
	cout << N + rest;
	*/
	return 0;
}