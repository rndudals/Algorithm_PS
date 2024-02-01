#include <iostream>
using namespace std;


int dp[1001];
int n;

/*
	DP�̿�
	dp[i-1] : i-1�� dp���� 2x1 Ÿ�� �߰�
	dp[i-2] : i-2�� dp���� 1x2 Ÿ�� �ΰ� �߰�
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	cout << dp[n];
	return 0;
}