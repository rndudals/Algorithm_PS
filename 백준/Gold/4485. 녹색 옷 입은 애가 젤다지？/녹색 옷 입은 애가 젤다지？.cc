#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int N;
int arr[125][125];
int dist[125][125];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = arr[0][0];
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (dist[nx][ny] > dist[cx][cy] + arr[nx][ny]) {
				dist[nx][ny] = dist[cx][cy] + arr[nx][ny];
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int cnt = 0;
	while (1) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = 100000;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		bfs();

		cout <<"Problem "<<++cnt<<": " << dist[N - 1][N - 1] << '\n';
	}
	return 0;
}