/*
https://www.acmicpc.net/problem/1735
풀이 2019.06.15
언어 C
작성자 ilsole1025
*/

#include<stdio.h>

// 최대공약수 찾기
int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int A = (a * d) + (b * c); // 분자
	int B = b * d; //분모
	int i = gcd(A, B);
	A /= i; //약분된 분자
	B /= i; //약분된 분모
	
	printf("%d %d", A, B);

	return 0;
}
