#include <iostream>
using namespace std;


int dp[1001];
int n;

/*
	DP이용
	dp[i-1] : i-1의 dp에서 2x1 타일 추가
	dp[i-2] : i-2의 dp에서 1x2 타일 두개 추가
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