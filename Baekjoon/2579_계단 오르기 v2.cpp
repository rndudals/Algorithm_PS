#include <iostream>
using namespace std;


int dp[301];
int N;
int arr[301];
/*
	dp 메모제이션 재귀함수로 풀기
*/
int func(int idx) {
	if (dp[idx] != 0) return dp[idx];
	if (idx == 0)return dp[idx] = 0;
	if (idx == 1) return dp[idx] = arr[1];
	if (idx == 2) return dp[idx] = arr[1] + arr[2];
	return dp[idx] = arr[idx] + max(arr[idx - 1] + func(idx - 3), func(idx - 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cout << func(N);
	return 0;
}