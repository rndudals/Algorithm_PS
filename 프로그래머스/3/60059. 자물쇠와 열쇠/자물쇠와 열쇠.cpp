#include <string>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

bool visited[60][60];
int hole_cnt = 0;
bool answer = false;

vector<vector<int>> locate(vector<vector<int>> key, int M){
    vector<vector<int>> tmp(M, vector<int>(M, 0));
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            tmp[i][j] = key[M-j-1][i];
        }
    }
    return tmp;
}

void printArr(vector<vector<int>> key, int M){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cout<<key[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void run1(vector<vector<int>> key, vector<vector<int>> lock, int M, int N, int start_i, int start_j){
    int cnt = 0;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            int x = start_i + i;
            int y = start_j + j;

            if(visited[x][y]==true){
                if(key[i][j]==1){ // 열쇠의 돌기가 자물쇠의 홈을 채움
                    cnt++;
                }
            } else {
                // 자물쇠 영역 내에서 열쇠의 돌기와 자물쇠의 돌기가 겹치는지 확인
                if(x >= M && x < M+N && y >= M && y < M+N){
                    int lock_i = x - M;
                    int lock_j = y - M;
                    if(key[i][j]==1 && lock[lock_i][lock_j]==1){
                        // 열쇠의 돌기와 자물쇠의 돌기가 겹침
                        return;
                    }
                }
            }
        }
    }
    
    if(cnt == hole_cnt){
        answer = true;
        return;
    }
}

void run(vector<vector<int>> key, vector<vector<int>> lock, int M, int N){
    for(int start_i=0; start_i<M+N; start_i++){
        for(int start_j=0; start_j<M+N; start_j++){
            run1(key, lock, M, N, start_i, start_j);
            if(answer) return; // 자물쇠를 열 수 있으면 조기 종료
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();

    // 변수 초기화
    hole_cnt = 0;
    answer = false;
    memset(visited, false, sizeof(visited));

    // 자물쇠의 홈 위치 기록
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(lock[i][j]==0){
                hole_cnt++;
                visited[i+M][j+M] = true; // 자물쇠의 홈 위치 표시
            }
        }
    }

    // 열쇠를 4번 회전하며 검사
    for(int i=0;i<4;i++){
        key = locate(key, M);
        run(key, lock, M, N);
        if(answer) return true; // 자물쇠를 열 수 있으면 true 반환
    }

    return false; // 자물쇠를 열 수 없으면 false 반환
}
