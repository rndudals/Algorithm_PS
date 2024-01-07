#include <iostream>
using namespace std;


int N;
char map[51][51];

int checkRow(int x, int y) { // 같은 행에서 같은 문자가 연속되는 최댓값을 리턴하는 함수
	char ch = map[x][1];
	int cnt = 1;
	int ret = 0;
	for (int i = 2; i <= N; i++) {
		if (ch != map[x][i]) {
			ch = map[x][i];
			cnt = 1;
		}
		else {
			cnt++;
			if (ret < cnt) {
				ret = cnt;
			}
		}
	}
	return ret;
}

int checkCol(int x, int y) { // 같은 열에서 같은 문자가 연속되는 최댓값을 리턴하는 함수
	int ret = 0;
	char ch = map[1][y];
	int cnt = 1;
	for (int i = 2; i <= N; i++) {
		if (ch != map[i][y]) {
			ch = map[i][y];
			cnt = 1;
		}
		else {
			cnt++;
			if (ret < cnt) {
				ret = cnt;
			}
		}
	}	return ret;
}

int func(int x, int y) { // 행 교체 하는 함수
	int ret = 0;

	//행 교체
	if (y + 1 <= N) {
		swap(map[x][y], map[x][y + 1]); // 교체
		ret= max(ret,checkRow(x,y));
		ret = max(ret, checkCol(x,y+1));
		ret = max(ret, checkCol(x, y));

		swap(map[x][y], map[x][y + 1]); // 원상복구
	}

	//열 교체
	if (x + 1 <= N) {
		swap(map[x][y], map[x+1][y]); // 교체
		ret = max(ret, checkRow(x, y));
		ret = max(ret, checkRow(x+1, y));
		ret = max(ret, checkCol(x, y));

		swap(map[x][y], map[x + 1][y]); // 원상복구
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int ans=0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans=max(ans,func(i,j));
		}
	}
	cout << ans;
	return 0;
}