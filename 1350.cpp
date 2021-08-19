#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	long long int s[1001];
	long long int size;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	cin >> size;
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += ceil((double)s[i] / (double)size);
	}

	cout << ans*size;
	
	return 0;
}