#include <iostream>
using namespace std;


int N, K;
int dp[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N>> K ;
	for (int i = 0; i <= N; i++) { // 숫자를 하나 썼을 때 나올 수 있는 경우의 수
		dp[1][i] = 1;
	}
	for (int i = 1; i <= K; i++) {
		dp[i][0] = 1;
	}
	for (int i = 2; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] =(dp[i][j-1] + dp[i - 1][j])%1000000000;
		}
	}

	cout << dp[K][N];
	return 0;
}