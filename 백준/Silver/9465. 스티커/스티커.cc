#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int T, N;
int arr[2][100000];
int dp[2][100000];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>T;
    while(T--){
        memset(dp, 0, sizeof(dp));
        cin>>N;
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                cin>>arr[i][j];
            }
        }

        if(N==1){
            cout<< max(arr[1][0], arr[0][0])<<'\n';
            continue;
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];

        for(int j=2;j<N;j++){
            dp[1][j] = arr[1][j] + max(dp[0][j-1], dp[0][j-2]);
            dp[0][j] = arr[0][j] + max(dp[1][j-1], dp[1][j-2]);
        }
        
        cout<<max(dp[0][N-1], dp[1][N-1])<<'\n';
    }
    

    return 0;
}
