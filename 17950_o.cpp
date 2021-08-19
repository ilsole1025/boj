#define MOD 1000000007
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
	long long int h, x, x1;
	cin >> h >> x;
	x1 = x;
	long long int sum = 0;
	long long int a;
	for (long long int i = 0; i < h; i++) {
		
		cin >> a;
		sum += (long long)(a * x);

		sum %= MOD;
		x = (x*x1)% MOD;
	}
	cout << sum;

	return 0;
}