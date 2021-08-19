#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int N;
int game[6][6];
// 0: �ƹ��͵� ������ ����, 1:��, 2:��
bool turn;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) game[i][j] = 0;
	game[2][2] = game[3][3] = 1;
	game[2][3] = game[3][2] = 2;
	
	int R, C;
	turn = false; // �� ���� ����

	for (int log = 0; log < N; log++) {
		cin >> R >> C;
		R--; C--;
		if (!turn) { //�� ����
			game[R][C] = 2;
		}
		else { // �� ����
			game[R][C] = 1;
		}
		// �� ���ʶ��, �Ͼ� ����(game==1)�� ���鼭 �̰� ������(game==2) üũ
		for (int r = 0; r < 6; r++) {
			for (int c = 0; c < 6; c++) { // �� �ڸ��ڸ��� ����
				int chk = 0;
				if (game[r][c] == 1) {
					// ���� üũ����.
					for (int i = 0; i < r; i++) { //üũ�ϴ°� �� ���� ���: r==0
						if (game[i][c] == 0) continue;
						if (game[i][c] == 2) {
							if (i + 1 == r) chk++; //�ٷ� ���� �ִ� ���
							else { // �� �� �� �� '��' �̷� ���
								bool tmpChk = true;
								for (int ti = i+1; ti < r; ti++) {
									// ��ġ [r][c] �������� ��� ������ Ȯ��
									// ��� ���̶�� �̰� chk++;
									// ��������� üũX, �׳� �ѱ�
									// ���̶�� �׳� �Ѱ��ش�
									//if (game[ti][c] == 0||game[ti][c]==2) break;
									if (game[ti][c] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //���� �ѷ��ο� �ִ�
							}
						}
					}
					// �Ʒ��� üũ����
					for (int i = r+1; i < 6; i++) {
						if (game[i][c] == 0) continue;
						if (game[i][c] == 2) {
							if (r+1==i) chk++; //�ٷ� �Ʒ��� �ִ� ���
							else { // '��' �� ��(üũ���) �̷� ���
								bool tmpChk = true;
								for (int ti = i - 1; ti > r; ti--) {
									if (game[ti][c] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //�Ʒ��� �ѷ��ο� �ִ�
							}
						}
					}
					// ���� üũ
					for (int j = 0; j < r; j++) {
						if (game[r][j] == 0) continue;
						if (game[r][j] == 2) {
							if (j + 1 == c) chk++; 
							else {
								bool tmpChk = true;
								for (int tj = j + 1; tj < r; tj++) {
									if (game[r][tj] != 1) tmpChk = false;
								}
								if (tmpChk) chk++;
							}
						}
					}

					// ���� üũ����
					for (int j = c + 1; j < 6; j++) {
						if (game[r][j] == 0) continue;
						if (game[r][j] == 2) {
							if (c + 1 == j) chk++; //�ٷ� �Ʒ��� �ִ� ���
							else { // '��' �� ��(üũ���) �̷� ���
								bool tmpChk = true;
								for (int tj = j - 1; tj > r; tj--) {
									if (game[r][tj] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //�Ʒ��� �ѷ��ο� �ִ�
							}
						}
					}

					// �»�-���� �밢�� Ư¡:�ε��� ���� ����
					int minus = c-r; // �� �밢�� ���� �����ִ°� [i][i+minus]
					for (int i = 0; i<6; i++) {
						// game[i][i+minus] �� ==2���� [r][c]�� �ѷ��δ��� üũ
						if (i == r) continue;
						if (game[i][i+minus] == 0) continue;
						if (game[i][i + minus] == 2) {
							if (c + 1 == j) chk++; //�ٷ� �Ʒ��� �ִ� ���
							else { // '��' �� ��(üũ���) �̷� ���
								bool tmpChk = true;
								for (int tj = j - 1; tj > r; tj--) {
									if (game[r][tj] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //�Ʒ��� �ѷ��ο� �ִ�
							}
						}
					}
					
					// chk >= 3�̸� ������
				}

			}
		}

		// �� ���ʶ�� ���� ���� ���鼭 üũ
	}

	

	cout << "-1";
	return 0;
}