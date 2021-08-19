#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;
int t, n;
string tmp;
vector<string> v;
void solve() { // �� �׽�Ʈ���̽�����
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	v.clear();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp; v.push_back(tmp);
	}

	int round = v[0].length();
	int check[3];
	for (int i = 0; i < round; i++) {
		fill_n(check, 3, -1); // �ʱ�ȭ

		// �� ���帶�� v[0][i], v[1][i]...v[n-1][i]�� �����
		// �� v[j][i]���� R,S,P�� ���� �������� ������
		
		for (int j = 0; j < v.size(); j++) {
			if (v[j][i] == 'R') check[0] = 1;
			if (v[j][i] == 'S') check[1] = 1;
			if (v[j][i] == 'P') check[2] = 1;
		}
		int sum = 0;
		for (int j = 0; j < 3; j++) if (check[j] == 1) sum++;
		if (sum == 3 || sum==1) { // ���
			// �ƹ��͵� �� �ʿ� ����
		}
		else if (sum == 2) { // �� �Ÿ� �����ش�
			if (check[0] == -1) { // S�̱� P��
				for (int j = 0; j <v.size(); j++) {
					if (v[j][i] == 'P') {
						v[j] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
					}
				}
			}
			else if (check[1] == -1) { // R�� P�̱�
				for (int j = v.size() - 1; j >= 0; j--) {
					if (v[j][i] == 'R') {
						v[j] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
					}
				}
			}
			else if(check[2] == -1){ // R�̱� S��
				for (int j = v.size() - 1; j >= 0; j--) {
					if (v[j][i] == 'S') {
						v[j] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
					}
				}
			}
			else cout << "���� ������\n";
		}
	//	printf("round:%d\n---------\n", i);
		for (int j = 0; j < v.size(); j++) {
	//		cout << "�κ�" << j << ": " << v[j] << "\n";
		}
	}
	// ��г���
	int sum = 0, ans;
	for (int j = 0; j < v.size(); j++) {
		if (v[j][0] != 'X') { // ����ִ� �κ�
			sum++;
			ans = j+1;
		}
		if (sum >= 2) { // ���
			cout << "0" << "\n";
			return;
		}
	}
	cout << ans << "\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) solve();
	return 0;
}