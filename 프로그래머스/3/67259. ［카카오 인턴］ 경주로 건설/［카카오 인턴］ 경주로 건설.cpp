#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

// 방향 벡터: 0 - 아래, 1 - 위, 2 - 오른쪽, 3 - 왼쪽
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 3차원 거리 배열: dist[x][y][d] - 방향 d로 도착할 때의 최소 비용
int dist_arr[25][25][4];

// 매우 큰 수로 초기화
const int INF = 987654321;

// Node 클래스 정의
class Node{
public:
    int x;
    int y;
    int prev_dir;
};

// 거리 배열 초기화 함수
void init(){
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            for(int d=0; d<4; d++) {
                dist_arr[i][j][d] = INF;
            }
        }
    }
}

// BFS 함수
void bfs(int x, int y, vector<vector<int>> board){
    int size = board.size();
    queue<Node> q;
    
    // 시작점에서 오른쪽(2)과 아래(0) 방향으로 초기화
    if(size > 1 && board[0][1] == 0){
        q.push(Node{0, 1, 2});
        dist_arr[0][1][2] = 100;
    }
    if(size > 1 && board[1][0] == 0){
        q.push(Node{1, 0, 0});
        dist_arr[1][0][0] = 100;
    }
    
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int cpd = q.front().prev_dir;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 범위 체크 및 벽 체크
            if(nx<0 || ny <0 || nx>=size || ny >=size) continue;
            if(board[nx][ny]!=0) continue;
            
            // 이동 비용 계산
            int new_cost = dist_arr[cx][cy][cpd];
            if(cpd == i){ // 같은 방향
                new_cost += 100;
            }
            else{ // 방향이 바뀔 때
                new_cost += 600; // 100 (직선) + 500 (코너)
            }
            
            // 해당 방향으로 도착했을 때의 비용이 더 작으면 업데이트
            if(new_cost < dist_arr[nx][ny][i]){
                dist_arr[nx][ny][i] = new_cost;
                q.push(Node{nx, ny, i});
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int size = board.size();
    init();
    bfs(0, 0, board);
    
    // 도착 지점에서의 최소 비용 찾기
    int answer = INF;
    for(int d=0; d<4; d++){
        answer = min(answer, dist_arr[size-1][size-1][d]);
    }
    
    return answer;
}