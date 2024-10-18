#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[500];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    bool isProcessing = false;
    int time = 0;
    
    while(time<500000){ 
        for(int i=0;i<jobs.size();i++){
            if(!visited[i] && time>=jobs[i][0]){
                if(!isProcessing) isProcessing = true;
                pq.push({jobs[i][1], jobs[i][0]});
                visited[i]=true;
            }
        }
        
        if(isProcessing){
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();
            time+=a;

            answer += (time - b);
            if(pq.empty()){
               isProcessing = false; 
            }
        }
        else{
            time++;
        }
        
    }
    
    return answer/jobs.size();
}