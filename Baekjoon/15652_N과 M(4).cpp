#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void func(int cnt, int k) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (k <= i) {
			v.push_back(i);
			func(cnt + 1, i);
			v.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	func(0, 0);
	
	return 0;
}