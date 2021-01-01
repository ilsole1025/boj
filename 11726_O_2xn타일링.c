#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	long long int a[1005];

	a[1] = 1; a[2] = 2;

	for (int i = 3; i <= n; i++) {
		a[i] = (a[i - 1] + a[i - 2])%10007;
		// 숫자가 크기 때문에 오버플로우 일어나지 않게, 계산하면서 나머지를 취해줘야 한다.
	}

	//a[n] %= 10007;

	printf("%lld\n", a[n]);

	return 0;
}