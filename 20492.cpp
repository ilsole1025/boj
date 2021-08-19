#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include <iomanip>
using namespace std;
int main() {
	double n; cin >> n;

//	cout << 0.78*n << " " << n - 0.044*n;
//	cout << n * 78 / 100 << " " << n - n * 44 / 1000;
	cout << setprecision(0) << fixed << n * 0.78 << ' ' << n - 0.044*n << endl;

	int a = 0.78*n;
	int b = n - 0.044*n;
//	cout << a << " " << b;

	return 0;
}