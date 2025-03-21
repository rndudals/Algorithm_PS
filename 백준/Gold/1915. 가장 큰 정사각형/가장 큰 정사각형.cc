#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        string st;
        cin>>st;
        for(int j=1;j<=m;j++){
            arr[i][j] = st[j-1]-'0';
        }
    }
    
    int len = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]==1){
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                len = max(len, dp[i][j]);
            }
        }
    }
    
    cout<<len*len<<'\n';
}
