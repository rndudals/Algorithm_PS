#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n;
int x, y;
int m;
bool visited[101];
vector<vector<int>> v;
int check;

void init(){
    v.resize(101);
}

void input(){
    cin>>n;
    cin>>x>>y;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>> a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int cur, int cnt){
    if(cur==y){
        cout<<cnt<<'\n';
        check = 1;
    }
    visited[cur]=true;
    for(int i=0;i<v[cur].size();i++){
        int next = v[cur][i];
        if(!visited[next]){
            dfs(next, cnt+1);
        }
    }
}

void run(){
    dfs(x, 0);
}


void printAnswer(){
    if(check == 0){
        cout<<-1<<'\n';
    }
}

int main(){
    init();
    input();
    run();
    printAnswer();
}