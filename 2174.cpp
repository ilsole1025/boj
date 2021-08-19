#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

int a, b, n, m;
struct pos {
	int num; // 로봇 넘버
};
pos map[101][101]; //로봇이 어느 위치에 있는지 보기(실제크기:axb)
struct robot {
	int num;
	int dir; // 동서남북 NWSE 1234
	int x, y; //위치...
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
		map[x-1][y-1].num = i + 1; //로봇 넘버

		if(dir == 'N') tmpdir = 1; // 방향
		if (dir == 'W') tmpdir = 2;
		if (dir == 'S') tmpdir = 3;
		if (dir == 'E') tmpdir = 4;

		robot tmp = { i + 1, tmpdir, x-1, y-1 };
		v.push_back(tmp); //로봇 관리..
	}



	int rbt; char cmd; int rpt;

	for (int i = 0; i < m; i++) {
		cin >> rbt >> cmd >> rpt;
		if (cmd == 'L') { // 좌측회전: 1→2, 2→3, 3→4, 4→1
			rpt %= 4;
			while (rpt--) {
				if (v[rbt - 1].dir <= 3) (v[rbt - 1].dir)++;
				else v[rbt - 1].dir = 1;
			}
		}
		else if (cmd == 'R') { // 우측회전: 4 > 3, 3 > 2 2→1, 1→4, 
			rpt %= 4;
			while (rpt--) {
				if (v[rbt - 1].dir >= 2) (v[rbt - 1].dir)--;
				else v[rbt - 1].dir = 4;
			}
		}
		else if (cmd == 'F') {
			// 충돌 발생시 is_carsh=1, 출력하고 종료하기
			/* 
			즉 한칸 옮길때마다 해줘야하는 것
제일 먼저 바뀔 위치 [x+1][y]가 1)인덱스 벗어나는지 
2)다른 로봇이 없는지 확인
→ 인덱스 벗어나면 1번 에러
→ 다른 로봇이 존재하면 (map[x+1][y].num ≠ 0) 2번 에러

v[].x, y에서 위치 x,y알아내서
map[x][y]를 0으로 바꾸고, 바뀐 위치 map[x+1][y]에다가 num새로 넣기
기존 v[].x,y는 새로 업데이트하기 (num과 dir은 바뀌지 않는다)
			*/
			while (rpt--) {
				x = v[rbt - 1].x; 
				y = v[rbt - 1].y;
				int dir = v[rbt - 1].dir;
				if (v[rbt - 1].dir == 1) { //위로
					if (y + 1 >= b) {
						print1(rbt); return 0;
					}
					else if (map[x][y + 1].num != 0) {
						print2(rbt, map[x][y + 1].num);
						return 0;
					}
					map[x][y + 1].num = map[x][y].num; // rbt와 같음
					map[x][y].num = 0;
					v[rbt - 1].y = y + 1;
				}
				else if (v[rbt - 1].dir == 2) { //왼쪽으로
					if (x - 1 < 0) {
						print1(rbt); return 0;
					}
					else if (map[x-1][y].num != 0) {
						print2(rbt, map[x-1][y].num);
						return 0;
					}
					map[x - 1][y].num = map[x][y].num; // rbt와 같음
					map[x][y].num = 0;
					v[rbt - 1].x = x - 1;
				}
				else if (v[rbt - 1].dir == 3) { //아래로
					if (y- 1 < 0) {
						print1(rbt); return 0;
					}
					else if (map[x][y - 1].num != 0) {
						print2(rbt, map[x][y - 1].num);
						return 0;
					}
					map[x][y - 1].num = map[x][y].num; // rbt와 같음
					map[x][y].num = 0;
					v[rbt - 1].y = y - 1;
				}
				else if (v[rbt - 1].dir == 4) { //우측으로
					if (x + 1 >= a) {
						print1(rbt); return 0;
					}
					else if (map[x + 1][y].num != 0) {
						print2(rbt, map[x + 1][y].num);
						return 0;
					}
					map[x + 1][y].num = map[x][y].num; // rbt와 같음
					map[x][y].num = 0;
					v[rbt - 1].x = x + 1;
				}
				else cout << "방향 에러\n";
			}
		}
		else cout << "뭔가 에러있음\n";
	}

	cout << "OK\n";

	return 0;
}