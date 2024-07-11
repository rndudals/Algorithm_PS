#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[8];
int ans=0;

void func(int k, vector<vector<int>> dungeons, int cnt){
    if(ans < cnt){ans=cnt;}
    for(int i=0;i<dungeons.size();i++){
        if(visited[i]) {continue;}
        if(dungeons[i][0] <= k){
            visited[i]=true;
            func(k-dungeons[i][1], dungeons, cnt+1);
            visited[i]=false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    func(k, dungeons, 0);
    return ans;
}