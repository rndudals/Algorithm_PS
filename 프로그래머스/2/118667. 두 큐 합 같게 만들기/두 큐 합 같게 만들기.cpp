#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

queue<int> q1;
queue<int> q2;
long long sum1=0, sum2=0;

void init(vector<int> queue1, vector<int> queue2){
    for(auto a:queue1){
        q1.push(a);
        sum1+=a;
    }
    
    for(auto a:queue2){
        q2.push(a);
        sum2+=a;
    }
}

int solution(vector<int> queue1, vector<int> queue2) {
    init(queue1, queue2);
    int cnt = 0;
    int answer = 0;
    
    while(sum1!=sum2){
        cnt++;
        if(cnt==600000){
            answer = -1;
            break;
        }
        if(sum1>sum2){
            int f = q1.front();
            sum2+=f;
            q2.push(f);
            q1.pop();
            sum1-=f;
        }else if(sum1<sum2){
            int f = q2.front();
            sum1+=f;
            q1.push(q2.front());
            q2.pop();
            sum2-=f;
        }
        else{ // sum1==sum2
            break;
        }
        if(q1.empty() || q2.empty()){
            answer = -1;
            break;
        }
        answer++;
    }
    return answer;
}