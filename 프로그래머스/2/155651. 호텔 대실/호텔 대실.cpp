#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Time {
public:
    int start;
    int end;
};

vector<Time> v;

int arr[1450];  

int makeNum(int h, int m){
    return 60 * h + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    string token1, token2;
    
    // 1) 입력받아 Time 벡터에 저장
    for(int i = 0; i < book_time.size(); i++){
        stringstream ss_start(book_time[i][0]); 
        stringstream ss_end(book_time[i][1]); 
        
        getline(ss_start, token1, ':'); 
        int start_h = stoi(token1);
        getline(ss_start, token1, ':');  
        int start_m = stoi(token1);
        
        getline(ss_end, token2, ':');    
        int end_h = stoi(token2);
        getline(ss_end, token2, ':');    
        int end_m = stoi(token2);
        
        // makeNum()으로 시작·끝 시간 계산
        // (여기서는 청소시간 +10분을 아직 더하지 않음)
        int s = makeNum(start_h, start_m);
        int e = makeNum(end_h, end_m);
        
        // 벡터에 저장
        v.push_back({ s, e });
    }
    
    // 2) 모든 예약에 대해, 배열에 카운팅
    //    '청소시간 10분'을 반영하기 위해 end에 +9 추가
    for(int i = 0; i < (int)v.size(); i++){
        // 실제로는 [start .. end+9] 구간을 사용
        int startIdx = v[i].start;
        int endIdx   = v[i].end + 9;  // 퇴실시간 + 10분 중 인덱스상 9 추가
        
        // 혹시 오버될 여지가 있다면 min() 처리 (예: 1459)
        // endIdx = min(endIdx, 1459);

        for(int j = startIdx; j <= endIdx; j++){
            arr[j]++;
            if(answer < arr[j]){
                answer = arr[j];
            }
        }
    }
    
    return answer;
}
