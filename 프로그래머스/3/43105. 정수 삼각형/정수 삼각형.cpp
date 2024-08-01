#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[501][501];
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int size = triangle.size();
    int answer = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<=i;j++){
            arr[i+1][j+1]=triangle[i][j];
        }
    }

    int m=0;
    for(int i=1;i<=size;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = arr[i][j]+max(dp[i-1][j], dp[i-1][j-1]);
            if(i==triangle.size() && m<dp[i][j]){m=dp[i][j];}
        }
    }
    answer=m;

    
    return answer;
}