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
	getline(cin, str); //공백 포함 문자열 입력받기

	/* 처음부터 끝까지 보면서 공백이나 <가 나올 때까지 스택에 넣는다.
	공백이나 <가 나오면 팝하면서 출력함.
	만약 '<'가 나오면 '>'가 나올때까지 그대로 출력한다.*/
	int i;
	for (i = 0; i < str.length(); i++) {
		if (!s.empty() &&
			(str[i] == '<' || str[i] == ' ' )) {
			// 스택 비우는 조건
			
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

		if (str[i] == '<') { // >가 나올때까지 그대로 출력함
			
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
		// <태그>안의 내용은 스택에 넣지 않는다
		
	}

	if (!s.empty()) { //마지막 용도
		while (!s.empty()) {
			cout << s.top();
				s.pop();
		}
	}

	return 0;
}