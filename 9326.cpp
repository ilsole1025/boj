#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
#include<cmath>
using namespace std;

int t;
long long num;
map<long long, int> temp;
vector<long long> res;

int list[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

void DIV(long long k, long long x) {
	while (x != 1) {
		if (x%k == 0) {
			if (temp.find(k) == temp.end()) {
				temp.insert(pair<long long, int>(k, 1));
			}
			else {
				(temp[k])++;
			}
			x /= k;
		}
		else {
			k++;
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
		map<int, int> visit;
		cin >> num;
		DIV(2, num);

		map<long long, int>::iterator iter;
		for (iter = temp.begin(); iter != temp.end(); iter++) {
			long long nnn = iter->first;
			int i = temp[nnn];

			if (visit.find(i) == visit.end()) { //if i not in visit
				visit.insert(pair<int, int>(i, 1));
				long long cnt = count(temp.begin(), temp.end(), i);
				if (cnt >= 2) {
					if (find(list,list+30, cnt) != list + 30) {
						res.push_back(pow(i, cnt));
					}
					else {
						int chk = 1;
						for (auto k : list) {
							if (k > cnt) {
								chk = k / 2;
								break;
							}
						}
						res.push_back(pow(i, chk));
						res.push_back(pow(i, cnt - chk));
					}
				}
			}
			else { //존재한다면
				(visit[i])++;
				res.push_back(i);
			}
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}