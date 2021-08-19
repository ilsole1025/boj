#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	// N이 10^9까지라 시간초과날까봐 고민했는데..
	// 10000 00000 이렇게 나누면.. 될것같기도 해서??
	// 대충 10만까지만 돌려봤는데 맞았다. 근데 왜지...?

	int cnt[10];
	for (int A = 1; A < 100000; A++) {
		bool flag = true;
		int a = A; int B = n - a; int b = B;
		if (b <= 0) continue; 
		if (a == b) continue; // 2같은 경우 고려

		for (int i = 0; i < 10; i++) cnt[i] = 0; //초기화
		while (a > 0) {
			cnt[a % 10]++;
			if (cnt[a % 10] >= 2) {
				flag = false;
				break;
			}
			a /= 10;
		}
		if (flag == false) continue;
		while (b > 0) {
			cnt[b % 10]++;
			if (cnt[b % 10] >= 2) {
				flag = false;
				break;
			}
			b /= 10;
		}

		if (flag) {
			cout << A << " + " << B;
			return 0;
		}
	}

	cout << "-1";
	return 0;
}