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
		2 * dp[i - 1] : i-1�� 10�� �� 01, 00 ����
						i-1�� 01�� �� 10, 00 ����
						i-1�� 00�� �� 10, 01, 00 ����-> ���⼭ 00�� i-2�� 00�� ���� �߰� ����

		dp[i-2] : (i-2)��°�� �ִ� ���� ��ŭ 00�� ����Ƿ�
	*/
	for (int i = 2; i <= N; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2])%9901;
	}
	cout << dp[N];

	return 0;
}