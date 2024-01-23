#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int, int>>> v;

struct K {
	int x, y, z;
} arr[100000];
int N;
int parent[100000];
int ans;
vector<pair<int, int>>X;
vector<pair<int, int>>Y;
vector<pair<int, int>>Z;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
	}

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}

int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = getParent(parent[x]);
	}
}

void unionNode(int a, int b) {
	if (a > b)swap(a, b);
	parent[getParent(b)] = getParent(a); // b의 부모가 a가 되어야한다
}
void run() {
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	for (int i = 0; i < N - 1; i++) {
		v.push_back({ X[i + 1].first - X[i].first , {X[i].second, X[i + 1].second} });
		v.push_back({ Y[i + 1].first - Y[i].first , {Y[i].second, Y[i + 1].second} });
		v.push_back({ Z[i + 1].first - Z[i].first , {Z[i].second, Z[i + 1].second} });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		int distance = v[i].first;
		if (getParent(a) != getParent(b)) {
			ans += distance;
			unionNode(a, b);
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	run();
	
	return 0;
}