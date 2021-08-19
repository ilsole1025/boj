#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int N;
int game[6][6];
// 0: 아무것도 놓이지 않음, 1:흰, 2:검
bool turn;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) game[i][j] = 0;
	game[2][2] = game[3][3] = 1;
	game[2][3] = game[3][2] = 2;
	
	int R, C;
	turn = false; // 흑 먼저 시작

	for (int log = 0; log < N; log++) {
		cin >> R >> C;
		R--; C--;
		if (!turn) { //흑 차례
			game[R][C] = 2;
		}
		else { // 백 차례
			game[R][C] = 1;
		}
		// 흑 차례라면, 하얀 돌들(game==1)을 보면서 이게 막혔나(game==2) 체크
		for (int r = 0; r < 6; r++) {
			for (int c = 0; c < 6; c++) { // 각 자리자리에 대해
				int chk = 0;
				if (game[r][c] == 1) {
					// 위를 체크하자.
					for (int i = 0; i < r; i++) { //체크하는게 맨 위인 경우: r==0
						if (game[i][c] == 0) continue;
						if (game[i][c] == 2) {
							if (i + 1 == r) chk++; //바로 위에 있는 경우
							else { // 빈 빈 흑 백 '백' 이런 경우
								bool tmpChk = true;
								for (int ti = i+1; ti < r; ti++) {
									// 위치 [r][c] 직전까지 모두 백인지 확인
									// 모두 백이라면 이건 chk++;
									// 비어있으면 체크X, 그냥 넘김
									// 흑이라면 그냥 넘겨준다
									//if (game[ti][c] == 0||game[ti][c]==2) break;
									if (game[ti][c] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //위는 둘러싸여 있다
							}
						}
					}
					// 아래를 체크하자
					for (int i = r+1; i < 6; i++) {
						if (game[i][c] == 0) continue;
						if (game[i][c] == 2) {
							if (r+1==i) chk++; //바로 아래에 있는 경우
							else { // '백' 백 흑(체크대상) 이런 경우
								bool tmpChk = true;
								for (int ti = i - 1; ti > r; ti--) {
									if (game[ti][c] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //아래는 둘러싸여 있다
							}
						}
					}
					// 왼쪽 체크
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

					// 우측 체크하자
					for (int j = c + 1; j < 6; j++) {
						if (game[r][j] == 0) continue;
						if (game[r][j] == 2) {
							if (c + 1 == j) chk++; //바로 아래에 있는 경우
							else { // '백' 백 흑(체크대상) 이런 경우
								bool tmpChk = true;
								for (int tj = j - 1; tj > r; tj--) {
									if (game[r][tj] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //아래는 둘러싸여 있다
							}
						}
					}

					// 좌상-우하 대각선 특징:인덱스 차가 같음
					int minus = c-r; // 즉 대각선 위에 놓여있는건 [i][i+minus]
					for (int i = 0; i<6; i++) {
						// game[i][i+minus] 가 ==2여서 [r][c]를 둘러싸는지 체크
						if (i == r) continue;
						if (game[i][i+minus] == 0) continue;
						if (game[i][i + minus] == 2) {
							if (c + 1 == j) chk++; //바로 아래에 있는 경우
							else { // '백' 백 흑(체크대상) 이런 경우
								bool tmpChk = true;
								for (int tj = j - 1; tj > r; tj--) {
									if (game[r][tj] != 1) tmpChk = false;
								}
								if (tmpChk) chk++; //아래는 둘러싸여 있다
							}
						}
					}
					
					// chk >= 3이면 뒤집음
				}

			}
		}

		// 백 차례라면 검은 돌들 보면서 체크
	}

	

	cout << "-1";
	return 0;
}