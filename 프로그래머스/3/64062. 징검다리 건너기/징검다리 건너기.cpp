#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    // 이진 탐색의 범위를 stones 배열의 최대 값으로 설정
    int l = 1;
    int r = 200000000; // stones 배열의 최대 값인 200,000,000으로 설정
    
    while(l <= r){
        int mid = l + (r - l) / 2; // 오버플로 방지를 위해 수정
        int cnt = 0;
        bool down = false;
        for(int i = 0; i < stones.size(); i++){
            if(stones[i] < mid){ // 조건 수정: stones[i] < mid
                cnt++;
                if(cnt >= k){ // 연속된 k개의 돌이 mid 미만일 때
                    down = true;
                    break;
                }
            }
            else{
                cnt = 0;
            }
        }
        if(down){
            r = mid - 1; // mid가 너무 큼, 줄여야 함
        }
        else{
            answer = mid; // mid가 유효함, 더 큰 값을 찾기 위해 증가
            l = mid + 1;
        }
    }
    
    return answer;
}
