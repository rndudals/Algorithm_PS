#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[100][100];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int answer = -1;
vector<string> arr;
int row;
int col;

pair<int, int> move(int cx, int cy, int i){
    while(1){
        int nx = cx+dx[i];
        int ny = cy+dy[i];
        if(nx<0 || ny<0 || nx>=row || ny>=col) break;
        if(arr[nx][ny]=='D') break;
        cx=nx;
        cy=ny;
    }
    return {cx, cy};
}

void bfs(int sx, int sy, int tx, int ty){
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    visited[sx][sy] = true;
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cnt = q.front().second;
        
        if(cx==tx && cy == ty){
            answer=cnt;
            break;
        }
        q.pop();
        
        for(int i=0;i<4;i++){
            pair<int, int> p= move(cx, cy, i);
            int nx = p.first;
            int ny = p.second;
            if(!visited[nx][ny]){
                q.push({{nx, ny}, cnt+1});
                visited[nx][ny]=true;
            }
        }
    }
}

int solution(vector<string> board) {
    arr = board;
    row = board.size();
    col = board[0].size();
    
    int sx, sy, tx, ty;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='R'){
                sx=i;
                sy=j;
            }
            if(board[i][j]=='G'){
                tx=i;
                ty=j;
            }
        }
    }
    
    bfs(sx, sy, tx, ty);
    
    return answer;
}