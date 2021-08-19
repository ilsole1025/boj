typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x; cin >> x;
	int order = 0, n=1;
	while (1) {
		order = n * (n + 1) / 2;
		n++;
		if (x <= order) break;
		// 1 3 6 10 15...
	}
	order -= (n-1);

	// x - order만큼 더 순서를 세어야 하고 이게 분자
	// 분모 분자의 합은 n
	
	if (n % 2 == 0) { //n이 짝수면 우상향
		int b = x - order;
		int a = n - b;
		cout << a << "/" << b;
	}
	else { // n이 홀수면 좌하향
		int a = x - order;
		int b = n - a;
		cout << a << "/" << b;
	}
	

	return 0;
}