#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
#include<cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b; cin >> a >> b;
	a--; b--; // ex. 1과 4의 경우 몫이 다르게 나옴
	int x = (b / 4) - (a / 4);
	int y = (b % 4) - (a % 4);
	
	if (x < 0) x *= -1;
	if (y < 0) y *= -1;
	cout << x + y;

	return 0;
}