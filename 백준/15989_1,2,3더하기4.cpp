#include <iostream>
using namespace std;

int ans;
int T;
int dp[10001][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	dp[1][1] = 1;
	dp[2][1] = 1; dp[2][2] = 1;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {

		dp[i][3] += dp[i - 3][1];
		dp[i][3] += dp[i - 3][2];
		dp[i][3] += dp[i - 3][3];

		dp[i][2] += dp[i - 2][1];
		dp[i][2] += dp[i - 2][2];

		dp[i][1] += dp[i - 1][1];
	}
	for (int i = 0; i < T; i++) {
		int a;
		cin >> a;
		cout << dp[a][1] + dp[a][2] + dp[a][3] << '\n';
	}
	return 0;
}