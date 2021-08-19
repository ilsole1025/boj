#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 5522
	/*
	int ans = 0;
	int A;
	for (int i = 0; i < 5; i++) {
		cin >> A;
		ans += A;
	}
	cout << ans;
	*/

	//6749

	int y, m;
	cin >> y >> m;
	cout << m + m - y;
	return 0;
}