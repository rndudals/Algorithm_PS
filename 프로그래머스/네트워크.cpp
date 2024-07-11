#include <string>
#include <vector>

using namespace std;
vector<vector<int>> v;

bool visited[200];

void dfs(int x){
    visited[x]=true;
    for(int i=0;i<v[x].size();i++){
        int next= v[x][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    v.resize(200);
    for(int i=0;i < n ; i++){
        for(int j=i+1;j<n;j++){
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