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

	stack<char> s;
	string str;
	getline(cin, str); //���� ���� ���ڿ� �Է¹ޱ�

	/* ó������ ������ ���鼭 �����̳� <�� ���� ������ ���ÿ� �ִ´�.
	�����̳� <�� ������ ���ϸ鼭 �����.
	���� '<'�� ������ '>'�� ���ö����� �״�� ����Ѵ�.*/
	int i;
	for (i = 0; i < str.length(); i++) {
		if (!s.empty() &&
			(str[i] == '<' || str[i] == ' ' )) {
			// ���� ���� ����
			
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			// if (str[i] == ' ') cout << " ";
		}
		if (str[i] == ' ') {
			cout << ' ';
			continue;
		}

		if (str[i] == '<') { // >�� ���ö����� �״�� �����
			
			while (1) {
				cout << str[i];
				i++;
				if (str[i] == '>') {
					break;
				}
			}
			cout << ">";
		}
		else s.push(str[i]);
		// <�±�>���� ������ ���ÿ� ���� �ʴ´�
		
	}

	if (!s.empty()) { //������ �뵵
		while (!s.empty()) {
			cout << s.top();
				s.pop();
		}
	}

	return 0;
}