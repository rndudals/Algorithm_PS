#include <iostream>
using namespace std;

int N, M;
char map[1000][1000];
bool visited[1000][1000];
int ans;

void dfs(int x, int y, char c) {
	visited[x][y] = true;
	// 상하좌우로 이동
	if (c == 'D' && x + 1 < N) {
		if (!visited[x + 1][y]) {dfs(x + 1, y, map[x + 1][y]);}
		else {
			if (map[x+1][y] == '1') {ans--;} // 다음이 Safe Zone에 이미 들어간 영역인 경우
		}
	}
	else if (c == 'U' && x - 1 >= 0) {
		if (!visited[x - 1][y]) {dfs(x - 1, y, map[x - 1][y]);}
		else {
			if (map[x - 1][y] == '1') {ans--;}
		}
	}
	else if (c == 'R' && y + 1 < M) {
		if (!visited[x][y + 1]) {dfs(x, y + 1, map[x][y + 1]);}
		else {
			if (map[x][y + 1] == '1') {ans--;}
		}
	}
	else if (c == 'L' && y - 1 >= 0) {
		if (!visited[x][y - 1]) {dfs(x, y - 1, map[x][y - 1]);}
		else {
			if (map[x][y - 1] == '1') {ans--;}
		}
	}
	map[x][y] = '1'; // Safe Zone에 이미 들어간 경우라고 체크
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				ans++;
				dfs(i, j, map[i][j]);
			}
		}
	}
	cout << ans;

	
	return 0;
}