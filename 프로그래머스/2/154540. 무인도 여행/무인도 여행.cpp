#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool visited[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int sum;
int row, col;

void dfs(int x, int y, vector<string>& maps){
    visited[x][y]=true;
    sum+=maps[x][y]-'0';
    
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
        
        if(!visited[nx][ny] && maps[nx][ny]!='X'){
            dfs(nx, ny, maps);
        }
    }
}

vector<int> solution(vector<string> maps) {
    row = maps.size();
    col = maps[0].size();
    vector<int> answer;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            if(!visited[i][j] && maps[i][j]!='X'){
                sum = 0;
                dfs(i, j, maps);
                if(sum != 0){
                    answer.push_back(sum);
                }
            }
        }
    }
    
        
    if(answer.size()==0){
        answer.push_back(-1);
    }
    else{
        sort(answer.begin(), answer.end());
    }
    return answer;
}