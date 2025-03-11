#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;


int N, ans;
int arr[17][17];

// 왼쪽 : 0, 대각선 : 1, 아래 : 2
int range[3][2] = {{0,1}, {0,2}, {1, 2}};
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

queue<pair<pair<int, int>, int>> q;



int main(int argc, char** argv)
{
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>arr[i][j];
		}
	}

	q.push({{1,2}, 0});

	while(!q.empty()){
		
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cdir = q.front().second;

		q.pop();
		if(cx==N && cy==N){ans++; continue;}
		
		int start = range[cdir][0];
		int end = range[cdir][1];
		for(int i=start ; i<=end; i++){
			int ndir = i;
			int nx = cx+dx[ndir];
			int ny = cy+dy[ndir];
			if(nx<1 || ny<1 || nx>N || ny>N) continue;
			if(arr[nx][ny]==1) continue;
			if(ndir==1){
				if(arr[nx-1][ny]==1 || arr[nx][ny-1]==1) continue;
			}
			q.push({{nx, ny}, ndir});
		}
	}

	cout<<ans;
}