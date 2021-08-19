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
	int n; cin >> n;
	int a[200001];
	int idx;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == -1) idx = i;
	}

	int min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 0; i < idx; i++) {
		if (min1 > a[i]) min1 = a[i];
	}
	for (int i = idx+1; i < n; i++) {
		if (min2 > a[i]) min2 = a[i];
	}

	cout << min1 + min2;

	return 0;
}