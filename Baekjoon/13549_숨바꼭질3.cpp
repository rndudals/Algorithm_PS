#include <iostream>
#include <queue>
#include <string.h>
using namespace std;


int visited[100001];

void bfs(int N, int K) {
	// ���� ���� �ð��� ã�� ���̹Ƿ� �켱����ť�� �����Ѵ�
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push(make_pair(0, N));
	visited[N] = 0;
	while (!pq.empty()) {
		int time = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();


		// �̵��ϱ�
		if (2 * cur_node <= 100000 && visited[2 * cur_node] == -1) {
			pq.push(make_pair(time, 2 * cur_node));
			visited[2 * cur_node] = visited[cur_node];
		}

		if (cur_node + 1 <= 100000 && visited[cur_node + 1] == -1) {
			pq.push(make_pair(time + 1, cur_node + 1));
			visited[cur_node + 1] = visited[cur_node] + 1;
		}
		if (cur_node - 1 >= 0 && visited[cur_node - 1] == -1) {
			pq.push(make_pair(time + 1, cur_node - 1));
			visited[cur_node - 1] = visited[cur_node] + 1;
		}

		if (cur_node == K) { break; }
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(visited, -1, sizeof(visited));
	int N;
	int K;

	cin >> N >> K;

	bfs(N, K);

	cout << visited[K] << '\n';
	return 0;
}