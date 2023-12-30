#include <iostream>
#include <vector>
using namespace std;

int N;
int oper[4];
int arr[12];
int M = -2000000000, m = 2000000000 ;
vector<int> v;
bool visited[401];


void go(int idx, int n) {
	if (idx == N - 1) {
		if (M < n) { M = n; }
		if (m > n) { m = n; }
		return ;
	}
	if (idx+1 < N) { // 다음 원소가 있으면 모든 연산자와 계산하기
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				if (!visited[i + 1]) {
					visited[i + 1] = true;
					go(idx + 1, n + arr[idx + 1]);
					visited[i + 1] = false;
				}
			}
			else if (v[i] == 1) {
				if (!visited[i + 1]) {
					visited[i + 1] = true;
					go(idx + 1, n - arr[idx + 1]);
					visited[i + 1] = false;
				}
			}
			else if (v[i] == 2) {
				if (!visited[i + 1]) {
					visited[i + 1] = true;
					go(idx + 1, n * arr[idx + 1]);
					visited[i + 1] = false;
				}
			}
			else {
				if (!visited[i + 1]) {
					visited[i + 1] = true;
					go(idx + 1, n / arr[idx + 1]);
					visited[i + 1] = false;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	int j = 0;
	while (j < 4) {
		if (oper[j] > 0) {
			oper[j]--;
			v.push_back(j);
		}
		else {
			j++;
		}

	}
	visited[0] = true;
	go(0, arr[0]);

	cout << M << '\n' << m;
	return 1;
}