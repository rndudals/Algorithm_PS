#include <iostream>
using namespace std;

int sum;
int d[1001][10];
int N, T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <=j; k++) {
				d[i][j] = (d[i][j]+d[i - 1][k])%10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum + d[N][i])%10007;
	}
	
	cout << sum << '\n';
	return 0;
}