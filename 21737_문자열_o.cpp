#define MAX 500000
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<math.h>
#include <iomanip>
using namespace std;

int n;
int number[MAX + 1];
char alpha[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	string s; cin >> s;
	int num = 0; int res = 0;
	int num_idx = 0, alp_idx = 0;
	int is_number = 0;
	int is_there_C = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'C') is_there_C = 1;
		if ('A' <= s[i] && s[i] <= 'Z') { // 알파벳일 경우
			if (is_number == 1) {
				number[num_idx] = num;
				num = 0; //초기화
				num_idx++;
			}
			alpha[alp_idx] = s[i];
			alp_idx++;
			is_number = 0;
		}
		else { // 숫자일 경우
			num *= 10; // 0일 경우 그대로임
			num += s[i] - '0';
			is_number = 1;
		}
	}
	if (is_there_C == 0) {
		cout << "NO OUTPUT";
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		//	cout << number[i] << " ";
	}
	//cout << "\n";
	for (int i = 0; i < s.length(); i++) {
		//	cout << alpha[i] << " ";
	}
	//cout << "\n";

	int ans = number[0];
	int tmp = 1;
	for (int i = 0; i < alp_idx; i++) {
		if (alpha[i] == 'S') {
			ans -= number[tmp++];
		}
		else if (alpha[i] == 'M') {
			ans *= number[tmp++];
		}
		else if (alpha[i] == 'U') {
			ans /= number[tmp++];
		}
		else if (alpha[i] == 'P') {
			ans += number[tmp++];
		}
		else if (alpha[i] == 'C') {
			cout << ans << " ";
		}
	}


	return 0;
}