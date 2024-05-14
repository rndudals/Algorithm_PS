#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
int x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			pq.push(x);
			if (pq.size() > N) {
				pq.pop();
			}
		}
	}
	
	cout << pq.top() << '\n';
	return 0;
}
