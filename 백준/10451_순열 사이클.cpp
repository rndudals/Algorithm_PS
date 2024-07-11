#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T ,N;
int answer;
vector<vector<int>> v;
bool visited[1001];

void func(int start, int cur) {
	visited[cur] = true;
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (next == start) { answer++;  return; }
		if (!visited[next]) {
			func(start, next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		v.resize(1001);
		memset(visited, 0, sizeof(visited));
		answer = 0;
		for (int i = 1; i <= N; i++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
		
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				func(i, i);
			}
		}
		v.clear();
		cout << answer << '\n';
	}
	
	
	return 0;
}