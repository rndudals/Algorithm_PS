#include <iostream>
using namespace std;

int ans;
int T;
int map[100][100];
int a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >>T;
	while (T--) {
		cin >> a >> b;
		for (int i = a; i < a + 10; i++) {
			for (int j = b; j < b + 10; j++) {
				if (map[i][j] == 1) continue;
				map[i][j]++;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			ans +=map[i][j];
		}
	}
	cout << ans;
	return 0;
}