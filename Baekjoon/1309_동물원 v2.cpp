#include <iostream>
using namespace std;



int N;
int dp[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	cin >> N;
	
	dp[1][0] = 1; // ���� �ƹ��� ���� ��
	dp[1][1] = 1; // ���ڰ� ���ʿ��� ���� ��
	dp[1][2] = 1; // ���ڰ� �����ʿ��� ���� ��

	for (int i = 2; i <= N; i++) {
		// ���� ���� ���ڰ� ���� ���
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;

		// ���� ���� ���ڰ� ���ʸ� ���� ���
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;

		// ���� ���� ���ڰ� �����ʿ��� ���� ���
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}
	cout << (dp[N][0]+ dp[N][1] + dp[N][2])%9901;

	return 0;
}