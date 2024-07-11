#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[10][10];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[10][10][10][10];
int ans;

struct K {
	int x, y;
};

K r;
K b;


void Input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < M; j++) {
			map[i][j] = st[j];
			if (st[j] == 'B') { b.x = i; b.y = j; }
			if (st[j] == 'R') { r.x = i; r.y = j; }
		}
	}
}

void move(int& rx, int& ry, int& d, int& i) {
	while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O') { // 다음이 벽의 끝이 아니면 이동
		rx += dx[i];
		ry += dy[i];
		d += 1;
	}
}


void bfs() {
	queue<pair<pair<int, int>, int>> red_q;
	queue<pair<int, int>> blue_q;
	visited[r.x][r.y][b.x][b.y] = true;
	red_q.push({ { r.x, r.y }, 0 });
	blue_q.push({ b.x, b.y });

	while (!red_q.empty()) {

		int r_cx = red_q.front().first.first;
		int r_cy = red_q.front().first.second;
		int cnt = red_q.front().second;

		int b_cx = blue_q.front().first;
		int b_cy = blue_q.front().second;
		if (cnt == 10) { return; }

		red_q.pop();
		blue_q.pop();
		for (int i = 0; i < 4; i++) {
			int r_nx = r_cx, r_ny = r_cy, b_nx = b_cx, b_ny = b_cy;
			int rd = 0, bd = 0;

			move(r_nx, r_ny, rd, i); // 빨간색 이동
			move(b_nx, b_ny, bd, i); // 파란색 이동

			if (map[b_nx][b_ny] == 'O')continue; // 파란색이 빠졌을 때

			if (map[r_nx][r_ny] == 'O') { ans = cnt + 1; return; } // 빨간색만 빠졌을 때

			if (r_nx == b_nx && r_ny == b_ny) { // 겹치는 부분 처리
				if (rd > bd) {
					r_nx -= dx[i], r_ny -= dy[i];
				}
				else {
					b_nx -= dx[i], b_ny -= dy[i];
				}
			}

			if (visited[r_nx][r_ny][b_nx][b_ny]) continue;
			visited[r_nx][r_ny][b_nx][b_ny] = true;
			red_q.push({ {r_nx, r_ny}, cnt + 1 });
			blue_q.push({ b_nx, b_ny });

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	bfs();
	if (ans == 0) { ans = -1; }
	cout << ans;
	return 0;
}