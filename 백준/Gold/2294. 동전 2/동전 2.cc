#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int n, k, ans;

int dp[1000001];
int arr[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=k;i++){
        dp[i] = 100000;
    }
    for(int i=1;i<=n;i++){
        int elem = arr[i];
        for(int j=1;j<=k;j++){
            if(j - elem >=0){
                dp[j] = min(dp[j], dp[j-elem]+1);
            }
        }
    }
    if(dp[k]==100000){
        cout<<-1<<'\n';
    }else{
        cout<<dp[k]<<'\n';
    }
}
