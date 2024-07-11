#include <iostream>
#include <vector>
#include <string.h>
#include <set>
using namespace std;

int N;
int cnt = 1;
int v[101];
bool visited[101];
bool isRight;
set<int> ans;

void dfs(int start, int next) {
	if (visited[next]) { // next��� �湮������
		if (next == start) { // ���������� ���������� ������
			isRight = true;
			ans.insert(next);
			
		}
		return;
	}
	visited[next] = true;

	dfs(start, v[next]);

	if (isRight) {
		ans.insert(next);
	}
}

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= N; i++) {
		visited[i] = true;
		dfs(i, v[i]);
		isRight = false;
		memset(visited, 0, sizeof(visited));

	}
	
	cout << ans.size()<<'\n';
	for (auto o : ans) {
		cout << o << '\n';
	}
	return 0;
}