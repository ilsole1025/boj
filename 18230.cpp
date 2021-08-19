#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int n, a, b;
vector<int> A;
vector<int> B;
struct tile {
	int sum=0;
	int idx1=0;
	int idx2=0;
};
tile ans[2002];

void solve(int x) {
	if (x == 1) {
		ans[1].sum = A[ans[1].idx1];
		ans[1].idx1++;
	}
	else if (x == 2) {
		// B가 비어있을경우: 1+1만 가능
		// A가 비어있을 경우: B값 하나로 결정
		// B가 안 비어있을경우: 1+1과 0+2 둘다 가능

		if (B.empty()) {
			ans[2].sum = A[0] + A[1];
			ans[2].idx1 += 2;
		}
		else if (A.empty()) {
			ans[2].sum = B[0];
			ans[2].idx2 += 1;
		}
		else {
			int a1 = A[0] + A[1];
			int a2 = B[0];
			if (a1 > a2) {
				ans[2].sum = A[0] + A[1];
				ans[2].idx1 += 2;
			}
			else {
				ans[2].sum = B[ans[2].idx2];
				ans[2].idx2++;
			}
		}
	}
	else if (A.empty() && !B.empty()) {
		// A 비어있음, B만 사용
		ans[x].sum = ans[x - 2].sum + B[ans[x - 2].idx2];
		ans[x].idx1 = ans[x - 2].idx1;
		ans[x].idx2 = ans[x - 2].idx2 + 1;
	}
	else if (!A.empty() && B.empty()) {
		// B만 비어있음
		ans[x].sum = ans[x - 1].sum + A[ans[x - 1].idx1];
		ans[x].idx1 = ans[x - 1].idx1 + 1;
		ans[x].idx2 = ans[x - 1].idx2;
	}
	else {
		int a1 = ans[x - 1].sum + A[ans[x-1].idx1];
		int a2 = ans[x - 2].sum + B[ans[x-2].idx2];

		if (a1 > a2) {
			ans[x].sum = a1;
			ans[x].idx1 = ans[x - 1].idx1 + 1;
			ans[x].idx2 = ans[x - 1].idx2;
		}
		else {
			ans[x].sum = a2;
			ans[x].idx1 = ans[x - 2].idx1;
			ans[x].idx2 = ans[x - 2].idx2 + 1;
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> a >> b;
	
	int tmp;
	for (int i = 0; i < a; i++) {
		cin >> tmp; A.push_back(tmp);
	}
	for (int i = 0; i < b; i++) {
		cin >> tmp; B.push_back(tmp);
	}
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 1; i <= n; i++) {
		solve(i);
	}

	for (int i = 1; i <= n; i++) {
	//	printf("%d (%d %d)\n", ans[i].sum, ans[i].idx1, ans[i].idx2);
	}

	cout << ans[n].sum << "\n";


	return 0;
}