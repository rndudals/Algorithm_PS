#include <iostream>
using namespace std;

#define size 10000000

int N, M, x;
bool visited[20000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		visited[x+size] = true;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		if (visited[x+size]) {
			cout << "1"<<" ";
		}else {
			cout << "0"<<" ";
		}
	}
	return 0;
}