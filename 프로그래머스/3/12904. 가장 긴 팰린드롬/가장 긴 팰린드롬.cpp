#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int answer=1;
    int size = s.size();
    for(int i=0;i<size;i++){
        int cnt = 1;
        for(int j=1;j<size;j++){
            int front = i-j;
            int rear = i+j;
            if(front<0 || rear>size-1) break;
            if(s[front]==s[rear]){
                cnt+=2;
            }
            else{
                break;
            }
        }
        answer = max(answer, cnt);
    }
    
    // abba
    for(int i=1;i<size;i++){
        if(s[i]==s[i-1]){
            int cnt = 2;
            for(int j=1;j<size;j++){
                int front = i-1-j;
                int rear = i+j;
                if(front<0 || rear>size-1) break;
                if(s[front]==s[rear]){
                    cnt+=2;
                }else{
                    break;
                }
            }
            answer = max(answer, cnt);
        }
    }

    return answer;
}