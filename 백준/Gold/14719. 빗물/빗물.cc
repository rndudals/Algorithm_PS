#include <iostream>
#include <queue>
using namespace std;

int H, W;
int arr[501];
int map[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;

	for (int i = 1; i <= W; i++) {
		cin >> arr[i];
	}
	for (int j = 1; j <= W; j++) {
		for (int i = 1; i <= H; i++) {
			if (i <= arr[j]) {
				map[i][j] = 1;
			}
		}
	}
	

	int ans = 0;
	for (int i = 1; i <= H; i++) {
		int on = 0;
		int cnt = 0;
		for (int j = 1; j <= W; j++) {
			if (on == 0) {
				if (map[i][j] == 1 && map[i][j+1] == 0) {
					on = 1;
					cnt = 0;
				}
			}
			else { // on == 1
				if (map[i][j] == 1) {
					ans += cnt;
					on = 0;
					j--;
				}
				else { // map[i][j] == 0
					cnt++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}