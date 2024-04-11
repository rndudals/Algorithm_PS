#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/*
    우선순위 큐 사용
*/
int visited[1000001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void func(int x, int n, int y){
    pq.push({0, y});
    while(!pq.empty()){
        int cnt = pq.top().first;
        int cur = pq.top().second;
        
        pq.pop();
        visited[cur] = cnt;
        
        if(!visited[cur - n] && cur - n > 0){
            pq.push({cnt+1, cur - n});
        }
        
        if(cur%3==0 && visited[cur/3] ==0 && cur/3 > 0){
            pq.push({cnt+1, cur/3});
        }
    
        if(cur%2==0 && visited[cur/2] ==0 && cur/2 > 0){
            pq.push({cnt+1, cur/2});
        }
    }
}

int solution(int x, int y, int n) {
    
    func(x, n, y);
    
    int answer = visited[x];
    if(visited[x] == 0) answer=-1;
    if(x==y) answer = 0;
    return answer;
}