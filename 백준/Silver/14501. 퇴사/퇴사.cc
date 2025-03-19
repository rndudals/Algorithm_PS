#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int N;
int ans = 0;
vector<pair<int, int>>v;

void run(int idx, int sum){
    if(idx>=N){
        ans = max(ans, sum);
        return;
    }
    if(idx + v[idx].first <= N){
        run(idx+v[idx].first, sum+v[idx].second);
    }

    run(idx+1, sum);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin>>N;
    for(int i=0;i<N;i++){
        int x, y;
        cin>>x>>y;
        v.push_back({x, y});
    }

    run(0, 0);
    cout<<ans<<'\n';
    return 0;
}
