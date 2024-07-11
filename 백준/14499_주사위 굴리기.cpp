#include <iostream>
using namespace std;

int N1, M1, x, y, K;
int map[21][21];
int U, L, E, W, S, N; // 위 아래 동서남북
int a;

void move(int u, int l, int e, int w, int s, int n) {
	U = u;	L = l;	E = e;	W = w;	S = s; N = n;

	if (map[x][y] == 0) {
		map[x][y] = L;
	}
	else {
		L = map[x][y];
		map[x][y] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N1 >> M1 >> x >> y >> K;
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < M1; j++) {
			cin >> map[i][j];
		}
	}
	while (K--) {
		bool check = 1;
		cin >> a;
		if (a == 1) { // 동쪽으로 이동
			if (y + 1 < M1) {
				y++;
				move(W, E, U, L, S, N);
			}
			else { check = 0; }
		}
		else if (a == 2) { // 서쪽으로 이동
			if (y - 1 >= 0) {
				y--;
				move(E, W, L, U, S, N);
			}
			else { check = 0; }
		}
		else if (a == 3) { // 북쪽으로 이동
			if (x - 1 >= 0) {
				x--;
				move(S, N, E, W, L, U);
			}
			else { check = 0; }
		}
		else { // 남쪽으로 이동
			if (x + 1 < N1) {
				x++;
				move(N, S, E, W, U, L);
			}
			else { check = 0; }
		}
		if (check == 1) {
			cout << U << '\n';
		}
	}
	return 0;
}