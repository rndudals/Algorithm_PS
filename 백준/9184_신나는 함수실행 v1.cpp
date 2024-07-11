#include <iostream>
using namespace std;


int dp[101][101][101];

int w(int a, int b, int c) {
	if (dp[a + 50][b + 50][c + 50] != 0) {
		return dp[a + 50][b + 50][c + 50];
	}
	if (a <= 0 or b <= 0 or c <= 0) {
		return dp[a + 50][b + 50][c + 50] = 1;
	}
	if (a > 20 or b > 20 or c > 20) {
		return w(20, 20, 20);
	}

	if (a < b && b < c) {
		return dp[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		return dp[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1)
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