#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp[101][101];
int stop[101][101];

int func(int i, int j, int m, int n){
    if(dp[i][j]!=0) return dp[i][j];
    if(i==m && j==n) return 1;
    if(j+1<=n && stop[i][j+1]!=1){
        dp[i][j] =  (dp[i][j]  + func(i, j+1, m, n))%1000000007;
    }
    if(i+1<=m && stop[i+1][j]!=1){
        dp[i][j] = (dp[i][j]  + func(i+1, j, m , n))%1000000007;
    }
    return dp[i][j];
} 

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0;i<puddles.size();i++){
        stop[puddles[i][0]][puddles[i][1]]=1;
    }
    answer = func(1, 1, m ,n);
    
    return answer;
}