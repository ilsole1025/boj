#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input; cin >> input;
	int len = input.length();
	int type = -1; //0�̸� java 1�̸� c++

	for (int i = 0; i < len; i++) {
		if (i == 0) { //ù���� �ҹ��� �ƴ�
			if ('a' > input[i] || input[i] > 'z') {
				cout << "Error!"; return 0;
			}
		}
		if (i <= len - 2) {
			if (input[i] == '_' && input[i + 1] == '_') {
				// 2���� _ ���� ���
				cout << "Error!"; return 0;
			}
		}
		if (i == len - 1) {
			if (input[i]=='_') {
				cout << "Error!"; return 0;
			}
		}

		if (i != 0 && 'A' <= input[i] && input[i] <= 'Z') {
			// java���Ŀ��� ù �ܾ�� �빮�ڰ� �ƴ�
			type = 0;
			break;
		}
		if (i != 0 && input[i-1] != '_' &&
			input[i] == '_' && input[i+1] != '_') {
			type = 1;
			break;
		}
	}
	if (type == -1) {
		// 1. ù �ܾ �ҹ���+�״����� ��ҹ��ڼ���
		// 2. �ҹ��ڸ� �ְ� ���ټ���
		// 3. �̰� �ƴϸ� ����ҹ��ڷθ� �Ǿ�����

		int ifalllower = 1;
		for (int i = 0; i < len; i++) {
			if ('a' > input[i] || 'z' < input[i]) {
				// ���� �ҹ��ڰ� �ƴ�
				ifalllower = 0;
			}
		}
		if (ifalllower == 0) {
			cout << "Error!"; return 0;
		}
	}
	// cout << "type: " << type << "\n";

	if (type == 0) { // java
		for (int i = 0; i < len; i++) {
			if (input[i] == '_') {
				cout << "Error!"; return 0;
			}
		}
	}
	if(type==1) { // c++
		for (int i = 0; i < len; i++) {
			if ('A' <= input[i] && input[i] <= 'Z') {
				cout << "Error!"; return 0;
			}
		}
	}


	if (type == 0) { // java -> c++
		for (int i = 0; i < len; i++) {
			if ('A' <= input[i] && input[i] <= 'Z') {
				// ���� �빮��
				cout << "_" << (char)tolower(input[i]);
			}
			else { //���� �ҹ���
				cout << input[i];
			}
		}
	}
	else { // c++ -> java
		for (int i = 0; i < len; i++) {
			// _ ������ �׳� ����ġ�� �״����� �빮�ڷ� ���
			if (input[i] == '_') {
				i++;
				cout << (char)toupper(input[i]);
			}
			else {
				cout << input[i];
			}
		}
	}

	return 0;
}