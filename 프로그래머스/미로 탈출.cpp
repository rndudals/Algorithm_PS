#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[100][100];
int dist[100][100];
int start_x, start_y;
int lx, ly;
int end_x, end_y;

int bfs(int sx, int sy, int ex, int ey, vector<string> &maps){
    int cnt=0;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    visited[sx][sy]=true;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(visited[nx][ny]) continue;
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >=maps[0].size()) continue;
            if(maps[nx][ny] != 'X'){
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
                visited[nx][ny]=true;
            }
        }
    }
    return dist[ex][ey];
}

int solution(vector<string> maps) {
    int answer = 0;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            if(maps[i][j]=='S'){
                start_x = i;
                start_y = j;
            }
            if(maps[i][j]=='L'){
                lx = i;
                ly = j;
            }
            if(maps[i][j]=='E'){
                end_x = i;
                end_y = j;
            }
        }
    }
    int a = bfs(start_x, start_y, lx, ly, maps);
    int b = bfs(lx, ly, end_x, end_y, maps);
    if(a ==0 || b == 0){answer = -1;}
    else{answer = a+b;}
    return answer;
}