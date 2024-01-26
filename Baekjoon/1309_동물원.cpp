#include <iostream>
using namespace std;



int N;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[0] = 1;
	dp[1] = 3;
	
	cin >> N;
	/*
		2 * dp[i - 1] : i-1가 10일 때 01, 00 가능
						i-1가 01일 때 10, 00 가능
						i-1가 00일 때 10, 01, 00 가능-> 여기서 00은 i-2가 00일 때만 추가 가능

		dp[i-2] : (i-2)번째에 있는 개수 만큼 00이 생기므로
	*/
	for (int i = 2; i <= N; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2])%9901;
	}
	cout << dp[N];

	return 0;
}