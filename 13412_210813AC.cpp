typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<limits.h>
#include<stack>
using namespace std;
int Gcd(int a, int b){
	int r = a % b;
	if (r == 0) return b;
	else return Gcd(b, r);
}
void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; // n은 100000000까지

	/* 1부터 sqrt(n)까지 나눠보면서
		나누어떨어지는 수에 대해서
		gcd함수 보내서 서로소검사
		(gcd==1이면 서로소임)
		그러면 ans++;
	*/
	int ans = 0;
	
	for (int i = 1; i <= (int)sqrt(n); i++) {
		if (n%i == 0) {
			int ret = Gcd(i, n / i);
			if (ret == 1) ans++;
		}
	}
	cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}