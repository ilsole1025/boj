#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int get_num(string a) {
	if (a == "black") return 0;
	if (a == "brown") return 1;
	if (a == "red") return 2;
	if (a == "orange") return 3;
	if (a == "yellow") return 4;
	if (a == "green") return 5;
	if (a == "blue") return 6;
	if (a == "violet") return 7;
	if (a == "grey") return 8;
	if (a == "white") return 9;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b, c;
	cin >> a >> b >> c;

	long long int num = 0;
	num += get_num(a); num *= 10;
	num += get_num(b);
	num *= pow(10, get_num(c));
	cout << num;

	return 0;
}