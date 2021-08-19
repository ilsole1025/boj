#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ret;
	string input;
	int idx[26];

	cin >> input;
	fill_n(idx, 26, -1);

	for (int i = 0; i < input.length(); i++) {
		char tmp = input[i];
		if (idx[tmp - 'a'] == -1) {
			// 처음 나온 거임, 그룹 ㅇㅋ
			idx[tmp - 'a'] = i;
		}
		else {
			if (idx[tmp - 'a'] != i - 1) {
				return 0;
			}
			else idx[tmp - 'a'] = i;
		}
		// 확인용
		/*
		printf("i:%d | ",i);
		for (int i = 0; i < 26; i++) {
			cout << (char)('a' + i) << idx[i] << " ";
		}
		cout << "\n";
		*/
	}
	

	return 1; //그룹단어 맞음
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	int ans = 0; // 각 단어가 그룹단어인거 확인되면 1씩 추가
	for (int i = 0; i < n; i++) ans += solve();
	
	cout << ans;
	return 0;
}