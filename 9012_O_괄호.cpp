#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool Solve(string str) {
	int len = (int)str.length();
	stack <char> s;

	for (int i = 0; i < len; i++) {
		char a = str[i];

		if (a == '(') {
			s.push(str[i]);
		}
		else {
			// pop하려는데 비어있으면 false
			if (s.empty()) return false;
			else s.pop();
			//스택에 뭔가가 있다는건, (가 들어갔다는 뜻
		}
	}

	return s.empty(); 
}

int main() {
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		if (Solve(str)) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;
}