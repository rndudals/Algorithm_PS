#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[101][101];
int sum[101][101];

#define DIV 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int row = puddles.size();
    
    
    for(int i=0;i<row;i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        arr[x][y] = 1;
    }
    sum[0][1] = 1;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j] == 0){
                sum[i][j] = (sum[i-1][j] + sum[i][j-1])%DIV;
            }
        }
    }
    
    return sum[m][n];
}