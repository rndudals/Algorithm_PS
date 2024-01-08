#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
int n;
int tree[20001][2];
vector<int> row[10002];
int r=1;
int parent[10001];
bool visited[10001];

int findRoot() { // 루트를 찾아주는 함수
	bool find = false;
	int node=0;
	for (int i = 1; i < 10001; i++) {
		if (visited[i]) {
			node = i;
			while (parent[node] != 0) {
				node=parent[node];
			}
			find = true;
		}
		if (find) { break; }
	}


	return node ;
}

void func(int node, int depth) { // 중위순회하며 행, 열을 정해주는 함수
	if (node == -1) { return; }
	func(tree[node][0], depth + 1);
	row[depth].push_back(r);
	r++;
	
	func(tree[node][1], depth + 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		visited[n] = true;
		cin >> tree[n][0] >> tree[n][1];
		parent[tree[n][0]] = n;
		parent[tree[n][1]] = n;
	}
	
	
	func(findRoot(), 1);


	int ans = 0;
	int ans_depth = 0;
	for (int i = 1; i < 10002; i++) {
		int M = 0;
		int m = 987654321;

		for (int j = 0; j < row[i].size(); j++) {
			if (row[i][j] > M) {  M= row[i][j]; } // 열 최댓값 찾기
			if (row[i][j] < m) { m= row[i][j]; } // 열 최솟값 찾기
		}

		if (ans < M - m + 1) { // 최대 길이와 그때의 레벨 찾기
			ans = M - m + 1;
			ans_depth = i;
		}
	}
	cout <<ans_depth<< " " <<ans;
	return 0;
}