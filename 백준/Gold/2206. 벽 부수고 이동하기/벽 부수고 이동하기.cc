#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <math.h>
#include <unordered_map>
#include <sstream>
using namespace std;

int arr[1000][1000];
bool visited[1000][1000][2];
int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1 ,-1};
int dist[1000][1000][2];

queue<pair<pair<int, int>, int>> q;

void init(){
    for(int i=0;i<N;i++){
        string st;
        cin >> st;
        for(int j=0;j<M;j++){
            arr[i][j] = st[j]-'0';
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j][0] = 1000000;
            dist[i][j][1] = 1000000;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    init();
    q.push({{0, 0}, 1});
    visited[0][0][1]=true;
    dist[0][0][1] = 1;
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int b = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || ny < 0 || nx>=N || ny>=M) continue;
            if(arr[nx][ny]==1){ // 벽일 때
                if(b==0) continue;
                if(visited[nx][ny][0]) continue;
                visited[nx][ny][0] = true;
                q.push({{nx, ny}, 0});
                dist[nx][ny][0] = dist[cx][cy][1] + 1;
            }else{ // 벽이 아닐 때
                if(visited[nx][ny][b]) continue;
                visited[nx][ny][b] = true;
                q.push({{nx, ny}, b});
                dist[nx][ny][b] = dist[cx][cy][b] + 1;
            }
        }
    }

    int a = dist[N-1][M-1][0];
    int b = dist[N-1][M-1][1];

    
    if(a ==1000000 && b ==1000000){
        cout<<"-1"<<'\n';
    }else{
        cout<<min(a, b)<<'\n';
    }
    return 0;
}
