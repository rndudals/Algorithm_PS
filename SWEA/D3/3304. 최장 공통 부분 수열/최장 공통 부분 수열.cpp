#include<iostream>

using namespace std;

int ans;
int dp[1001][1001];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string a, b;
		cin >> a >> b;
		int sizeA = a.size();
		int sizeB = b.size();
		for (int i = 1; i <= sizeB; i++) {
			for (int j = 1; j <= sizeA; j++) {
				if (a[j-1] == b[i-1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				if (ans < dp[i][j]) {
					ans = dp[i][j];
				}
			}
		}
		
		cout << "#" << test_case <<" " << ans << '\n';
		ans = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}