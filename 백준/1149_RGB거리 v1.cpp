#include <iostream>
using namespace std;

int arr[1000][3];
int dp[1000][3];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			}
			else if (j == 1) {
				dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			}
			else{
				dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
			}
		}
	}
	int ans = 987654321;
	for (int i = 0; i < 3; i++) {
		ans = min(ans, dp[N - 1][i]);
	}
	cout << ans;
	return 0;
}