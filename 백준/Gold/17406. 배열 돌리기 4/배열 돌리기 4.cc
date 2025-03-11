#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;





int N, M, K;
int arr[51][51];
bool visited[6];
int ans = 5000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<pair<int, int>, int>> v;
vector<int> idx_v;

void input(){
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<K;i++){
		int a, b, c;
		cin>>a>>b>>c;
		v.push_back({{a,b}, c});
	}
}

void updateAnswer(){
	int m = 5000;

	for(int i=1;i<=N;i++){
		int sum = 0;
		for(int j=1;j<=M;j++){
			sum += arr[i][j];
		}
		m = min(sum, m);
	}

	ans = min(ans, m);
}


void rotationArr(int x, int y, int R){
	for(int r=1;r<=R;r++){
		int cnt = 2*r*4;
		int dir = 0;
		int change = 0;
		
		int cx = x-r;
		int cy = y-r;
		int value = arr[cx][cy];
		
		while(cnt--){
			int nx = cx+dx[dir];
			int ny = cy+dy[dir];
			change++;
			arr[cx][cy] = arr[nx][ny];
			// 방향 변경
			if(change==2*r){
				dir++;
				change=0;
			}
			cx = nx;
			cy = ny;
		}
		arr[x-r][y-r+1] = value;
	}
}


void backtracking(int idx, int cnt){
	if(cnt == v.size()){

		int backup[51][51];
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                backup[i][j] = arr[i][j];
            }
        }

		for(int i=0;i<idx_v.size();i++){
			int elem = idx_v[i];
			int x = v[elem].first.first;
			int y = v[elem].first.second;
			int r = v[elem].second;
			rotationArr(x, y, r);
		}
		updateAnswer();

		for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                arr[i][j] = backup[i][j];
            }
        }
		return;
	}
	for(int i=0;i<v.size();i++){
		if(!visited[i]){
			idx_v.push_back(i);
			visited[i]=true;
			backtracking(idx+1, cnt+1);
			visited[i]=false;
			idx_v.pop_back();
		}
	}
}

void printAnswer(){
	cout<<ans<<'\n';
}

int main(int argc, char** argv)
{
	// 입력 받는 함수
	input();
	
	backtracking(-1, 0);
	
	printAnswer();
}