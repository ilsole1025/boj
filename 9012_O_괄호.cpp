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
			// pop�Ϸ��µ� ��������� false
			if (s.empty()) return false;
			else s.pop();
			//���ÿ� ������ �ִٴ°�, (�� ���ٴ� ��
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