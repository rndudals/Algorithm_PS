#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M, K;
int arr[101][101];
bool visited[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int m = 0;
int ans = 0;

void dfs(int x, int y){
    visited[x][y] = true;
    m++;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>N || ny >M||nx<1 || ny<1) continue;
        if(!visited[nx][ny] && arr[nx][ny]==1){
            dfs(nx, ny);
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>K;
    for(int i=0;i<K;i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = 1;
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            
            if(!visited[i][j] && arr[i][j]==1){
                m = 0;
                dfs(i, j);
                ans = max(ans, m);
            }
        }
    }
    cout<<ans;
}
