#include <iostream>
#include <map>
using namespace std;


int N, M, x;
int dp[101][10];
map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		m[x] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		if (m[x] == 1) {
			cout << "1"<<" ";
		}else {
			cout << "0"<<" ";
		}
	}
	
	return 0;
}