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

	string a;
	cin >> a;
	stack <int> s;
	// 8������ 2������ �ٲٷ���
	if (a == "0") {
		cout << "0";
		return 0;
	}

	for (int i = 0; i < a.length(); i++) {

		// �� if�� 8������ �������̱��ѵ� �����غ������
		//while (!s.empty()) s.pop();
		if (i == 0) {
			int tmp = a[i] - '0'; //(int)�� �ƽ�Ű�� ��ȯ
			while (tmp != 0) {
				s.push(tmp % 2);
				tmp /= 2;
			}
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			continue;
		}
		
		if (a[i] == '0') cout << "000";
		if (a[i] == '1') cout << "001";
		if (a[i] == '2') cout << "010";
		if (a[i] == '3') cout << "011";
		if (a[i] == '4') cout << "100";
		if (a[i] == '5') cout << "101";
		if (a[i] == '6') cout << "110";
		if (a[i] == '7') cout << "111";

	}


	return 0;
}