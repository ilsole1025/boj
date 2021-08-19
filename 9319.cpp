#define MAX 100000
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t, n, B, x, y;
int xi[MAX + 5];
int yi[MAX + 5];
int si[MAX + 5];

double dist(const double& x1, const double& y1,
	const double& x2, const double& y2) {
	double x_diff = abs(x2 - x1);
	double y_diff = abs(y2 - y1);
	return x_diff*x_diff + y_diff * y_diff; //Á¦°öÇÑ°Å
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> B;
	cin >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> xi[i] >> yi[i] >> si[i];
	}

	double totalSum = 0;
	for (int j = 1; j <= n; j++) {
		totalSum += (si[j] / dist(x, y, xi[j], yi[j]));
	}
	double sum;
	for (int i = 1; i <= n; i++) {
		double ri = si[i] / dist(x, y, xi[i], yi[i]);
		double sum = totalSum - ri;
		if ( ri > 6 * (B + sum)) {
			cout << i << "\n";
			return;
		}
	}
	cout << "NOISE" << "\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}