#include<iostream>
#include<vector>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> v;

	while (1) {
		v.push_back(n%9);   //해당 진수로 나눈 나머지를 vector에 넣음
		n /= 9;
		if (n == 0) break;
	}


	vector<int>::reverse_iterator iter;

	// 정방향 반복자라면  vector<int>::iterator iter;
	//						v.begin(); v.end();
	// 여기선 역방향 반복자 사용

	for (iter = v.rbegin(); iter != v.rend(); iter++) {
		cout << *iter;
	}


	return 0;
}