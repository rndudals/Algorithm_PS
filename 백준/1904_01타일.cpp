#include <iostream>
using namespace std;

int N;
long long d[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= N; i++) {
		d[i] = (d[i - 1] + d[i - 2])%15746;
	}
	cout << d[N] << '\n';

	return 0;
}