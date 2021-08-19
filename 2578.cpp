#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int bingo[5][5];

int count() {
	int cnt = 0; int is_bingo;
	// �ش� �����ٿ� ���� �ִ��� Ȯ��
	for (int i = 0; i < 5; i++) {
		is_bingo = 1;
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] != 0) {
				is_bingo = 0;
				break;
			}
		}
		if (is_bingo == 1) cnt++;
	}

	// �ش� �����ٿ� ���� �ִ��� Ȯ��
	for (int j = 0; j < 5; j++) {
		is_bingo = 1;
		for (int i = 0; i < 5; i++) {
			if (bingo[i][j] != 0) {
				is_bingo = 0;
				break;
			}
		}
		if (is_bingo == 1) cnt++;
	}
	
	// �밢�� [0][0]���� [4][4]����
	is_bingo = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][i] != 0) is_bingo = 0;
	}
	if (is_bingo == 1) cnt++;

	// �밢�� [0][4] [1][3] [2][2] [3][1] [4][1]
	is_bingo = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][4-i] != 0) is_bingo = 0;
	}
	if (is_bingo == 1) cnt++;

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int call[25];
	for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)
			cin >> bingo[i][j];
	for (int i = 0; i < 25; i++) cin >> call[i];
	//������� �Է¹ޱ�


	for (int i = 0; i < 25; i++) {
		// ���� �θ��� �ش����ĭ 0���� �����
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (bingo[j][k] == call[i]) {
					bingo[j][k] = 0;
					break;
				}
			}
		}

		int cnt = count();
		if (cnt >= 3) {
			cout << i+1;
			return 0;
		}
	}
	return 0;
}