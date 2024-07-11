#include <iostream>
using namespace std;

int N, M;
int arr[50][50];
int ans = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < M; j++) {
			arr[i][j] = st[j]- '0';
		}
	}
	int max_size = min(N, M);
	int cur_size = 0;
	while (1) {
		if (max_size - 1 == cur_size) { break; }
		cur_size++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int cnt = 0;
				int cur = arr[i][j];
				if (i + cur_size < N && arr[i + cur_size][j] == cur)cnt++;
				if (j + cur_size < M && arr[i][j + cur_size] == cur)cnt++;
				if (i + cur_size < N && j + cur_size < M && arr[i + cur_size][j + cur_size] == cur)cnt++;
				if (cnt == 3) ans = (cur_size + 1) * (cur_size + 1);
			}
		}
	}

	cout << ans;
	
	return 0;
}
