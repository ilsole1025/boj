typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	map<char, int> m;
	int n; cin >> n;
	std::map<char, int>::iterator it;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		it = m.find(s[0]);
		if (it == m.end()) {
			// ¾ø´Â °Í
			m[s[0]] = 1;
		}
		else {
			m[s[0]] ++;
		}
	}

	bool over5 = false;

	for (it = m.begin(); it != m.end(); it++) {
		if (it->second >= 5) {
			cout << it->first;
			over5 = true;
		}
	}

	if (!over5) cout << "PREDAJA";
	
	return 0;
}