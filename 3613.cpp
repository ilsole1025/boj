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
	int type = -1; //0이면 java 1이면 c++

	for (int i = 0; i < len; i++) {
		if (i == 0) { //첫글자 소문자 아님
			if ('a' > input[i] || input[i] > 'z') {
				cout << "Error!"; return 0;
			}
		}
		if (i <= len - 2) {
			if (input[i] == '_' && input[i + 1] == '_') {
				// 2연속 _ 나온 경우
				cout << "Error!"; return 0;
			}
		}
		if (i == len - 1) {
			if (input[i]=='_') {
				cout << "Error!"; return 0;
			}
		}

		if (i != 0 && 'A' <= input[i] && input[i] <= 'Z') {
			// java형식에서 첫 단어는 대문자가 아님
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
		// 1. 첫 단어가 소문자+그다음은 대소문자섞임
		// 2. 소문자만 있고 밑줄섞임
		// 3. 이게 아니면 영어소문자로만 되어있음

		int ifalllower = 1;
		for (int i = 0; i < len; i++) {
			if ('a' > input[i] || 'z' < input[i]) {
				// 영어 소문자가 아님
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
				// 영어 대문자
				cout << "_" << (char)tolower(input[i]);
			}
			else { //영어 소문자
				cout << input[i];
			}
		}
	}
	else { // c++ -> java
		for (int i = 0; i < len; i++) {
			// _ 나오면 그냥 지나치고 그다음거 대문자로 출력
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