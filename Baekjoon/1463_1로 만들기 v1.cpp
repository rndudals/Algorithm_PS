#include <iostream>
#include <queue>
using namespace std;



int N;
int dist[1000001];

int bfs() {
	queue<int> q;
	dist[N] = 0;
	q.push(N);
	while (!q.empty()) {
		int cur = q.front();
		if (cur == 1) { break; }
		q.pop();
		
		if (dist[cur / 3]==-1 && (cur % 3 == 0)) {
			dist[cur / 3] = dist[cur] + 1;
			q.push(cur / 3);
		}
		if (dist[cur / 2] == -1 && (cur % 2 == 0)) {
			dist[cur / 2] = dist[cur] + 1;
			q.push(cur / 2);
		}
		if (dist[cur - 1] == -1 && cur - 1 >= 1) {
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
	}
	return dist[1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 1000000; i++) {
		dist[i] = -1;
	}
	
	cin >> N;

	cout<<bfs();
	
	
	return 0;
}