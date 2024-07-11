#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int T, n, m;
int A_arr[1001];
int B_arr[1001];
vector<int> sub_A;
vector<int> sub_B;

void Input() {
	cin >> T;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A_arr[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B_arr[i];
	}
}

void addSub(int* arr, vector<int>& v, int size) { // �κ� �迭�� �� ã��
	for (int i = 1; i <= size; i++) { // �ϳ��� ��
		v.push_back(arr[i]);
	}

	for (int i = 1; i <= size - 1; i++) { // �ΰ� �̻��� ��
		int plus = arr[i];
		for (int j = i + 1; j <= size; j++) {
			plus += arr[j];
			v.push_back(plus);
		}
	}
}

int lower_bound(int lo, int hi, int target) {
	while (lo != hi) {
		int mid = lo + (hi - lo) / 2;
		if (sub_B[mid] >= target) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

int upper_bound(int lo, int hi, int target) {
	while (lo != hi) {
		int mid = lo + (hi - lo) / 2;
		if (sub_B[mid] > target) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

long long answer() {
	sort(sub_B.begin(), sub_B.end());

	int sub_A_size = sub_A.size();
	int sub_B_size = sub_B.size();

	long long ans = 0;
	for (int i = 0; i < sub_A_size; i++) { // �̺� Ž������ ��� ��� ã��
		int target = T - sub_A[i];
		int ub = upper_bound(0, sub_B_size, target);
		int lb = lower_bound(0, sub_B_size, target);
		ans += (ub - lb);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	addSub(A_arr, sub_A, n); // A�� �κ� �迭�� �� ã��
	addSub(B_arr, sub_B, m); // B�� �κ� �迭�� �� ã��
	cout << answer(); 
	
	return 0;
}