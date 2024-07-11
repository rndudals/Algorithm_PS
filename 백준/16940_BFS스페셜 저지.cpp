#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[100001];
int order[100001];
vector <vector<int>> graph;
int arr[100001];
int N;
int ans;

bool cmp(const int & a, const int &b) { // ������ �켱���� �������� ����
	return order[a] < order[b];
}

void bfs(int start, int idx) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (next == arr[idx+1]) { // ���������� ������
				q.push(next);
				idx++;
			}
		}
	}
	if (idx == N) { // ������ ���� ��쿡 ���� ���
		ans = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> N;
	graph.resize(100001);
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		order[arr[i]] = i; // ������ �켱����
	}
	for (int i = 1; i <= N; i++) { // �� ���� �������ֱ�
		sort(graph[i].begin(), graph[i].end(), cmp);
	}
	
	bfs(1, 1);

	if (arr[1] != 1) { ans = 0; } // ���������� 1�� �ƴ� ���
	cout << ans;
	return 0;
}