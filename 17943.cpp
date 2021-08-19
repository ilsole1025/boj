typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, Q; cin >> N >> Q;
	ll domino[200003];
	for (ll i = 0; i < N - 1; i++) cin >> domino[i];
	ll type, x, y, d;
	for (ll i = 0; i < Q; i++) {
		cin >> type;
		if (type == 0) {
			cin >> x >> y;
		}
		else {
			cin >> x >> y >> d;
		}
	}

	return 0;
}