#include<iostream>
#include<vector>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> v;

	while (1) {
		v.push_back(n%9);   //�ش� ������ ���� �������� vector�� ����
		n /= 9;
		if (n == 0) break;
	}


	vector<int>::reverse_iterator iter;

	// ������ �ݺ��ڶ��  vector<int>::iterator iter;
	//						v.begin(); v.end();
	// ���⼱ ������ �ݺ��� ���

	for (iter = v.rbegin(); iter != v.rend(); iter++) {
		cout << *iter;
	}


	return 0;
}