#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;


int N, M;
int map[51][51];
bool visited[51][51];
int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
vector<pair<int, int>>shark;
int dist[51][51];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	dist[x][y] = 0;
	
	q.push({ x,y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M) {
				if (dist[next_x][next_y] > dist[cur_x][cur_y] + 1) { // 과거의 기록보다 현재의 기록이 가까울 때
					q.push({ next_x,next_y });
					dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
				}
			}
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist[i][j] = 999999;
			int x;
			cin >> x;
			if (x == 1) { 
				shark.push_back({ i,j });
			}
			
		}
	}
	
	for (int i = 0; i < shark.size(); i++) { // 상어를 기준으로 bfs 실행
		bfs(shark[i].first, shark[i].second);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) { // 최댓값 찾기
		for (int j = 0; j < M; j++) {
			if (ans < dist[i][j]) {
				ans = dist[i][j];
			}
		}
	}
	cout << ans;

	return 0;
}