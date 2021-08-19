typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	
	ll n, f; cin >> n >> f;
	ll mod = n % 100;
	n -= mod;
	for (ll i = 0; i < 100; i++) {
		if ((n + i) % f == 0) {
			printf("%02d\n", i);
			return 0;
		}
	}

	return 0;
}