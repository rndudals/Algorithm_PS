#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <math.h>
#include <unordered_map>

using namespace std;

int N, M;
vector<pair<int, string>> v;

string bs(int n){
    int s = 0;
    int e = v.size();

    while(s<e){
        int mid = (e-s)/2 + s;
        if(v[mid].first < n){
            s = mid+1;
        }else{
            e = mid;
        }
    }
    return v[s].second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;

    int start = 0;
    for(int i=0;i<N;i++){
        string st;
        int x;
        cin >> st >> x;
        v.push_back({x, st});
    }
    for(int i=0;i<M;i++){
        int n;
        cin>>n;
        cout<< bs(n)<<'\n';
    }
    return 0;
}
