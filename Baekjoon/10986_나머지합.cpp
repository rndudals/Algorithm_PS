#include<iostream>
using namespace std;


int N, M;
long long arr[1000001];
long long cnt[1001];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) { // 누적합 계산
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i <= N; i++) { // 모듈러 연산
		arr[i] = (arr[i])%M;
	}
	for (int i = 1; i <= N; i++) { // 개수 세기
		cnt[arr[i]]++;
	}
	
	long long ans = 0;
	for (int i = 0; i < M; i++) { // ans = nC2 + cnt[0]의 개수
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans + cnt[0];

	return 0;
}