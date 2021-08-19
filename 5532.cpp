typedef long long ll;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int kor = ceil((double)a / (double)c);
	int math = ceil((double)b / (double)d);

	cout << l - max(kor, math);

	return 0;
}