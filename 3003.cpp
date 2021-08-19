#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int input[6];
	for (int i = 0; i < 6; i++) {
		cin >> input[i];
	}
	cout << 1 - input[0] << " ";
	cout << 1 - input[1] << " ";
	cout << 2 - input[2] << " ";
	cout << 2 - input[3] << " ";
	cout << 2 - input[4] << " ";
	cout << 8 - input[5] << " ";

	

	return 0;
}