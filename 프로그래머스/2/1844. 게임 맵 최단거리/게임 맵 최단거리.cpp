#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int dist[100][100];
bool visited[100][100];
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    visited[0][0] = true;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 ||ny<0 ||nx>=n ||ny>=m){
                continue;
            }
            if(!visited[nx][ny] && maps[nx][ny]==1){
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    
    return dist[n-1][m-1] == 0 ? -1:dist[n-1][m-1];
}