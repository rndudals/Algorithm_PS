#include <iostream>
using namespace std;

int dp[301];
int N;
int arr[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1]+arr[2];
    /*
    arr[i - 1] + dp[i - 3] : ¹Ù·Î Àü °è´Ü + 3Ä­Àü±îÁöÀÇ ÃÖ´ñ°ª(i-2¹øÂ° Ä­ Á¡ÇÁ)
    dp[i-2] : i-2¹øÂ°Ä­ ±îÁöÀÇ ÃÖ´ñ°ª(i-1¹øÂ° Ä­ Á¡ÇÁ)
    */
	for (int i = 3; i <= N; i++) {
		dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
	}

	cout << dp[N];

	return 0;
}