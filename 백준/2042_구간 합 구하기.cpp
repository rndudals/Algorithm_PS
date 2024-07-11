#include <iostream>
using namespace std;


long long arr[1000000];
long long segtree[2000000];
long long N, M, K;

void Init() {
	for (long long i = 0; i < N; i++) {
		segtree[i + N] = arr[i]; // [N, 2N)�� �������� ä��ϴ�.
	}
	for (long long i = N-1; i !=0 ; i--) {
		segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
	}
	
}

void update(long long i, long long x) { // i��° ���� x�� �ٲߴϴ�.
	segtree[i + N] = x;
	i = i + N;
	while (i >>= 1) {
		segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
	}
}

long long query(long long l, long long r) {
	long long result = 0;
	for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
		if (l & 1)result += segtree[l++]; // l�� ������ ����̸� �����ְ� �ø��ϴ�.
		if (r & 1)result += segtree[--r]; // r�� ������ ����̸� ���ְ� ���մϴ�.
	}
	return result;
}

void run() {
	cin >> N >> M >> K;
	for (long long i = 0; i < N; i++) {
		cin >> arr[i];
	}
	Init();
	
	for (long long i = 0; i < M+K; i++) {
		long long q, x, y;
		cin >> q;
		if (q == 1) {
			cin >> x >> y;
			update(x - 1, y);
		}
		else {
			cin >> x >> y;
			cout<<query(x - 1, y)<<'\n';
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	run();
	
	return 0;
}