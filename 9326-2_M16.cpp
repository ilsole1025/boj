#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
#include<cmath>
typedef long long ll;
using namespace std;

ll t;
ll num;
map<int, int> temp;
vector<int> res;

void DIV(ll k, ll x) {
	while (x != 1) {
		if (x%k == 0) {
			if (temp.find(k) == temp.end()) {
				temp.insert(pair<int, int>(k, 1));
			}
			else {
				(temp[k])++;
			}
			x /= k;
		}
		else {
			k++;
			if (k >= 4) k++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		temp.clear();
		res.clear();
		cin >> num;
		DIV(2, num);

		vector<pair<int, int>> v(temp.begin(), temp.end());
		sort(v.begin(), v.end(), [](pair<int, int>a, pair<int, int>b) {
			return a.second > b.second;
		});
		

		for (pair<int, int> it : v) {
			int n = it.first;
			int cnt = it.second;
			cout << n << " " << cnt << "\n";
			if (cnt == 1) {
				res.push_back(n);
				it.second = 0;
			}
			else if (cnt == (cnt&-cnt)) {
				//cnt´Â 2ÀÇ °ÅµìÁ¦°öÀÌ´Ù
				res.push_back(pow(n, cnt));
				it.second = 0;
			}
			else {

			}
		}
		
		for (auto i : res) {
			cout << res[i] << " ";
		}
		cout << "\n\n";
	}

	return 0;
}