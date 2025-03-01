#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class A{
  public:
    int cost;
    int x;
    int y;
};

int parent[100];
vector<A> v;

void init(int n){
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
}

bool compare(A a, A b){
    return a.cost<b.cost;
}

int getParent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x] = getParent(parent[x]);
}

void unionNode(int x, int y){
    if(y<x) swap(x, y);
    parent[getParent(y)] = getParent(x);
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    init(n);
    for(int i=0;i<costs.size();i++){
        v.push_back({costs[i][2], costs[i][0], costs[i][1]});
    }
    sort(v.begin(), v.end(), compare);
    
    
    int cnt = 0;
    for(int i=0;i<v.size();i++){
        int x = v[i].x;
        int y = v[i].y;
        int cost = v[i].cost;
        
        if(getParent(x)!=getParent(y)){
            unionNode(x, y);
            cnt++;
            answer+=cost;

            if(cnt == n) break;
        }
    }
    return answer;
}