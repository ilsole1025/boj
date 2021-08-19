
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

struct hw {
	int score;
	int time;
};
stack<hw> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, ans=0;
	int type, a, t;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> type;
		if (type == 1) { // 새로 나온 과제를 한다
			cin >> a >> t;
			s.push({ a,t });
			s.top().time--;
			if (s.top().time == 0) {
				ans += s.top().score;
				s.pop();
			}
		}
		else {
			if (s.empty()) continue;
			// 하던 과제를 한다
			s.top().time--;
			if (s.top().time == 0) {
				ans += s.top().score;
				s.pop();
			}
		}
	}

	cout << ans;

	return 0;
}