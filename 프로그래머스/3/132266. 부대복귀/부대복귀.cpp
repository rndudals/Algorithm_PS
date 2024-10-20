#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[100001];
int dist[100001];

vector<vector<int>> v;
vector<int> answer;

void init(int n, vector<vector<int>> roads, vector<int> sources, int destination){
    v.resize(100001);
    
    for(int i=0;i<roads.size();i++){
        int a = roads[i][0];
        int b = roads[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void bfs(int n, vector<vector<int>> roads, vector<int> sources, int start){
    queue<int> q;
    visited[start]= true;
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int c = q.front();
        q.pop();
        
        for(int i=0;i<v[c].size();i++){
            int n = v[c][i];
            if(!visited[n]){
                q.push(n);
                visited[n] = true;
                dist[n] = dist[c] + 1;
            }
        }
    }
    
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
    init(n, roads, sources, destination);
    
    bfs(n, roads, sources, destination);
       
    for(int i=0;i<sources.size();i++){
        if(!visited[sources[i]]){
            answer.push_back(-1);
        }
        else{
            answer.push_back(dist[sources[i]]);
        }
    }
    
    return answer;
}