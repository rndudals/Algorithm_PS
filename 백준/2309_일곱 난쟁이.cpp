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
			sum -= arr[i]; number[i] = true; // ������ �θ� ���ֱ�
			sum -= arr[j]; number[j] = true;
			if (sum == 100) { // ���� 100�� ��� ���� ���
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