#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	c += d;
	if (c >= 60) {
		//�ʴ���
		b += (c / 60); //�д��� �Ѱ��ְ�
		c %= 60; //�ʷ� �����
	}

	if (b >= 60) {
		// �д���
		a += (b / 60);
		b %= 60;
	}

	// if (a >= 24) { a -= 24; }
	//  48�� �Ѿ���� �ִ�!!
	if (a >= 24) a %= 24;

	cout << a << " " << b << " " << c;

	return 0;
}