#include<iostream>
#include<vector>
using namespace std;

bool white = true;
void change() {
	if (white) white = false;
	else white = true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int ans=0; char tmp;
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> tmp;
			if (white) {
				if (tmp == 'F') ans++;
			}
			change();
		}
		change();
	}

	cout << ans;

	return 0;
}