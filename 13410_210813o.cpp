#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;
int reverse(int n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	int ret = stoi(s);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int max = -1;
	
		for (int j = 1; j <= k; j++) {
			int tmp = reverse(n*j);
		//	printf("tmp:%d\n", tmp);
			if (tmp > max) max = tmp;
		}
	
	cout << max;
	return 0;
}