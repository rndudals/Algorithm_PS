#include <iostream>
using namespace std;

int N;
int visited[9];
int arr[9];
int ans;
void func(int front, int second, int depth, int sum) {
	if (depth == N) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			func(second, arr[i], depth + 1, sum + abs(second - arr[i]));
			visited[i] = false;
		}
	}
	

}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		visited[i] = true;
		func(arr[0], arr[i], 1, 0);
		visited[i] = false;
	}
		
	
	cout << ans;
	return 0;
}