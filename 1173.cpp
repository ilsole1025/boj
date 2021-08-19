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
	
	// 시간초과 났던 이유는 -1 처리를 안 해줘서.
	
	int X = m;
	while (N != 0) {
		if (X + T <= M) { //운동
			X += T; //X는 심박수
			N--;
		}
		else { // 휴식
			X -= R;
			if (X < m) X = m;
		}
		ans++;
	}
	cout << ans;
	
	/*
	int X = m;
	while (N != 0) {
		tmp = (M - X) / T; //운동을 더 할 수 있는 횟수
		
		if (tmp == 0) { // 휴식을 취해야 한다
			// 휴식을 취하는 횟수의 최대값은 현재 남은 운동시간 N분
			// m이 될 때까지 휴식을 한다
			// 이때 휴식횟수보다 N
		}

		if (X + T <= M) { //운동
			X += T; //X는 심박수
			N--;
		}
		else { // 휴식
			X -= R;
			if (X < m) X = m;
		}
		ans++;
	}
	cout << ans;
	*/

	/*
	// 계산을 해보자.
	int total = N * T; // 총 운동하면서 올라가는 심박수 total
	int low = (m + total) - M; //이만큼을 내려야 함
	
	int rest = ceil((double)low / (double)R); // 휴식 횟수
	
	cout << N + rest;
	*/
	return 0;
}