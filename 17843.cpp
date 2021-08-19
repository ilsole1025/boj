#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void solve() {
	double h, m, s;
	cin >> h >> m >> s;
	double oa, ob, oc;
	// 시침 12시간에 360도
	// 60분에 추가 30도씩, 1분에 0.5도
	// 60초*60분에 추가 30도씩, 1초에 30/3600도
	oa = 30 * h + ((double)1/ (double)2) * m + ((double)30 / (double)3600)*s;
	// 분침은 60분에 360도
	// 초침은 1분에 360도를 돈다. 즉 1초에 6도씩.
	ob = m * 6 + ((double)1/10) * s;
	// 초침은.. 1초에 6도씩 돈다
	oc = 6 * s;
//	cout << oa << " " << ob << " " << oc << endl;
	double a, b, c;
	if (oa > ob) a = oa - ob;
	else a = ob - oa;
	if (ob > oc) b = ob - oc;
	else b = oc - ob;
	if (oc > oa) c = oc - oa;
	else c = oa - oc;
//	cout << a << " " << b << " " << c << endl;

	if (a > 180) a = 360 - a;
	if (b > 180) b = 360 - b;
	if (c > 180) c = 360 - c;
	double min = 361;
	if (min > a) min = a;
	if (min > b) min = b;
	if (min > c) min = c;
//	cout << a << " " << b << " " << c << endl;
	printf("%.8f\n", min);
	// double로 출력하면 틀렸습니다 뜸 ㅎㅎ..
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}