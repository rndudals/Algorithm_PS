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
#include <sstream>
using namespace std;

int N;
vector<pair<int, int>> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    int len = 0;
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        len = max(len, y);
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
   int size = v.size();
    // 앞
    int a_pre_x = v[0].first;
    int a_pre_y = v[0].second;
    int a_ans = 0;
    for(int i=1;i<size;i++){
        int x = v[i].first;
        int y = v[i].second;

        if(y>a_pre_y){
            a_ans += a_pre_y * (x - a_pre_x);
            a_pre_x = x; 
            a_pre_y = y ;
        }
    }

    // 뒤
    int b_pre_x = v[size-1].first;
    int b_pre_y = v[size-1].second;
    int b_ans = 0;
    for(int i=size-2;i>=0;i--){
        int x = v[i].first;
        int y = v[i].second;

        if(y>b_pre_y){
            b_ans += b_pre_y * (b_pre_x - x);
            b_pre_x = x; 
            b_pre_y = y;
        }
    }

    int ans = 0;
    ans = a_ans + b_ans + (b_pre_x+1 - a_pre_x)*a_pre_y;
    cout<<ans<<'\n';
    return 0;
}
