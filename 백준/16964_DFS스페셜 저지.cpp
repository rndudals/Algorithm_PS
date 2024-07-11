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
int cnt=1;
bool cmp(const int & a, const int &b) { // ������ �켱���� �������� ����
	return order[a] < order[b];
}

void dfs(int cur) {
	if (cnt == N) { // ������ ���� ��쿡 ���� ���
		ans = 1;
		return;
	}
	
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (next == arr[cnt+1]) {
			cnt++;
			dfs(next);
		}
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
	
	dfs(1);

	if (arr[1] != 1) { ans = 0; } // ���������� 1�� �ƴ� ���
	cout << ans;
	return 0;
}