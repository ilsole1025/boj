#include<iostream>
#include<vector>
#include<string>
#include<tuple>
using namespace std;

int n;
vector<pair<int, int>> v;
int time;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	for (int i = 0; i < n; i++) {
		a = v[i].first;
		b = v[i].second;

		if (i == 0) {
			time += b; //ó������ ������ ��ٷ��� ��
			time++; //�̵��ϴµ� 1�� �ҿ��
			continue;
		}

		int tmp = time % (a + b);
	//	printf("\n���� i:%d,a,b:%d,%d, tmp:%d,time:%d\n", i,a,b, tmp, time);
		if ( tmp < b) {
			// b�� �� Ž���ð�
			// b - tmp��ŭ ��ٷ��� ��
			time += (b - tmp);
	//		printf("��ٷ��� ��/ time:%d\n", time);

			time++; // �̵��ϴµ����� 1�ʰ� �ɸ�
		}
		else { 
			//���� ���½ð�: �ٷ� �̵�����
	//		printf("�ٷ��̵�/ time:%d\n", time);

			time++; // �̵��ϴµ����� 1�ʰ� �ɸ�
		}


	}

	cout << time;

	return 0;
}