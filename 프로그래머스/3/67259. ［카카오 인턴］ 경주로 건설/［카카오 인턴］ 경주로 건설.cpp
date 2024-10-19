#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int INF = 987654321;
int dist[25][25][4];

class Node{
public:
    int x;
    int y;
    int prev_dir;
};

void init(){
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            for(int d=0; d<4; d++) { 
                dist[i][j][d] = INF;
            }
        }
    }
}

void bfs(int x, int y, vector<vector<int>> board){
    int size = board.size();
    queue<Node> q;
    q.push({x, y, 0});
    q.push({x, y, 2});
    dist[0][0][0] = 0;
    dist[0][0][2] = 0;
    while(!q.empty()){
        
        int cx = q.front().x;
        int cy = q.front().y;
        int cpd = q.front().prev_dir;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || ny <0 || nx>=size || ny >=size) continue;
            if(board[nx][ny]!=0) continue;
            if(cpd == i){ // 같은 방향
                if(dist[nx][ny][i] > dist[cx][cy][i] + 100){
                    dist[nx][ny][i] = dist[cx][cy][i] + 100;
                    q.push({nx, ny, i});
                }
            }
            else{ // 방향이 바뀔 때
                if(dist[nx][ny][i] > dist[cx][cy][cpd] + 600){
                    dist[nx][ny][i] = dist[cx][cy][cpd] + 600;
                    q.push(Node{nx, ny, i});
                }
            }
            
        }
    }
    
}

int solution(vector<vector<int>> board) {
    int answer = INF;
    int size = board.size();
    init();
    bfs(0, 0, board);
    
    for(int i=0;i<4;i++){
        answer = min(answer, dist[size-1][size-1][i]);
    }
    return answer;
}