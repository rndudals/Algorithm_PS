#include <iostream>
#include <vector>
using namespace std;

int dp1[100000];
int dp2[100000];

int solution(vector<int> sticker)
{
    if(sticker.size()==1) return sticker[0];
    
    int answer =0;
    int size = sticker.size();
    
    // 첫 번째꺼 뜯었을 때
    dp1[0]=sticker[0];
    dp1[1]=sticker[0];
    for(int i=2;i<size-1;i++){
        dp1[i] = max(dp1[i-1], sticker[i]+dp1[i-2]);
    }
    
    // 첫 번째꺼 안뜯었을 때
    dp2[1]=sticker[1];
    for(int i=2;i<size;i++){
        dp2[i] = max(dp2[i-1], sticker[i]+dp2[i-2]);
    }
    
    answer = max(dp1[size-2], dp2[size-1]);
    return answer;
}