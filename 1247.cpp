#define MAX 9223372036854775807;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;
vector<long double>v;
void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	v.clear();
	long long tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	long long k = n / 2;
	long long j;
	long double sum = 0;
	printf("n:%d\n", n);
	if (n % 2 == 0) { //Â¦¼ö
		for (long long i = 0; i < k; i++) {
			j = n - i - 1;
			sum += v[i];
			sum += v[j];
			printf("%lld+%lld=%lld\n", v[i], v[j],sum);
		}
	}
	else { // È¦¼ö
		for (long long i = 0; i < k; i++) {
			j = n - i - 1;
			sum += v[i] + v[j];
			printf("Ã¼Å© i:%lld,j:%lld\n",i,j);
		}
		sum += v[k];
		printf("Ã¼Å© k:%lld\n",k);
	}
	if (sum == 0) cout << "0\n";
	else if (sum > 0) cout << "+\n";
	else cout << "-\n";

}
int main() {
	int t = 3;
	while (t--) solve();
	return 0;
}