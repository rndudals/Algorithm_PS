#include <iostream>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
using namespace std; 



int N;
bool visited[101][101];
int dist[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[101][101];




int bfs(int x, int y, int cnt) { // 01bfs를 이용하여 최소 다리를 계산
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	dist[x][y] = 0;
	deque<pair<int, int>> dq;
	dq.push_back({x, y});
	visited[x][y] = true;
	while (!dq.empty()) {
		int cur_x = dq.front().first;
		int cur_y = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x<1 || next_y<1 || next_x>N || next_y > N) { continue; }

			if (!visited[next_x][next_y]) { // 같은 섬이면 deque의 앞에 넣어줍니다.
				if (map[next_x][next_y] == cnt) {
					visited[next_x][next_y] = true;
					dq.push_front({ next_x,next_y });
					dist[next_x][next_y] = 0;
				}
				else if (map[next_x][next_y] == 0) { // 바다면 deque의 뒤에 넣어줍니다.
					visited[next_x][next_y] = true;
					dq.push_back({ next_x,next_y });
					dist[next_x][next_y] = dist[cur_x][cur_y]+1;
				}
				else {
					return dist[cur_x][cur_y];
				}
				
			}
		}
	}
	
}

void makeGroup(int x, int y, int cnt) { // 섬을 그룹별로 묶어줍니다.
	queue<pair<int, int>> q;
	visited[x][y] = true;
	map[x][y] = cnt;
	q.push({ x,y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x<1 || next_y<1 || next_x>N || next_y > N) { continue; }
			if (!visited[next_x][next_y] && map[next_x][next_y] == 1) {
				map[next_x][next_y] = cnt;
				visited[next_x][next_y] = true;
				q.push({ next_x,next_y });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dist, 0, sizeof(dist));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	memset(visited, 0, sizeof(visited));
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && map[i][j]==1) {
				makeGroup(i,j, cnt);
				cnt++;
			}
		}
	}

	cnt = 1;
	int ans = 987654;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == cnt) {
				ans = min(ans, bfs(i, j, cnt));
				cnt++;
			}
		}
	}
	cout << ans;


	return 0;
}