#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cnt=1;
int tmp[100001];

vector <pair<int, int >> v;
vector<pair<int, int>> check;
bool visited[500001];

int binarySearch(int lo, int hi, int target) { // 이분탐색
	while (lo!=hi) {
		int mid = lo + (hi - lo) / 2;
		if (tmp[mid] >= target) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	
	tmp[0] = v[0].second;
	int tmp_idx =0;
	check.push_back({ v[0].second, 0 });
	for (int i = 1; i < N; i++) {
		if (tmp[tmp_idx] < v[i].second) { 
			tmp_idx++;
			cnt++;
			tmp[tmp_idx] = v[i].second; 
			check.push_back({ v[i].second, tmp_idx });

		}
		else { 
			int idx = binarySearch(0, tmp_idx, v[i].second); // 이분 탐색으로 시간 줄이기
			tmp[idx] = v[i].second; 
			check.push_back({ v[i].second, idx });
		}
		
	}
	cout << N-cnt<<'\n';
	
	int l = tmp_idx;

	for (int i = check.size() - 1; i >= 0; i--) { // 줄이 있는 것은 방문 체크
		if (check[i].second == l) {
			visited[check[i].first] = true;
			l--;
		}
	}
	for (int i = 0; i < v.size(); i++) { // 줄이 없으면 출력
		if (visited[v[i].second] == false) {
			cout << v[i].first<< '\n';
		}
	}

	return 0;
}