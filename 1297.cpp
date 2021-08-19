#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	double d, h, w;
	cin >> d >> h >> w;

	double a = 0;
	a += h * h;
	a += w * w;

	double k = d * d / a;
	k = sqrt(k);

	int ans1 = h * k;
	int ans2 = w * k;
	cout << ans1 << " "<< ans2;
	

	return 0;
}