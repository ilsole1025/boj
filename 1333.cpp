#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, l, d; cin >> n >> l >> d;
	int time = 0;
	
	while (1) {
		time += d; //��ȭ�� �︮�� ������ �ð�

		if (time >= n*l + 5 * (n - 1)) { // �ٹ� ���ϰ� �� �������. 
			// ��ü ���̴� n*l + 5(n-1)
			// �̺κ� ���ļ� �ѹ� Ʋ��..
			cout << time; return 0;
		}

		/* ��ȭ���� �︮�� ���� time�� L + 5�ʷ� ������ ��
		   �������� L���� �۴ٸ� ��ȭ�� �� ���� */
		if (time % (l + 5) < l) { }
		else {
			cout << time; return 0;
		}
	}
	return 0;
}