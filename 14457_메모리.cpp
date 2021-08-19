#include<iostream>
#include<vector>
#include<string>
#include<tuple>
using namespace std;

int r, c;
int time;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	cout << (r*c / 2)<<" ";
	cout << (r*c - 1);
	return 0;
}