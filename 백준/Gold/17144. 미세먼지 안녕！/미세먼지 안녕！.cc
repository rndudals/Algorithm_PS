#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
using namespace std;

int R, C, T;
int arr[1000][1000];
int tmp[1000][1000];
int sx, sy;
int dx1[4] = {-1, 0, 1, 0};
int dy1[4] = {0, 1, 0, -1};

int dx2[4] = {1, 0, -1, 0};
int dy2[4] = {0, 1, 0, -1};

void printArr(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
void input(){
    cin>>R>>C>>T;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
            if(arr[i][j]==-1){
                sx = i;
                sy = j;
            }
        }
    }
}

void move1(int x, int y, int dir){
    int tmp_R = x + 1;
    x--;
    
    while(arr[x][y]!=-1){
        int nx = x+dx1[dir];
        int ny = y+dy1[dir];
        if(nx < 0 || ny < 0 || nx >= tmp_R|| ny >= C){
            dir++;
            nx = x+dx1[dir];
            ny = y+dy1[dir];
        }
        
        if(arr[nx][ny]==-1){break;}
        arr[x][y] = arr[nx][ny];

        x=nx;
        y=ny;
    }
    arr[x][y] = 0;
}

void move2(int x, int y, int dir){
    
    int tmp_R = x;
    x++;

    while(1){
        int nx = x+dx2[dir];
        int ny = y+dy2[dir];
        if(nx >= R || ny < 0 || nx < tmp_R|| ny >= C){
            dir++;
            nx = x+dx2[dir];
            ny = y+dy2[dir];
        }
        
        if(arr[nx][ny]==-1){break;}
        arr[x][y] = arr[nx][ny];
        
        
        x=nx;
        y=ny;
    }
    arr[x][y] = 0;
}

vector<int> v;

int check(int x, int y){
    int cnt = 0;
    for(int i=0;i<4;i++){
        int nx = x+dx1[i];
        int ny = y+dy1[i];
        if(nx<0||ny<0||nx>=R||ny>=C) continue;
        if(arr[nx][ny]==-1) continue;
        cnt++;
        v.push_back(i);
    }
    return cnt;
}

void run(){

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            v.clear();
            
            int n = check(i, j);
            tmp[i][j] += (arr[i][j] - arr[i][j]/5*n);
            for(int k=0;k<v.size();k++){
                int nx = i+dx1[v[k]];
                int ny = j+dy1[v[k]];
                tmp[nx][ny] += arr[i][j]/5;
            }
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    while(T--){
        memset(tmp, 0, sizeof(tmp));
        run();
        move1(sx-1, sy, 0);
        move2(sx, sy, 0);
    }
    int ans = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j]!=-1){
                ans += arr[i][j];
            }
            
        }
    }
    cout<<ans<<'\n';
    return 0;
}
