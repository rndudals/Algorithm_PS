#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std; 



int N, M;
bool visited[3001];
int dist[3001];
vector<int> v[3001];
bool cycle;
int start_bfs;


void dfs(int cur, int cnt, int start) { // 순환을 찾아주는 함수
	visited[cur] = true;
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (next == start && cnt > 2) {
			cycle = true;
			dist[cur] = 0;
			start_bfs = next;
			return;
		}
		if (!visited[next] &&  cycle==false) {
			dfs(next, cnt + 1, start);
		}
	}
	if (cycle == true) { dist[cur] = 0; }
}


void bfs(int start) { // 비순환노드까지의 거리 계산
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				if (dist[next] == -1) {
					dist[next] = dist[cur] + 1;
				}
				q.push(next);
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}


	for (int i = 1; i <= N; i++) {
		cycle = false;
		memset(visited, 0, sizeof(visited));
		dfs(i,1, i); // 순환을 찾아주는 함수
		if (cycle == true) {
			break;
		}
	}
	
	bfs(start_bfs); // 비순환노드까지의 거리 계산

	for (int i = 1; i <= N; i++) {
		cout << dist[i] << '\n';
	}
	return 0;
}