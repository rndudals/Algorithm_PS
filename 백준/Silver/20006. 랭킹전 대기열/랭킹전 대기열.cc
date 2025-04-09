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

int p, m;

vector<vector<pair<int, string>>> v;
vector<pair<int, string>> input;



bool compare(pair<int, string> a, pair<int, string> b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p >> m;
    for(int i=0;i<p;i++){
        string st;
        int n;
        cin>>n>>st;

        input.push_back({n, st});
    }

    v.resize(1);  
    v[0].push_back({input[0].first, input[0].second});

    for(int i=1;i<input.size();i++){
        int n = input[i].first;
        string st = input[i].second;

        int v_size = v.size();
        for(int j=0;j<v_size;j++){
            if(v[j][0].first-10 <= n && n<=v[j][0].first+10){
                if(v[j].size() < m){
                    v[j].push_back({n ,st});
                    break;
                }
            }
            if(j==v_size-1){
                vector<pair<int, string>> tmp;
                tmp.push_back({n, st});
                v.push_back(tmp);
            }
        }
    }

    for(int i=0;i<v.size();i++){
        sort(v[i].begin(), v[i].end(), compare);
    }

    for(int i=0;i<v.size();i++){
        if(v[i].size() == m) cout << "Started!\n";
        else                 cout << "Waiting!\n";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j].first<<" "<<v[i][j].second<<'\n';
        }
    }
    return 0;
}
