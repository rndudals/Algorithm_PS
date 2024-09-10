#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> node[1001];
vector<pair<pair<long long, long long>, long long>> v;
int N;
long long parent[1001];
bool cmp(pair<pair<long long, long long>, long long>& A, pair<pair<long long, long long>, long long>& B) {
	return A.second < B.second;
}

void distanceCheck() {
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			long long x = node[i].first - node[j].first;
			long long y = node[i].second - node[j].second;
			long long L2 = x * x + y * y;
			v.push_back({ { i,j }, L2 });
		}
	}
	sort(v.begin(), v.end(), cmp);
}

int getParent(int x) {
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> node[i].first;
		}
		for (int i = 1; i <= N; i++) {
			cin >> node[i].second;
		}
		double E = 0;
		long long ans = 0;
		cin >> E;
		// 거리순 정렬
		distanceCheck();

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < v.size(); i++) {
			long long start = v[i].first.first;
			long long end = v[i].first.second;
			if (getParent(start) != getParent(end)) {
				ans += v[i].second;
				unionParent(start, end);
			}
		}
		cout << fixed;
		cout.precision(0);
		cout << "#" << test_case << " " << E * ans << '\n';
		v.clear();

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}