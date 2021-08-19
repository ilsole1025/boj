#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

/*
어떻게 하든지간에 풀 수는 있는 문제겠지.
근데 뭐가 제일 간단하고 빠른 방법일까..? 를 고민해야하는 지점 같다.
*/
long long int prime(long long n) {
	if (n == 2) return 2;
	if (n == 3) return 3;
	if (n == 1) return -1;
	if (n % 2 == 0) return -1;
	for (long long i = 5; i < sqrt(n); i += 2) {
		if (n % i == 0) 
			return -1;
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long int p, k;
	cin >> p >> k;
/* p는 두 소수의 곱으로 이루어져 있음
p를 2부터 k까지의 소수로 나눠보면서 나눠지면 BAD와 r을 출력한다.
k까지 나눴는데 안 끝났으면 good출력
*/
	if (p % 2 == 0) { //p==2인 경우는 문제조건에 없음
		cout << "BAD " << "2";
		return 0;
	}

	for (long long int i = 3; i < k; i += 2) {
		if (prime(i) != -1) { // 소수라면
			if (p % i == 0) {
				cout << "BAD " << i;
				return 0;
			}
		}
		else {
			// 소수 아니면 넘어감
		}
	}

	cout << "GOOD";

	return 0;
}