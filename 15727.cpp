#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	// 6���̸�.. ���� 4�� ������ ���� 1�� ��ġ�� ������ 2�� 
	cout << k / m <<" "<< k % m;

	return 0;
}