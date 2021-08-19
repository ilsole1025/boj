#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int E, EM, M, MH, H;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> E >> EM >> M >> MH >> H;
	
	int max = 0;
	while (1) {
		if (E >= 1) E--;
		else if (EM >= 1) EM--;
		else break;

		if (M >= 1) M--;
		else if (EM >= 1 || MH >= 1) {
			if (EM >= MH) EM--;
			else MH--;
		}// 왜째서 하나씩 하면 안 되는가...??
		else break;

		if (H >= 1) H--;
		else if (MH >= 1) MH--;
		else break;

		max++;
	}

	cout << max;
	return 0;
}