#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M, K;
int card[4000000];
int chulsu[10000];
int parent[4000001];
int location[4000000];

int getParent(int x) {
	if (parent[x] == x) { // �θ�� �ڱ��ڽ��� ������ ����
		return x;
	}
	else {
		return parent[x] = getParent(parent[x]); // ��� ����
	}
}

void unionNode(int a, int b) { // a, b�� ���� �������� ��ħ
	if (a > b) swap(a, b);
	parent[getParent(a)] = getParent(b);
}

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> card[i];
	}
	for (int i = 0; i < K; i++) {
		cin >> chulsu[i];
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

}

int binarySearch(int lo, int hi, int target) { 
	while (lo != hi) { // lower_bound�� target���� ũ�ų� ���� ������ ��ġ�� ã���ϴ�.
		int mid = lo + (hi - lo) / 2;
		card[mid] > target ? hi = mid : lo = mid + 1;
	}
	return lo;
}

void run() {
	sort(card, card + M);
	for (int i = 0; i < M; i++) {
		location[card[i]] = i;
	}
	for (int i = 0; i < K; i++) {
		int target = chulsu[i];
		int idx = binarySearch(0, M, target);
		int p = getParent(card[idx]);
		cout << p<< '\n';
		unionNode(card[idx], card[location[p]+1]); // Union ���ݴϴ�.
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	run();
	
	return 0;
}