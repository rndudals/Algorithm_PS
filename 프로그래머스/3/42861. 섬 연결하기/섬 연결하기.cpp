#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int , pair<int, int>>> v;
int parent[101];

void init(int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}

int getParent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x] = getParent(parent[x]);
}

void unionNode(int a, int b){
    if(a>b){swap(a,b);}
    parent[getParent(b)] = getParent(a);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    init(n);
    
    for(int i=0;i<costs.size();i++){
        v.push_back({costs[i][2], {costs[i][0], costs[i][1]}});
    }
    
    sort(v.begin(), v.end());
    
    
    for(int i=0;i<v.size();i++){
        int cost = v[i].first;
        int start = v[i].second.first;
        int end = v[i].second.second;
        
        if(getParent(start)!=getParent(end)){
            unionNode(start, end);
            answer+=cost;
        }
    }
    return answer;
}