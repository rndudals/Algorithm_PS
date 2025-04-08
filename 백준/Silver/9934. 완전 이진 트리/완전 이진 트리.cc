#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

int K;
int arr[1024];
vector<int> v[11];
bool visited[1024];
int S;
int idx=1;

void tree(int n, int dep){
    if(2*n>S){
        visited[n] = true;
        v[dep].push_back(arr[idx++]);
        return;
    }

    if(!visited[2*n]){
        tree(2*n, dep+1);
    }

    visited[n] = true;
    v[dep].push_back(arr[idx++]);

    if(!visited[2*n+1]){
        tree(2*n+1, dep+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>K;
    S = pow(2, K) - 1;
    for(int i=1;i<=S;i++){
        cin>>arr[i];
    }

    tree(1, 1);

    for(int i=1;i<=K;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
