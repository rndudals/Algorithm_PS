#include <iostream>
#include <deque>
#include <string.h>
using namespace std;


//int visited[101][101];
int dist[101][101];
int M, N;
char map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void bfs_01() { // 01bfs알고리즘 이용!
	deque<pair<int, int>> dq;
	dq.push_back({ 1,1 });
	dist[1][1] = 0;
	while (!dq.empty()) {
		int cur_x = dq.front().first;
		int cur_y = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			
			if (next_x<1 ||  next_y<1 || next_x>N || next_y>M) { continue; }
			if (dist[next_x][next_y] != -1) { continue; }

			if (map[next_x][next_y]=='0') { // 벽이 아닐 때
				dist[next_x][next_y] = dist[cur_x][cur_y];
				dq.push_front({ next_x, next_y });
			}
			else { // 벽일 때
				dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
				dq.push_back({ next_x, next_y });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	
	bfs_01();
	
	cout << dist[N][M];
	return 0;
}