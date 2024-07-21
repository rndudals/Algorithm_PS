#include <iostream>
#include <cstring>
using namespace std;

int N;
int arr[1000001];
int cnt=1;
int tmp[1000001];
int binarySearch(int lo, int hi, int target) {
	while (lo!=hi) {
		int mid = lo + (hi - lo) / 2;
		if (tmp[mid] >= target) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	tmp[0] = arr[0];
	int tmp_idx =0;
	for (int i = 1; i < N; i++) {
		if (tmp[tmp_idx] < arr[i]) {
			tmp_idx++;
			cnt++;
			tmp[tmp_idx] = arr[i];
			
			
		}
		else {
			int idx = binarySearch(0, tmp_idx, arr[i]);
			tmp[idx] = arr[i];
		}
		
	}
	cout << cnt;

	return 0;
}