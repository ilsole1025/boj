#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int n;
string cryp;
string dic[21];
string push(string a, int b) {
	// ���ڿ� a�� i��ŭ �� ���ڿ� ����
	char ret[101] = { 0, };
	int i;
	for (i = 0; i < a.length(); i++) {
		int tmp = (int)a[i] + b; //char�� �ϸ� 127 �Ѿ�� �����Ⱚ�� ��
		// �ҹ��ڷθ� �̷��������
		// z+1=123�̸� a=97�� �ٲ���� ��
		if ('z' < tmp) tmp -= 26;
		ret[i] = (char)tmp;
	//	cout << "i: " << i << "a[i]:" << a[i] << ", b:" << b << " tmp : " << tmp << endl;
	}
	ret[i + 1] = '\0';
	string ret2(ret);

	return ret2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> cryp >> n;
	for (int i = 0; i < n; i++) cin >> dic[i];

	bool ans = false;
	for (int i = 0; i < 26; i++) {
		string after = push(cryp, i);
		for (int j = 0; j < n; j++) {
			// after �ȿ� ������ �ܾ �ִ��� üũ
			if (after.find(dic[j]) != string::npos) {
				ans = true;
				cout << after;
				return 0;
			}
		}
	}
	
	return 0;
}