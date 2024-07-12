#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
#define INF 0x7FFFFFFF;
int N;
bool visited[13][13];
int map[13][13];
queue<int> qx;
queue<int> qy;
int dx[4] = { 1,-1,0,0 }; // 아래, 위, 왼, 오
int dy[4] = { 0,0,-1,1 };


int coreCnt;


int direction(int x, int y) {
	int minDis = INF;
	int idx = 4;
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (1) {
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && map[nx][ny] == 0 && !visited[nx][ny]) {
				cnt++;
				if (nx == 1 || ny == 1 || nx == N || ny == N) {
					if (cnt <= minDis) { minDis = cnt; idx = i; }
				}
				nx = nx + dx[i];
				ny = ny + dy[i];

			}
			else { break; }
		}
	}
	if (idx == 4) { // 연결 실패
		
	}
	else { // 연결 성공
		coreCnt++;
		int nx = x + dx[idx];
		int ny = y + dy[idx];
		while (1) {
			visited[nx][ny] = true;
			if (nx == 1 || ny == 1 || nx == N || ny == N) { break; }
			nx = nx + dx[idx];
			ny = ny + dy[idx];
		}
	}
	if (minDis == 0x7FFFFFFF)minDis = 0;
	return minDis;
}



int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		while (!qx.empty()) {
			qx.pop();
			qy.pop();
		}
		int ans = INF;
		int M = 0x80000000;
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		//-------------------------------------
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1&& i != 1 && i != N && j != 1 && j != N) {
					qx.push(i);
					qy.push(j);
				}
			}
		}
		
		int qSize = qx.size();
		for (int i = 0; i < qSize; i++) {
			int minDis = 0;
			coreCnt = 0;
			for (int j = 0; j < qSize; j++) {

				int x = qx.front();
				int y = qy.front();
				qx.push(x);
				qy.push(y);
				qx.pop();
				qy.pop();
				minDis+= direction(x, y);
			}
			if (coreCnt > M) {
				M = coreCnt;
				ans = minDis;
			}
			else if(coreCnt == M) {
				if (ans > minDis) {
					ans = minDis;
				}
			}
			coreCnt = 0;
			
			qx.push(qx.front());
			qy.push(qy.front());
			qx.pop();
			qy.pop();
			memset(visited, 0, sizeof(visited));
		}
		if (ans == 0x7FFFFFFF)ans = 0;
		cout << "#" << test_case << " " << ans << '\n';
		
	}
	return 0;
}