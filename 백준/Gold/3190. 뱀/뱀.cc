#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int N, K;
int L;
vector<pair<int, char>> v;
int cx=1, cy=1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[102][102]; // 0: 갈수 있는 칸, 1: 벽 or 몸, 2: 사과
int ans = 0;
queue<pair<int, int>>q;
int dir = 0;


void input(){
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = 2;
    }

    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=N+1;j++){
            if(i==0 || j==0 || i==N+1 || j==N+1){
                arr[i][j] = 1;
            }
        }
    }
    cin>>L;
    for(int i=0;i<L;i++){
        int x;
        char ch;
        cin>>x>>ch;
        v.push_back({x, ch});
    }
}

int change_dir(int dir, char next_dir){
    if(next_dir=='D'){
        dir=(dir+1)%4;
    }else{
        dir--;
        if(dir<0){dir=3;}
    }
    return dir;
}

void move(int go, int next_dir){
    while(go--){
            int nx = cx+dx[dir];
            int ny = cy+dy[dir];

            ans++;
            
            if(arr[nx][ny]==1) {
                cout<<ans<<'\n';
                return exit(0);
            };
            
            if(go==0){
                dir = change_dir(dir, next_dir);
            }
            
            if(arr[nx][ny]==2){// 사과일 때
                q.push({nx, ny});
                arr[nx][ny] = 1;
            }
            else{ // 사과 아닐 때
                q.push({nx, ny});
                arr[nx][ny] = 1;
                
                
                int x = q.front().first;
                int y = q.front().second;
                arr[x][y] = 0;
                q.pop();
            }
            // 이동
            cx = nx;
            cy = ny;
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // input();
    input();

    // 이동
    
    q.push({cx, cy});
    arr[cx][cy] = 1;
    
    int pre = 0;
    for(int i=0;i<v.size();i++){
         int go = v[i].first - pre;
         pre = v[i].first;
         char next_dir = v[i].second;
         
         move(go, next_dir);
    }

    move(1000, -1);
}
