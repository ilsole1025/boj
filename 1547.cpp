#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
#include<cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	bool cup[3];
	cup[0] = true; cup[1] = false; cup[2] = false;
	int m, x, y;
	cin >> m;
	while (m--) {
		cin >> x >> y;
		x--; y--;
		if (cup[x]) {
			cup[x] = false; cup[y] = true;
		}
		else if (cup[y]) {
			cup[y] = false; cup[x] = true;
		}
	}

	for (int i = 0; i <= 2; i++) {
		if (cup[i]) cout << i + 1;
	}

	return 0;
}