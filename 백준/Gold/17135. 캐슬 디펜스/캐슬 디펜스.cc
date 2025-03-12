#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, D, ans, maxAns;
int arr[16][16];
int backupArr[16][16];
bool visited[16][16];
bool checkPos[16];
bool reservation[16][16];

// 궁수를 놓을 열(세로) 위치 3개
vector<int> archers;

// 방향: 왼, 위, 오른, 아래 (가장 왼쪽 적 우선 탐색을 위해)
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void initArr(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            backupArr[i][j] = arr[i][j];
        }
    }
}

void input(){
    cin >> N >> M >> D;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    initArr();
}

// (sx, sy)는 궁수 위치 (row=N+1, col=archer_col)
// BFS로 사거리 D 이내의 가장 가까운 적(동일거리면 왼쪽 우선) 1마리를 찾음
void bfs(int sx, int sy){
    // 각 BFS 시작 시 visited 초기화
    memset(visited, false, sizeof(visited));

    queue< pair<pair<int,int>, int> > q;
    q.push({{sx, sy}, 0});
    visited[sx][sy] = true;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nd = dist + 1;

            // 적이 있는 실제 범위: 1행 ~ N행
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if(nd > D) continue;

            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                // 적 발견 → reservation 표시 후 즉시 종료
                if(arr[nx][ny] == 1){
                    reservation[nx][ny] = true;
                    return;
                }
                // 적이 없으면 계속 탐색
                q.push({{nx, ny}, nd});
            }
        }
    }
}

// reservation[]에 표시된 적을 실제로 제거
void removeReservation(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(reservation[i][j]){
                arr[i][j] = 0;
                ans++;
            }
        }
    }
    memset(reservation, false, sizeof(reservation));
}

// 적 이동: N행부터 2행까지 아래로 한 칸씩 복사, 1행은 0으로
void moveMonster(){
    for(int i = N; i > 1; i--){
        for(int j = 1; j <= M; j++){
            arr[i][j] = arr[i-1][j];
        }
    }
    for(int j = 1; j <= M; j++){
        arr[1][j] = 0;
    }
}

// 궁수 3명 배치 후 시뮬레이션: 최대 N턴
void startAttack(){
    ans = 0;
    for(int turn = 0; turn < N; turn++){
        // 3궁수가 동시에 공격
        for(int i=0; i<3; i++){
            // 궁수는 (N+1)행, archers[i] 열 위치
            bfs(N+1, archers[i]);
        }
        removeReservation();
        moveMonster();
    }
    maxAns = max(maxAns, ans);
}

void makeAttackLocation(int idx){
    if(archers.size() == 3){
        // 매 조합마다 arr를 초기 상태로 복원
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                arr[i][j] = backupArr[i][j];
            }
        }
        startAttack();
        return;
    }
    for(int i=idx; i<=M; i++){
        if(!checkPos[i]){
            checkPos[i] = true;
            archers.push_back(i);
            makeAttackLocation(i+1);
            archers.pop_back();
            checkPos[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    makeAttackLocation(1);
    cout << maxAns << "\n";
    return 0;
}
