#include <iostream>
using namespace std;


int dp[1001];
int n;

/*
	dp �޸����̼� ����Լ��� Ǯ��
*/

int func(int N) {
	if (dp[N] != 0) { return dp[N]; }
	if (N == 1) { return dp[N]=1; }
	if (N == 2) { return dp[N]=2; }
	return dp[N]=(func(N - 1) + func(N - 2))%10007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	cout << func(n);
	return 0;
}