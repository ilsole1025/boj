#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void solve() {
	string s; cin >> s;
	if (s.length() != 7) {
		cout << "0\n";
		return;
	}
	char a = s[0];
	char b = s[2];
	if(a==b) {
		cout << "0\n";
		return;
	}
	for (int i = 0; i < 7; i++) {
		if (s[i] == a) s[i] = 'A';
		else if (s[i] == b) s[i] = 'B';
	}
	if(s == "AABBABB") {
		cout << "1\n";
		return;
	}
	else {
		cout << "0\n";
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}