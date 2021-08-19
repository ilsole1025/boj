#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	string str_ans;
	string str_input;
	for (int i = 0; i < n; i++) {
		cin >> str_input;
		if (i == 0) {
			str_ans = str_input;
			continue;
		}
		for (int j = 0; j < str_input.length(); j++) {
			if (str_ans[j] != str_input[j]) {
				str_ans[j] = '?';
			}
		}

	}
	cout << str_ans;

	return 0;
}