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
void solve() { // 각 테스트케이스마다
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	v.clear();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp; v.push_back(tmp);
	}

	int round = v[0].length();
	int check[3];
	for (int i = 0; i < round; i++) {
		fill_n(check, 3, -1); // 초기화

		// 각 라운드마다 v[0][i], v[1][i]...v[n-1][i]가 대결함
		// 즉 v[j][i]에서 R,S,P중 뭐가 나오는지 봐야함
		
		for (int j = 0; j < v.size(); j++) {
			if (v[j][i] == 'R') check[0] = 1;
			if (v[j][i] == 'S') check[1] = 1;
			if (v[j][i] == 'P') check[2] = 1;
		}
		int sum = 0;
		for (int j = 0; j < 3; j++) if (check[j] == 1) sum++;
		if (sum == 3 || sum==1) { // 비김
			// 아무것도 할 필요 없음
		}
		else if (sum == 2) { // 진 거를 없애준다
			if (check[0] == -1) { // S이김 P짐
				for (int j = 0; j <v.size(); j++) {
					if (v[j][i] == 'P') {
						v[j] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
					}
				}
			}
			else if (check[1] == -1) { // R짐 P이김
				for (int j = v.size() - 1; j >= 0; j--) {
					if (v[j][i] == 'R') {
						v[j] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
					}
				}
			}
			else if(check[2] == -1){ // R이김 S짐
				for (int j = v.size() - 1; j >= 0; j--) {
					if (v[j][i] == 'S') {
						v[j] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
					}
				}
			}
			else cout << "뭔가 에러남\n";
		}
	//	printf("round:%d\n---------\n", i);
		for (int j = 0; j < v.size(); j++) {
	//		cout << "로봇" << j << ": " << v[j] << "\n";
		}
	}
	// 결론내기
	int sum = 0, ans;
	for (int j = 0; j < v.size(); j++) {
		if (v[j][0] != 'X') { // 살아있는 로봇
			sum++;
			ans = j+1;
		}
		if (sum >= 2) { // 비김
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