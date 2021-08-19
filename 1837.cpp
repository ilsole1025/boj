#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

/*
��� �ϵ������� Ǯ ���� �ִ� ��������.
�ٵ� ���� ���� �����ϰ� ���� ����ϱ�..? �� ����ؾ��ϴ� ���� ����.
*/
long long int prime(long long n) {
	if (n == 2) return 2;
	if (n == 3) return 3;
	if (n == 1) return -1;
	if (n % 2 == 0) return -1;
	for (long long i = 5; i < sqrt(n); i += 2) {
		if (n % i == 0) 
			return -1;
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long int p, k;
	cin >> p >> k;
/* p�� �� �Ҽ��� ������ �̷���� ����
p�� 2���� k������ �Ҽ��� �������鼭 �������� BAD�� r�� ����Ѵ�.
k���� �����µ� �� �������� good���
*/
	if (p % 2 == 0) { //p==2�� ���� �������ǿ� ����
		cout << "BAD " << "2";
		return 0;
	}

	for (long long int i = 3; i < k; i += 2) {
		if (prime(i) != -1) { // �Ҽ����
			if (p % i == 0) {
				cout << "BAD " << i;
				return 0;
			}
		}
		else {
			// �Ҽ� �ƴϸ� �Ѿ
		}
	}

	cout << "GOOD";

	return 0;
}