#include<iostream>
#include<vector>
#include<string>
#include<tuple>
using namespace std;

int n;
vector<pair<int, int>> v;
int time;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	for (int i = 0; i < n; i++) {
		a = v[i].first;
		b = v[i].second;

		if (i == 0) {
			time += b; //처음에는 무조건 기다려야 함
			time++; //이동하는데 1초 소요됨
			continue;
		}

		int tmp = time % (a + b);
	//	printf("\n현재 i:%d,a,b:%d,%d, tmp:%d,time:%d\n", i,a,b, tmp, time);
		if ( tmp < b) {
			// b는 봇 탐지시간
			// b - tmp만큼 기다려야 함
			time += (b - tmp);
	//		printf("기다려야 함/ time:%d\n", time);

			time++; // 이동하는데에는 1초가 걸림
		}
		else { 
			//봇이 쉬는시간: 바로 이동가능
	//		printf("바로이동/ time:%d\n", time);

			time++; // 이동하는데에는 1초가 걸림
		}


	}

	cout << time;

	return 0;
}