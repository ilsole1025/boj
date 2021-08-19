
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a;
	getline(cin, a);
	int i = 0, level=0;
	while (i <= a.size()) {
		if (level == 0 && a[i] == 'U') {
			level = 1;
		}
		if (level == 1 && a[i] == 'C') {
			level = 2;
		}
		if (level == 2 && a[i] == 'P') {
			level = 3;
		}
		if (level == 3 && a[i] == 'C') {
			level = 4;
			break;
		}
		i++;
	}

	if (level == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";

	return 0;
}