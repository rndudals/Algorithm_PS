#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
using namespace std;

int N;
int arr[20][20];
int ans = 0;

// 우, 하, 좌, 상
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// 디버깅용 (원하면 그대로 두거나 삭제)
void printArr(){
    cout << "\n-----\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

// 최대값 갱신
void calculateAns(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans = max(ans, arr[i][j]);
        }
    }
}

// 하나의 타일을 dir 방향으로 최대한 이동 + 합치기
// integ[x][y] = true 이면, 그 칸은 이미 합쳐진 칸이라서 추가 합침 불가
void move_elem(int x, int y, int dir, bool (&integ)[20][20]){
    int n = arr[x][y];
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    while(nx >= 0 && nx < N && ny >= 0 && ny < N){
        if(arr[nx][ny] != 0){
            // 같은 값이고, 아직 merge 한 칸이 아니라면 합치기
            if(arr[nx][ny] == n && !integ[nx][ny]){
                arr[nx][ny] *= 2;     // merge
                arr[x][y] = 0;
                integ[nx][ny] = true; // 이 칸은 이미 합쳐짐
            }
            // merge 했거나 못 했으면, 더 못 앞으로 가므로 break
            break;
        }
        // 그 칸이 0이면 계속 이동
        arr[nx][ny] = n;
        arr[x][y] = 0;

        x = nx;  // 실제로 위치 갱신
        y = ny;

        nx = x + dx[dir];
        ny = y + dy[dir];
    }
}

// 입력
void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
}


void move_(int cnt){ 
    if(cnt == 5){
        // 5번 움직였으니 최고값 확인
        calculateAns();
        return;
    }

    // 현재 보드 저장 (백업)
    int tmp[20][20];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmp[i][j] = arr[i][j];
        }
    }

    // 네 가지 방향 모두 시도
    for(int d = 0; d < 4; d++){
        // 이동/합치기 진행
        bool integ[20][20];
        memset(integ, false, sizeof(integ));

        if(d == 0){ // 오른쪽
            for(int i=0; i<N; i++){
                for(int j=N-1; j>=0; j--){
                    if(arr[i][j] != 0){
                        move_elem(i, j, d, integ);
                    }
                }
            }
        }
        else if(d == 1){ // 아래
            for(int j=0; j<N; j++){
                for(int i=N-1; i>=0; i--){
                    if(arr[i][j] != 0){
                        move_elem(i, j, d, integ);
                    }
                }
            }
        }
        else if(d == 2){ // 왼쪽
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(arr[i][j] != 0){
                        move_elem(i, j, d, integ);
                    }
                }
            }
        }
        else{ // d == 3 => 위
            for(int j=0; j<N; j++){
                for(int i=0; i<N; i++){
                    if(arr[i][j] != 0){
                        move_elem(i, j, d, integ);
                    }
                }
            }
        }

        // 다음 단계로
        move_(cnt + 1);

        // 보드 복원
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    // "0회 이동 상태"에서 시작
    move_(0);

    cout << ans << '\n';
    return 0;
}
