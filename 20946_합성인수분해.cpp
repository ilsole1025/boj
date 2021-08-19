#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
typedef long long ll;
using namespace std;

ll n;

bool isPrime(ll a) {
	if (a == 2 || a == 3 || a == 5 || a == 7) return true;
	if (a % 2 == 0 || a == 1 || a == 9) return false;
	if (!(a & 1)) { return false; }
	ll range = a / 3;
	unsigned pos = 3;
	while (pos <= range) {
		if (!(a % pos) || !(a % (pos + 2))) { return false; }
		pos += 4;
		range = a / pos;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	clock_t start = clock();
	if (isPrime(n)) { cout << "-1"; return 0; }

	ll origN = n;
	vector<ll> res; //���μ�����


	if (origN == 4) { //�Ʒ��ڵ忡�� ��Ÿ�ӿ�����;
		cout << 4;
		return 0;
	}

	ll k = 2;
	while (n != 1 && k*k <= origN) {
		if (n % k == 0) {
			res.push_back(k);
			n /= k;
		}
		else if (k == 2) {
			k++;
		}
		else {
			k += 2;
		}
	}
	
	if(n != 1 && isPrime(n)) 
		res.push_back(n); //���� k*k<=N �������� ��ó �� �� ���� ���

	// printf("n:%lld, k:%lld\n", n, k);
	// for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	// cout << "\n";

	ll nowN = 1;
	int idx = 0;
	vector<ll> ans;

	while (nowN < origN) {
		if (res.size() == 1) {
			ans.push_back(res[0]);
			nowN *= res[0];
		}
		if (idx + 1 == res.size()) { // idx��ġ�� �������̴�
			ans.back() *= res[idx]; // �������ſ� �����ֱ�
			nowN *= res[idx];
		}
		else { // idx�� idx+1�� �� �� �ִ�
			ll tmp = res[idx] * res[idx + 1];
			ans.push_back(tmp);
			nowN *= tmp;
			idx += 2;
		}
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}