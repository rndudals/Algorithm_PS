#include <iostream>
#include <algorithm>
using namespace std;

int number[9];
int arr[9];
int sum = 0;

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			sum -= arr[i]; number[i] = true; // 난쟁이 두명 빼주기
			sum -= arr[j]; number[j] = true;
			if (sum == 100) { // 합이 100일 경우 정답 출력
				for (int i = 0; i < 9; i++) {
					if (!number[i]) {
						cout << arr[i]<<'\n';
					}
				}
				exit(0);
			}
			sum += arr[i]; number[i] = false;
			sum += arr[j]; number[j] = false;
		}
	}

	return 0;
}