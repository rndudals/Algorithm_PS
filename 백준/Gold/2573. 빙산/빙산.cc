#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int map[301][301];
int ans;
int minus_arr[301][301];
int visited[301][301];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void melt() {
	memset(minus_arr, 0, sizeof(minus_arr));
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (map[i][j] != 0) {
				if (map[i - 1][j] == 0) { minus_arr[i][j]++; }
				if (map[i + 1][j] == 0) { minus_arr[i][j]++; }
				if (map[i][j - 1] == 0) { minus_arr[i][j]++; }
				if (map[i][j + 1] == 0) { minus_arr[i][j]++; }
			}
		}
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (map[i][j] != 0) {
				map[i][j] = max(0, map[i][j] - minus_arr[i][j]);
			}
		}
	}
}

bool complete() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
	
	if (cnt == N * M) {
		ans = 0;
		return true;
	}
	else return false;
}

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N - 1 || ny > M - 1) continue;
		if (!visited[nx][ny] && map[nx][ny] != 0) {
			dfs(nx, ny);
		}
	}
}

bool check() {
	if (complete()) { return true; }
	memset(visited, 0, sizeof(visited));

	int cnt = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (visited[i][j] == false && map[i][j] != 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	if (cnt >= 2) { return true; }
	else { return false; }
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
	while (1) {
		if (check()) { break; }
		ans++;
		melt();
	}
	
	cout << ans;
	return 0;
}
