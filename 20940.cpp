#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
typedef long long ll;
using namespace std;

ll N, K;
ll mem[10005][10005];

ll gcd(ll a, ll b) {
	if (a == 1 || b == 1) return 1;
	ll tmp, n;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}
ll lcm(ll a, ll b, ll gcd) {
	ll res = gcd * (a / gcd) * (b / gcd);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	
	
	/*
	for (ll n = 1; n <= N; n++) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				res += (i*j);
				res %= K;
			}
		}
	}*/
	/*
	res += (N*(N + 1)*(2 * N + 1)*(3 * N*N + 3 * N - 1)) / 30;
	res -= (N * N * (N + 1) * (N + 1) / 2);
	res += (N*(N + 1)*(2 * N + 1) / 6);
	res /= 4;
	*/
	ll res = 0;
	ll tCnt = 2;
	ll tmul = 1;

	while (tCnt<=N+1) {
		res += (tmul*tmul);
		res %= K;
		tmul += tCnt;
		tCnt++;
	}

	cout << res << "\n";

	ll res1 = 0;
	for (ll i = 1; i <= N; i++) {
		ll tmpSum = 0;
		if (i != 1) {
			for (ll j = 1; j <= i-1; j++) {
				mem[i][j] = gcd(i, j);
				tmpSum += mem[i][j];
				tmpSum %= K;
			}
			tmpSum *= 2;
			tmpSum %= K;
		}
		tmpSum += i; //gcd(i,i)
		
		res1 += (tmpSum)*(N - i + 1);
		res1 %= K;

		//printf("i는 %lld, tmpSum:%lld, res1:%lld\n", i, tmpSum,res1);
	}
	printf("res1:%lld\n", res1);

	ll res2 = 0;
	for (ll i = 1; i <= N; i++) {
		ll tmpSum = 0;
		if (i != 1) {
			for (ll j = 1; j <= i - 1; j++) {
				tmpSum += (i*j) / mem[i][j];
				tmpSum %= K;
			}
			tmpSum *= 2; //양쪽의 lcm값은 같다
			tmpSum %= K;
		}
		tmpSum += i; //lcm(i,i)
		res2 += (tmpSum)*(N - i + 1);
		//printf("i는 %lld, tmpSum:%lld\n", i, tmpSum);
	}

	ll ans = (res1 % K);
	ans *= (res%K);
	ans %= K;
	cout << ans;
	

	return 0;
}