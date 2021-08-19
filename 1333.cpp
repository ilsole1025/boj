#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, l, d; cin >> n >> l >> d;
	int time = 0;
	
	while (1) {
		time += d; //전화벨 울리는 순간의 시간

		if (time >= n*l + 5 * (n - 1)) { // 앨범 수록곡 다 들었을때. 
			// 전체 길이는 n*l + 5(n-1)
			// 이부분 놓쳐서 한번 틀림..
			cout << time; return 0;
		}

		/* 전화벨이 울리는 순간 time을 L + 5초로 나눴을 때
		   나머지가 L보다 작다면 전화벨 못 들음 */
		if (time % (l + 5) < l) { }
		else {
			cout << time; return 0;
		}
	}
	return 0;
}