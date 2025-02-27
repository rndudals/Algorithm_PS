#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> v;

bool visited[201];

void dfs(int c){
    visited[c] = true;
    
    for(int i=0;i<v[c].size();i++){
        int next = v[c][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    v.resize(201);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(computers[i][j]==1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            answer++;
        }
    }
    return answer;
}