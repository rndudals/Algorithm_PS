#include <iostream>
#include <algorithm>
using namespace std;
int A[50];
int B[50];
int main() {
	int N,sum=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N, greater<int>());
	for (int i = 0; i < N; i++) {
		sum = sum + A[i] * B[i];
	}
	cout << sum;
}