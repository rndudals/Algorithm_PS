#include<iostream>
using namespace std;

int N, M;
int arr[2001];
int dp[2001][2001];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= N-1; i++) { // 한칸차이가 될 수 있으므로 예외처리! 
		if (arr[i]==arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = i; j <= N; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
			}
		}
	}

	
	cin >> M;
	for (int j = 0; j < M; j++) {
		int start, end;
		cin >> start>>end;
		cout << dp[start][end] << '\n';
	}

	return 0;
}