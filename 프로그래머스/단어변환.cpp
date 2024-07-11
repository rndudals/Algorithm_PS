#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

vector<int> v[52];
vector<string> w;
int dist[52];
void naming(string &begin, vector<string>& words){
    w.push_back(begin);
    for(int i=0;i<words.size();i++){
        w.push_back(words[i]);
    }
    
    for(int i=0;i<w.size();i++){
        for(int j=i+1;j<w.size();j++){
            string a=w[i];
            string b=w[j];
            int cnt=0;
            for(int k=0;k<begin.size();k++){
                if(w[i][k]!=w[j][k]){
                    cnt++;
                }
            }
            if(cnt==1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
}

int bfs(int find){
    queue<int> q;
    dist[0]=0;
    q.push(0);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i];
            if(dist[next]==-1){
                dist[next]=dist[cur]+1;
                q.push(next);
            }
        }
    }
    return dist[find];
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int find = 0;
    // 없을 경우 예외 처리
    for(int i=0;i<words.size();i++){
        if(target==words[i]){
            find=i+1;
        }
    }
    for(int i=0;i<52;i++){
        dist[i]=-1;
    }
    if(find==0){return 0;}

    naming(begin, words);
    return bfs(find);
}