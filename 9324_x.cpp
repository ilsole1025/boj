#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<char, int> dic;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	string M;

	while (t--) {
		cin >> M;
		for (int i = 0; i < M.length(); i++) {
			char a = M[i];
			if (dic.find(a) == dic.end()) { //������Ѵٸ�
				dic.insert(pair<char, int>(a, 1));
			}
			else { //�����Ѵٸ�
				(dic[a])++;
			}
		}

		bool fake = false;
		for (auto it = dic.begin(); it != dic.end(); it++) {
			char tmp = it->first;
			int cnt = dic[tmp];
			if (cnt >= 3) {
				// 3, 7, 11, 15....�� �����ϸ� ��¥�޽����̴�.
				if ((cnt+1)%4 == 0) {
					fake = true;
					break;
				}
			}
		}
		if (fake) cout << "FAKE" << "\n";
		else cout << "OK" << "\n";

		dic.clear();
	}
	return 0;
}