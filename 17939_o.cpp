
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
	
	vector<int> price, p2;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		price.push_back(tmp);
	}

	// 각 시점에 대해서 오른쪽에 있는 것중에 제일 비싼 시점에서 팔기

	// 오른쪽에서 쫙..훑으면서 그 시점까지의 최대 가격 갱신
	int M[100001];
	int max = price[n-1];
	for (int i = n - 1; i >= 0; i--) {
		if (max < price[i]) max = price[i];
		M[i] = max;
	}
	
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		ans += (M[i] - price[i]);
	}

	cout << ans;

	return 0;
}