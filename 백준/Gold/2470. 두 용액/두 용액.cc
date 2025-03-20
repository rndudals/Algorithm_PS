#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int arr[100001];
int* s, * e;
int value,m=2100000000;
int ansX, ansY;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	s = arr;
	e = arr + N-1;
	while (1) {
		if (s == e) { break; }

		value = *s + *e;
		if (m > abs(value)) {
			m = abs(value);
			ansX = *s;
			ansY = *e;
		}
		if (value < 0) {
			s++;
		}
		else if (value > 0) {
			e--;
		}
		else {
			ansX = *s;
			ansY = *e;
			break;
		}
	}
	cout << ansX << " " << ansY << '\n';
	return 0;
}