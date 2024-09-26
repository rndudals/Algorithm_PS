#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


int n, m;
int map[1000][1000];
int dist[1000][1000];
bool visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j] = 1000000;
        }
    }
}

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    init();
}

void bfs(int x, int y){
    
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    visited[x][y] = true;
    q.push({x, y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy +dy[i];
            
            if(nx<0||nx>=n ||ny<0||ny>=m) continue;
            if(map[nx][ny]!=0 && !visited[nx][ny]){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void run(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==2){
                bfs(i, j);
            }
        }
    }
}


void printAnswer(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && map[i][j]!=0){
                cout<<-1<<" ";
            }
            else{
            cout<<((dist[i][j]==1000000)?0:dist[i][j])<<" ";
            }
        }
        cout<<'\n';
    }
}
int main(){
    input();
    run();
    printAnswer();
}