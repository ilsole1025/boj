#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include <iomanip>
using namespace std;
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		char a = s[i];
		int b = (int)a;
		int num = 0;
		while (b != 0) {
			num += (b % 10);
			b /= 10;
		}
		while (num--) cout << a;
		cout << "\n";
	}
	return 0;
}