#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int N, M, ans;
string st;
int dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    cin>>st;

    
    for(int i=2;i<st.size(); i++){
        if(st[i]=='I'){
            if(st[i-1]=='O' && st[i-2]=='I'){
                dp[i] = dp[i-2]+1;
                if(dp[i]>=N) ans++;
            }
        }
    }

    

    cout<<ans<<'\n';
}
