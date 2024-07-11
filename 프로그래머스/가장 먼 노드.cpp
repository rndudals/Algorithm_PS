#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> v;
int dist[20001];
bool visited[20001];
int cnt[20001];

void bfs(int start){
    queue<int> q;
    visited[start]=true;
    q.push(start);
     dist[start]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i];
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
                dist[next]=dist[cur]+1;
                cnt[dist[next]]++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    v.resize(20001);
    
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(1);
    
    for(int i = 1;i<20001 ;i++){
        if(cnt[i]==0){
            answer=cnt[i-1];
            break;
        }
    }
    return answer;
}