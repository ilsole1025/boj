#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a;
	vector<long long int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	while (m--) {
		sort(v.begin(), v.end());
		long long int sum = v[0] + v[1];
		v[0] = v[1] = sum;
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += v[i];
	}
	cout << ans;

	return 0;
}