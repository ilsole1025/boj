#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	// 6번이면.. 가로 4로 나눠서 몫인 1이 위치고 나머지 2가 
	cout << k / m <<" "<< k % m;

	return 0;
}