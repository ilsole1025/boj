#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void solve() {
	double h, m, s;
	cin >> h >> m >> s;
	double oa, ob, oc;
	// ��ħ 12�ð��� 360��
	// 60�п� �߰� 30����, 1�п� 0.5��
	// 60��*60�п� �߰� 30����, 1�ʿ� 30/3600��
	oa = 30 * h + ((double)1/ (double)2) * m + ((double)30 / (double)3600)*s;
	// ��ħ�� 60�п� 360��
	// ��ħ�� 1�п� 360���� ����. �� 1�ʿ� 6����.
	ob = m * 6 + ((double)1/10) * s;
	// ��ħ��.. 1�ʿ� 6���� ����
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
	// double�� ����ϸ� Ʋ�Ƚ��ϴ� �� ����..
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}