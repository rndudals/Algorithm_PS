#include <iostream>
using namespace std;


int N;
int dp[1001][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N ;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N;i++) {
		dp[i][0] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%10007;
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans= (ans + dp[N][i])%10007;
	}
	cout << ans;
	return 0;
}