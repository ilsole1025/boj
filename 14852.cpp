
#include<iostream>
#include<vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int a[9], b[9];
	for (int i = 0; i < 9; i++) cin >> a[i];
	for (int i = 0; i < 9; i++) cin >> b[i];

	int x = 0, y = 0;
	bool ans = false;
	for (int i = 0; i < 9; i++) {
		while (a[i]--) {
			x++;
			if (x > y) ans = true;
		}
		while (b[i]--) {
			y++;
		}
		if (x > y) ans = true;
	}

	if (ans) cout << "Yes";
	else cout << "No";

	return 0;
}