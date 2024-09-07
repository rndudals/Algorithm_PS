#include<iostream>
#include <queue>

using namespace std;
#define INF 999999
int arr[100][100];
int dist[100][100];
int N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<int>xq;
queue<int>yq;
string st;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> st;
			for (int j = 0; j < N; j++) {
				arr[i][j] = st[j]-'0';
				dist[i][j] = 999999;
			}
		}
		dist[0][0] = 0;
		xq.push(0);
		yq.push(0);
		while (!xq.empty()) {

			int cx = xq.front();
			int cy = yq.front();
			xq.pop();
			yq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N&&dist[nx][ny]>dist[cx][cy]+arr[nx][ny]) {
					dist[nx][ny] = dist[cx][cy] + arr[nx][ny];
					xq.push(nx);
					yq.push(ny);
				}
			}
		}

		cout << "#" << test_case << " " << dist[N - 1][N - 1]<<'\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}