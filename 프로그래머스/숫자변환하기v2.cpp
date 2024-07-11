#include <string>
#include <vector>

using namespace std;

/*
    DP ÀÌ¿כ
*/
int dp[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    for(int i=0;i<1000001;i++){
        dp[i]=1000000;
    }
    dp[x]=0;
    for(int i=x;i<=y;i++){
        if(i-n >= x){
            if(dp[i] > dp[i-n]+1){
                dp[i] = dp[i-n]+1;
            }
        }
        
        if(i%3==0 && i/3>=x){
            if(dp[i] > dp[i/3]+1){
                dp[i] = dp[i/3]+1;
            }
        }
        
        if(i%2==0 && i/2>=x){
            if(dp[i] > dp[i/2]+1){
                dp[i] = dp[i/2]+1;
            }
        }
    }
    
    answer = dp[y];
    if(dp[y]==1000000){answer =-1;}
    return answer;
}