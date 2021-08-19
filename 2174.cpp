#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int a, b, n, m;
struct pos {
	int num; // �κ� �ѹ�
};
pos map[101][101]; //�κ��� ��� ��ġ�� �ִ��� ����(����ũ��:axb)
struct robot {
	int num;
	int dir; // �������� NWSE 1234
	int x, y; //��ġ...
};
vector<robot> v;
void print1(int x) {
	cout << "Robot " << x << " crashes into the wall\n";
}
void print2(int x, int y) {
	cout << "Robot " << x << " crashes into robot " << y <<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> n >> m;
	int x, y; char dir; int tmpdir;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> dir;
		map[x-1][y-1].num = i + 1; //�κ� �ѹ�

		if(dir == 'N') tmpdir = 1; // ����
		if (dir == 'W') tmpdir = 2;
		if (dir == 'S') tmpdir = 3;
		if (dir == 'E') tmpdir = 4;

		robot tmp = { i + 1, tmpdir, x-1, y-1 };
		v.push_back(tmp); //�κ� ����..
	}



	int rbt; char cmd; int rpt;

	for (int i = 0; i < m; i++) {
		cin >> rbt >> cmd >> rpt;
		if (cmd == 'L') { // ����ȸ��: 1��2, 2��3, 3��4, 4��1
			rpt %= 4;
			while (rpt--) {
				if (v[rbt - 1].dir <= 3) (v[rbt - 1].dir)++;
				else v[rbt - 1].dir = 1;
			}
		}
		else if (cmd == 'R') { // ����ȸ��: 4 > 3, 3 > 2 2��1, 1��4, 
			rpt %= 4;
			while (rpt--) {
				if (v[rbt - 1].dir >= 2) (v[rbt - 1].dir)--;
				else v[rbt - 1].dir = 4;
			}
		}
		else if (cmd == 'F') {
			// �浹 �߻��� is_carsh=1, ����ϰ� �����ϱ�
			/* 
			�� ��ĭ �ű涧���� ������ϴ� ��
���� ���� �ٲ� ��ġ [x+1][y]�� 1)�ε��� ������� 
2)�ٸ� �κ��� ������ Ȯ��
�� �ε��� ����� 1�� ����
�� �ٸ� �κ��� �����ϸ� (map[x+1][y].num �� 0) 2�� ����

v[].x, y���� ��ġ x,y�˾Ƴ���
map[x][y]�� 0���� �ٲٰ�, �ٲ� ��ġ map[x+1][y]���ٰ� num���� �ֱ�
���� v[].x,y�� ���� ������Ʈ�ϱ� (num�� dir�� �ٲ��� �ʴ´�)
			*/
			while (rpt--) {
				x = v[rbt - 1].x; 
				y = v[rbt - 1].y;
				int dir = v[rbt - 1].dir;
				if (v[rbt - 1].dir == 1) { //����
					if (y + 1 >= b) {
						print1(rbt); return 0;
					}
					else if (map[x][y + 1].num != 0) {
						print2(rbt, map[x][y + 1].num);
						return 0;
					}
					map[x][y + 1].num = map[x][y].num; // rbt�� ����
					map[x][y].num = 0;
					v[rbt - 1].y = y + 1;
				}
				else if (v[rbt - 1].dir == 2) { //��������
					if (x - 1 < 0) {
						print1(rbt); return 0;
					}
					else if (map[x-1][y].num != 0) {
						print2(rbt, map[x-1][y].num);
						return 0;
					}
					map[x - 1][y].num = map[x][y].num; // rbt�� ����
					map[x][y].num = 0;
					v[rbt - 1].x = x - 1;
				}
				else if (v[rbt - 1].dir == 3) { //�Ʒ���
					if (y- 1 < 0) {
						print1(rbt); return 0;
					}
					else if (map[x][y - 1].num != 0) {
						print2(rbt, map[x][y - 1].num);
						return 0;
					}
					map[x][y - 1].num = map[x][y].num; // rbt�� ����
					map[x][y].num = 0;
					v[rbt - 1].y = y - 1;
				}
				else if (v[rbt - 1].dir == 4) { //��������
					if (x + 1 >= a) {
						print1(rbt); return 0;
					}
					else if (map[x + 1][y].num != 0) {
						print2(rbt, map[x + 1][y].num);
						return 0;
					}
					map[x + 1][y].num = map[x][y].num; // rbt�� ����
					map[x][y].num = 0;
					v[rbt - 1].x = x + 1;
				}
				else cout << "���� ����\n";
			}
		}
		else cout << "���� ��������\n";
	}

	cout << "OK\n";

	return 0;
}