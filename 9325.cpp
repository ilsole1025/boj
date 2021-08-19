#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long t;
	cin >> t;
	long long s, n, q,p;

	while (t--) {
		long long ans = 0;
		cin >> s >> n;
		ans += s;
		for (long long i = 0; i < n; i++) {
			cin >> q >> p;
			ans += (q*p);
		}
		cout << ans << "\n";
	}

	return 0;
}