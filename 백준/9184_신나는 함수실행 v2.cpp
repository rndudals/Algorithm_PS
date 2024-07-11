#include <iostream>
#include <string.h>
using namespace std;

#define N 50

int dp[N][N][N];

int w(int a, int b, int c) {

	if (a <= 0 or b <= 0 or c <= 0) {
		return 1;
	}
	if (a > 20 or b > 20 or c > 20) {
		return w(20, 20, 20);
	}
	if (dp[a][b][c] != 0) {
		return dp[a][b][c];
	}
	if (a < b && b < c) {
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1)
			- w(a - 1, b - 1, c - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}


	return 0;
}