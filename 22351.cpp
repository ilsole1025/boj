#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<stack>
using namespace std;
string solve(int A, int B) {
	string tmp = ""; string ret = "";
	for (int i = A; i <= B; i++) {
		tmp = to_string(i);
		ret.append(tmp);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S; cin >> S;
	/*
	// 9������ 1�� ���� �ڸ����� �ٲ��
	int digit = 0;
	int a, b;
	// 1�̻� 999���ϴϱ�
	// ���ڸ���,���ڸ���,���ڸ����� ����
	if (s[0]-'0' + 1 == s[1]-'0') {
		if()
	}
	for (int i = 0; i < s.size(); i++) {
		if (i + 1 != s.size()) {
			if (s[i] == 9 && s[i + 1]==1){
				digit++;
			}
		}
	}
	*/
	// A�� B�� 1�̻� 999������ �����̹Ƿ�
	// ��� ����� ���� �� �������� s�� ������ üũ�Ѵ�
	
	int A1 = S[0] - '0';
	
	// �ð��ʰ���
	/*
	for (int A = 4; A <= 999; A++) {
		for (int B = A; B <= 999; B++) {
			string ret = solve(A, B);
		//	cout << A << " " << B << " " << tmp << "\n";
			if (ret == S) {
				cout << A << " " << B;
				return 0;
			}
		}
	}
	*/


	for (int B = A1; B <= 999; B++) {
		string ret = solve(A1, B);
		//	cout << A << " " << B << " " << tmp << "\n";
		if (ret == S) {
			cout << A1 << " " << B;
			return 0;
		}
	}
	int A2 = 10 * (S[0] - '0') + (S[1] - '0');
	for (int B = A2; B <= 999; B++) {
		string ret = solve(A2, B);
		//	cout << A << " " << B << " " << tmp << "\n";
		if (ret == S) {
			cout << A2 << " " << B;
			return 0;
		}
	}
	int A3 = 100 * (S[0] - '0') + 10*(S[1] - '0') + (S[2] - '0');
	for (int B = A3; B <= 999; B++) {
		string ret = solve(A3, B);
		//	cout << A << " " << B << " " << tmp << "\n";
		if (ret == S) {
			cout << A3 << " " << B;
			return 0;
		}
	}
	

	return 0;
}