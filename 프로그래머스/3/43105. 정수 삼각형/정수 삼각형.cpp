#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[501][501];
int sum[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int size = triangle.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<=i;j++){
            arr[i+1][j+1] = triangle[i][j];
        }
    }
    
    
    for(int i=1;i<=size;i++){
        for(int j=1;j<=i;j++){
            sum[i][j] = arr[i][j] + max(sum[i-1][j], sum[i-1][j-1]);
        }
    }
    
    for(int i=1; i<=size;i++){
        answer = max(sum[size][i], answer);
    }
    
    return answer;
}