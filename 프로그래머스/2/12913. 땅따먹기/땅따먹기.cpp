#include <iostream>
#include <vector>
using namespace std;

int dp[100001][5];

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for(int i=0;i<land.size();i++){
        for(int j=0;j<4;j++){
            int m = 0;
            for(int k=0;k<4;k++){
                if(k!=j){
                    m = max(m, dp[i-1][k]);
                }
            }
            dp[i][j] = m + land[i][j];
        }
    }
    
    
    for(int i=0;i<4;i++){
        answer = max(answer, dp[land.size()-1][i]);
    }
    return answer;
}

//  1  2  3  5
// 10 11 12 11
// 16 15 13 