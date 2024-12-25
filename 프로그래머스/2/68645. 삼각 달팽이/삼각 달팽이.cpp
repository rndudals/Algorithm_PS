#include <string>
#include <vector>
#include <iostream>
using namespace std;

int map[1002][1002];
bool visited[1002][1002];
int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    int x=1, y=1;
    int number = 1;
    int dir = 0;
    int total = 0;
    
    for(int i=1;i<=n;i++){
        total+=i;
    }
    while(total--){
        // 찍기
        map[x][y]=number;
        visited[x][y] = true;
        number++;
        
        // 방향 보기
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        
        // 방향 수정
        if(nx<1 || nx>n || ny < 1 || ny>n || visited[nx][ny]){
            dir=(dir+1)%3;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        // 이동하기
        x=nx;
        y=ny;
        
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            answer.push_back(map[i][j]);
        }
    }
    return answer;
}