#include <string>
#include <vector>
#include <cstring>

using namespace std;
int visited[101];
vector<vector<int>> win;
vector<vector<int>> lose;
int x, y;

void dfs(int c, vector<vector<int>>& graph, int& ch){
    ch++;
    visited[c]=true;
    for(int i=0;i<graph[c].size();i++){
        int next=graph[c][i];
        if(!visited[next]){
            dfs(next, graph, ch);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    win.resize(n+1);
    lose.resize(n+1);
    for(int i=0;i<results.size();i++){
        win[results[i][0]].push_back(results[i][1]);
        lose[results[i][1]].push_back(results[i][0]);
    }
    int answer = 0;
    for(int i=1;i<=n;i++){
        x=-1,y=-1;
        memset(visited, 0, sizeof(visited));
        dfs(i, win, x);
        memset(visited, 0, sizeof(visited));
        dfs(i, lose, y);
        if(x+y==n-1){answer++;}
    }
    return answer;
}