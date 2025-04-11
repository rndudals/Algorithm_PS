#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[1001];

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    for(int i=0;i<players.size();i++){
        int a = players[i]/m;
        
        if(a>arr[i]){
            int n = a-arr[i];
            
            // 서버 증설 기록
            for(int j=i;j<i+k;j++){
                if(j<players.size()){
                    arr[j] += n;
                }
            }
            
            
            // 서버 개수 추가
            answer +=n;
        }
    }
    
    return answer;
}

/*
m명 되면 +1개 
2m명 되면 +2개

k시간동안 운영

return 증설 횟수

*/