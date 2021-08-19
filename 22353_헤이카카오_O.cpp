#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;
vector <double> v(1000000);

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, d;
	double k, i = 1;
	cin >> a >> d >> k;

	v[0] = d;
	while (1) {
		v[i] = v[i - 1] + v[i - 1] * (k / 100);
		if (v[i] >= 100) {
			v[i] = 100;
			break;
		}
		i++;
	}

	for (int j = 0; j <= i; j++) v[j] /= 100;
	// cout << "\n";

	double res = 0;
	double p; 
	double time = a;

	res += time * v[0];
//	printf("처음res: %lf\n", res);

	for (int j = 1; j <= i; j++) {
		time += a;
		p = 1;
		for (int t = 0; t < j; t++) {
			p *= (1 - v[t]);
		}
	//	printf("%d 번째 p : %lf, time:%lf, v[]:%lf \n", j, p, time, v[j]);
		res += p * time * v[j];
		
	}

	printf("%.8lf\n", res);
//	cout << res;

	return 0;
}