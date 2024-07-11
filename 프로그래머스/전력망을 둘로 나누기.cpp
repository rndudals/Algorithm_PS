#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

vector<int> v[101];
bool block[101][101];
bool visited[101];
vector<int> two;

int bfs(int start){
    int cnt=0;
    queue<int> q;
    visited[start]=true;
    q.push(start);
    cnt++;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i];
            if(block[cur][next]) {continue;}
            if(!visited[next]){
                q.push(next);
                visited[next]=true;
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    for(int i=0;i<wires.size();i++){
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0;i<wires.size();i++){
        memset(visited,0,sizeof(visited));
        block[wires[i][0]][wires[i][1]]=true;
        block[wires[i][1]][wires[i][0]]=true;
        int cnt=0;
        two.clear();
        for(int j=1;j<=wires.size();j++){
            if(!visited[j]){
                two.push_back(bfs(j));
                cnt++;
            }
        }
        if(cnt==2){
            if(answer==-1){answer = abs(two[1]-two[0]);}
            else{
                answer=min(answer, abs(two[1]-two[0]));
            }
        }
        block[wires[i][0]][wires[i][1]]=false;
        block[wires[i][1]][wires[i][0]]=false;
    }
    
    
    return answer;
}