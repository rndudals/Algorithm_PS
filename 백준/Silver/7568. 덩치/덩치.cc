#include <iostream>
using namespace std;


int main() {
	int N;
	cin >>N;
	int* p = new int[N];
	int* px = new int[N];
	int* py = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> px[i];
		cin >> py[i];
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (px[i] < px[j] && py[i] < py[j]) {
				rank++;
			}
		}
		p[i] = rank;
	}

	for (int i = 0; i < N; i++) {
		cout << p[i] << ' ';
	}
	return 0;
}