#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	long long int a[1005];

	a[1] = 1; a[2] = 2;

	for (int i = 3; i <= n; i++) {
		a[i] = (a[i - 1] + a[i - 2])%10007;
		// ���ڰ� ũ�� ������ �����÷ο� �Ͼ�� �ʰ�, ����ϸ鼭 �������� ������� �Ѵ�.
	}

	//a[n] %= 10007;

	printf("%lld\n", a[n]);

	return 0;
}