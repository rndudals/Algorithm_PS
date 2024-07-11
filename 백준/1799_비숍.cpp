#include<iostream>
#include <map>
#include <queue>
using namespace std;

bool l_visited[50]; // 왼쪽아래로 가는 대각선
bool r_visited[50]; // 오른쪽 아래로 가는 대각선
int arr[11][11];
int N;
int ans;
int bishop[2];

void func(int x, int y, int cnt, int color) {
	if (x>N) {
		if (bishop[color] < cnt) { // 최댓값 갱신
			bishop[color] = cnt;
		}
		return;
	}
	if (y > N) {
		x++;
		if (y % 2 == 1) y = 2; // 홀수면 짝수로 바꿔주기
		else y = 1; // 짝수면 홀수로 바꿔주기
	}
	//말을 놓을 수 있을 때
	if (arr[x][y] && !l_visited[x + y] && !r_visited[x - y + 10]) {
		l_visited[x + y] = 1;
		r_visited[x - y + 10] = 1;
		func(x, y+2, cnt+1, color); // 말을 놓는 경우
		l_visited[x + y] = 0;
		r_visited[x - y + 10] = 0;
	}
	func(x, y+2, cnt, color); // 말을 안놓는 경우
	// *말을 놓을수 있을 때도 안 놓는 경우도 계산 해야 함
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	func(1, 1, 0, 0); // 검정
	func(1, 2, 0, 1); // 흰색

	
	cout << bishop[0] + bishop[1];
	
	return 0;
}