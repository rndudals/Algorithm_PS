#include <iostream>
#include <vector>
using namespace std;

int N, S;
int arr[20];
bool visited[20];
int answer;
int k;
void func(int sum, int cnt, int size, int cur) {
	if (cnt == size) {
		if (sum == S) { answer++; }
		return;
	}
	for (int i = cur; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			func(sum+arr[i], cnt+1, size, i);
			visited[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N>>S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		func(0, 0, i, 0);
	}
	
	cout << answer;
	return 0;
}