
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

	double a, b, x, ans_x, ans_y, tmp1, tmp2, k;

	cin >> a >> b;

	x = (a * sqrt(a*a + b * b) - a * a) / b;
	
	ans_x = sqrt(a*a + x * x) / 2;

	double cos_2o = a / (sqrt(a*a + b * b));
	double sin_o = sqrt((1 - cos_2o) / 2);

	tmp1 = a * sin_o;
	k = sqrt(a*a + b * b) - a;
	tmp2 = k * sin_o;

	ans_y = tmp1 + tmp2;

	cout << ans_x << " " << ans_y;
	
	return 0;
}