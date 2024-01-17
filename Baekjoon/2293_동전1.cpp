#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int dp[10001];
int arr[100];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			if (arr[i] == j) {
				dp[j]++;
			}
			else {
				dp[j] = dp[j] + dp[j - arr[i]];
			}
		}
	}
	
	cout << dp[k];
	

	return 0;
}