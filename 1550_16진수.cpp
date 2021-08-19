#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long int ans = 0;
	int digit = 0;

	string input;
	cin >> input;

	for (int i = input.length() - 1; i >= 0; i--) {
		
		char a = input[i];
		long long int tmp;
		if ('0' <= a && a <= '9') {
			tmp = a - '0';
		}
		else { // A:10, B:11, F:15
			tmp = 10 + a - 'A';
		}

	//	printf("a´Â %c, tmp´Â %d, ans´Â %d\n", a, tmp, ans);
		
		tmp *= pow(16, digit);
		digit++;
		ans += tmp;
	}

	cout << ans;

	return 0;
}