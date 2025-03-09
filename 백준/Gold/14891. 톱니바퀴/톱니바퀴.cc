#include <iostream>
using namespace std;

// 회전 함수
// N=0, S=1
int ans;
int K;

bool visited[5];
int circle[5][8];

void func(int N, int lotation) {
	//회전
	if (lotation == 1) { // 시계방향
		int tmp = circle[N][7];
		circle[N][7] = circle[N][6];
		circle[N][6] = circle[N][5];
		circle[N][5] = circle[N][4];
		circle[N][4] = circle[N][3];
		circle[N][3] = circle[N][2];
		circle[N][2] = circle[N][1];
		circle[N][1] = circle[N][0];
		circle[N][0] = tmp;
	}
	else { // 반시계
		int tmp = circle[N][0];
		circle[N][0] = circle[N][1];
		circle[N][1] = circle[N][2];
		circle[N][2] = circle[N][3];
		circle[N][3] = circle[N][4];
		circle[N][4] = circle[N][5];
		circle[N][5] = circle[N][6];
		circle[N][6] = circle[N][7];
		circle[N][7] = tmp;
	}
}

int lotation_change(int lotation) {
	if (lotation == -1) { lotation = 1; }
	else { lotation = -1; }
	return lotation;
}

void go(int N, int lotation) {
	//방문처리
	visited[N] = true;
	// 확인 후 옆으로 이동
	if (N-1>0  &&!visited[N - 1] && circle[N][6]!=circle[N-1][2]) {
		lotation = lotation_change(lotation);
		go(N - 1, lotation);
		lotation = lotation_change(lotation);
	}
	if (N + 1 <= 4 && !visited[N + 1] && circle[N][2] != circle[N + 1][6]) {
		lotation = lotation_change(lotation);
		go(N + 1, lotation);
		lotation = lotation_change(lotation);
	}
	func(N, lotation);
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < 8; j++) {
			circle[i][j] = st[j] - '0';
		}
	}
	
	cin >> K;
	for (int i = 0; i < K; i++) {
		int N;
		int lotation; // 1 시계방향, -1 반시계방향
		cin >> N >> lotation;
		for (int i = 1; i <= 4; i++) {
			visited[i] = false;
		}
		go(N, lotation);
	}


	if (circle[1][0] == 1) { ans += 1; }
	if (circle[2][0] == 1) { ans += 2; }
	if (circle[3][0] == 1) { ans += 4; }
	if (circle[4][0] == 1) { ans += 8; }
	cout << ans;
	return 0;
}