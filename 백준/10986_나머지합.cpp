#include<iostream>
using namespace std;


int N, M;
long long arr[1000001];
long long cnt[1001];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) { // ������ ���
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i <= N; i++) { // ��ⷯ ����
		arr[i] = (arr[i])%M;
	}
	for (int i = 1; i <= N; i++) { // ���� ����
		cnt[arr[i]]++;
	}
	
	long long ans = 0;
	for (int i = 0; i < M; i++) { // ans = nC2 + cnt[0]�� ����
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans + cnt[0];

	return 0;
}