#include <iostream>
#include <string.h>
using namespace std; 



int N, M;
char map[50][50];
bool visited[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
string ans = "No";

void dfs(int x, int y, int start_x, int start_y, int cnt, char c) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x < 0 && next_y < 0 && next_x >= N && next_y >= N) { continue; }
		if (next_x == start_x && next_y == start_y && cnt + 1 >= 4) { // 순환!!
			ans = "Yes";
			return;
		}
		if (!visited[next_x][next_y] && c == map[next_x][next_y]) {
			dfs(next_x, next_y, start_x, start_y, cnt + 1, c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visited, 0, sizeof(visited));
			dfs(i, j, i, j, 1, map[i][j]); // 모든경우 탐색
		}
	}
	cout << ans;
	return 0;
}