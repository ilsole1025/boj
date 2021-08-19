#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	// N�� 10^9������ �ð��ʰ������ ����ߴµ�..
	// 10000 00000 �̷��� ������.. �ɰͰ��⵵ �ؼ�??
	// ���� 10�������� �����ôµ� �¾Ҵ�. �ٵ� ����...?

	int cnt[10];
	for (int A = 1; A < 100000; A++) {
		bool flag = true;
		int a = A; int B = n - a; int b = B;
		if (b <= 0) continue; 
		if (a == b) continue; // 2���� ��� ���

		for (int i = 0; i < 10; i++) cnt[i] = 0; //�ʱ�ȭ
		while (a > 0) {
			cnt[a % 10]++;
			if (cnt[a % 10] >= 2) {
				flag = false;
				break;
			}
			a /= 10;
		}
		if (flag == false) continue;
		while (b > 0) {
			cnt[b % 10]++;
			if (cnt[b % 10] >= 2) {
				flag = false;
				break;
			}
			b /= 10;
		}

		if (flag) {
			cout << A << " + " << B;
			return 0;
		}
	}

	cout << "-1";
	return 0;
}