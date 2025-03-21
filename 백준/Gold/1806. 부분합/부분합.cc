#include <iostream>
using namespace std;

int N, S;
int arr[100000];
int len, sum;
int ans=100000000;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int* s = arr;
	int* e = arr;
	len = 1;
	sum = arr[0];
	while (1) {
		if (e == arr + N) {break;}
		if (sum < S) {
			e++;
			sum += *e;
			len++;


		}
		else if (sum >= S) {
			if (ans > len) { ans = len; }
			sum -= *s;
			s++;
			len--;
		}
		if (sum < 0) { ans = 1; break; }
	}
	if (ans == 100000000) { cout << 0; }
	else { cout << ans; }
	

	return 0;
}