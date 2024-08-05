#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int N, L, R;
int arr[50][50];
bool visited[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int out = 0;

void bfs(int x, int y) {
	int sum = 0;
	int cnt = 0;
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ x,y });
	v.push_back({x, y});
	visited[x][y] = true;
	sum += arr[x][y];
	cnt++;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int diff = abs(arr[cx][cy] - arr[nx][ny]);
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (diff < L || diff > R) continue;
			q.push({ nx, ny });
			v.push_back({ nx, ny });
			visited[nx][ny] = true;
			sum += arr[nx][ny];
			cnt++;
		}
	}
	
	
	for (int i = 0; i < v.size(); i++) {
		arr[v[i].first][v[i].second] = sum / cnt;
	}
	if (v.size() > 1) {
		out = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int ans = 0;
	
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	while (1) {
		
		memset(visited, 0, sizeof(visited));
		out = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
				}
			}
		}
		if (out == 1) {
			break;
		}
		ans++;
	}
	cout << ans;
	return 0;
}
