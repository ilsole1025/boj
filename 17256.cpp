#include<iostream>
#include<vector>
using namespace std;

struct cake {
	int x, y, z;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cake a, c;
	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;
	cout << c.x - a.z << " "; //c.x = a.z + b.x
	cout << c.y / a.y << " "; // c.y = a.y ¡¿ b.y
	cout << c.z - a.x << " "; // c.z = a.x + b.z

	return 0;
}