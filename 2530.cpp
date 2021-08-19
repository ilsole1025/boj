#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	c += d;
	if (c >= 60) {
		//초단위
		b += (c / 60); //분단위 넘겨주고
		c %= 60; //초로 계산함
	}

	if (b >= 60) {
		// 분단위
		a += (b / 60);
		b %= 60;
	}

	// if (a >= 24) { a -= 24; }
	//  48을 넘어갈수도 있다!!
	if (a >= 24) a %= 24;

	cout << a << " " << b << " " << c;

	return 0;
}