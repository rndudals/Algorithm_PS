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
bool cmp(const int & a, const int &b) { // 정답의 우선순위 기준으로 정렬
	return order[a] < order[b];
}

void dfs(int cur) {
	if (cnt == N) { // 정답대로 들어갔을 경우에 정답 출력
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
		order[arr[i]] = i; // 정답의 우선순위
	}
	for (int i = 1; i <= N; i++) { // 층 별로 정렬해주기
		sort(graph[i].begin(), graph[i].end(), cmp);
	}
	
	dfs(1);

	if (arr[1] != 1) { ans = 0; } // 시작지점이 1이 아닐 경우
	cout << ans;
	return 0;
}