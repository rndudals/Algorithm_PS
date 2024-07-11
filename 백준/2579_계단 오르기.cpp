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
    arr[i - 1] + dp[i - 3] : �ٷ� �� ��� + 3ĭ�������� �ִ�(i-2��° ĭ ����)
    dp[i-2] : i-2��°ĭ ������ �ִ�(i-1��° ĭ ����)
    */
	for (int i = 3; i <= N; i++) {
		dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
	}

	cout << dp[N];

	return 0;
}