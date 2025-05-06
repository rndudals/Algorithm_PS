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

int R, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[26];
int arr[21][21];
int ans = 0;

void input(){
    cin >> R >> C;
    for(int i=0;i<R;i++){
        string st;
        cin >> st;
        for(int j=0;j<C;j++){
            arr[i+1][j+1] = st[j]-'A';
        }        
    }
}

void dfs(int x, int y, int cnt){
    
    if(cnt>ans) ans = cnt;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[arr[nx][ny]]) continue;
        if(nx<1 || ny < 1 || nx>R || ny>C) continue;
        visited[arr[nx][ny]] = true;
        dfs(nx, ny, cnt+1);
        visited[arr[nx][ny]] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    
    visited[arr[1][1]] = true;
    dfs(1, 1, 1);

    cout<<ans<<'\n';
    return 0;
}
