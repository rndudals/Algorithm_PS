#include <iostream>
using namespace std;



int N;
int dp[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	cin >> N;
	
	dp[1][0] = 1; // 사자 아무도 없을 때
	dp[1][1] = 1; // 사자가 왼쪽에만 있을 때
	dp[1][2] = 1; // 사자가 오른쪽에만 있을 때

	for (int i = 2; i <= N; i++) {
		// 다음 줄의 사자가 없을 경우
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;

		// 다음 줄의 사자가 왼쪽만 있을 경우
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;

		// 다음 줄의 사자가 오른쪽에만 있을 경우
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}
	cout << (dp[N][0]+ dp[N][1] + dp[N][2])%9901;

	return 0;
}