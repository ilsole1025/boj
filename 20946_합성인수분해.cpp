#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
typedef long long ll;
using namespace std;

ll n;

bool isPrime(ll a) {
	if (a == 2 || a == 3 || a == 5 || a == 7) return true;
	if (a % 2 == 0 || a == 1 || a == 9) return false;
	if (!(a & 1)) { return false; }
	ll range = a / 3;
	unsigned pos = 3;
	while (pos <= range) {
		if (!(a % pos) || !(a % (pos + 2))) { return false; }
		pos += 4;
		range = a / pos;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	clock_t start = clock();
	if (isPrime(n)) { cout << "-1"; return 0; }

	ll origN = n;
	vector<ll> res; //소인수분해


	if (origN == 4) { //아래코드에서 런타임에러남;
		cout << 4;
		return 0;
	}

	ll k = 2;
	while (n != 1 && k*k <= origN) {
		if (n % k == 0) {
			res.push_back(k);
			n /= k;
		}
		else if (k == 2) {
			k++;
		}
		else {
			k += 2;
		}
	}
	
	if(n != 1 && isPrime(n)) 
		res.push_back(n); //위에 k*k<=N 제한으로 미처 다 못 넣은 경우

	// printf("n:%lld, k:%lld\n", n, k);
	// for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	// cout << "\n";

	ll nowN = 1;
	int idx = 0;
	vector<ll> ans;

	while (nowN < origN) {
		if (res.size() == 1) {
			ans.push_back(res[0]);
			nowN *= res[0];
		}
		if (idx + 1 == res.size()) { // idx위치가 마지막이다
			ans.back() *= res[idx]; // 마지막거에 곱해주기
			nowN *= res[idx];
		}
		else { // idx와 idx+1을 볼 수 있다
			ll tmp = res[idx] * res[idx + 1];
			ans.push_back(tmp);
			nowN *= tmp;
			idx += 2;
		}
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}