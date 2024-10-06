#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    pair<char, int> input[1000000];
    int Q_size =0;
    
    for(int i=0;i<operations.size();i++){
        stringstream ss(operations[i]);
        string token;
        int cnt =0;
        while(getline(ss, token, ' ')){
            if(cnt==0){
                input[i].first = token[0];
            }
            else{
                input[i].second = stoi(token);
            }
            cnt++;
        };
    }
    
    
    
    for(int i=0;i<operations.size();i++){
        char ins = input[i].first;
        int value = input[i].second;
        
        if(ins =='I'){
            Q_size++;
            dq.push_back(value);
            sort(dq.begin(), dq.end());
        }
        else{ // ins =='D'
            if(Q_size>0){
                Q_size--;
                if(value == 1){ // 최대값 제거
                    dq.pop_back();
                }else{ // 최솟값 제거
                    dq.pop_front();
                }
            }
        }
    }
    
    if(Q_size==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}