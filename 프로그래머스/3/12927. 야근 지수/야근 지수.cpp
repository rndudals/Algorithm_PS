#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt[50001];


long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    int c = n;
    for(int i=0;i<works.size();i++){
        cnt[works[i]]++;
        sum += works[i];
    }
    
    for(int i=50000;i>0;i--){
        if(cnt[i]!=0){
            c--;
            cnt[i]--;
            cnt[i-1]++;
            i++;
            if(c==0) {break;}
        }
    }
    
    if(sum>n){
        for(int i=50000;i>0;i--){
            if(cnt[i]!=0){
                answer += i*i;
                cnt[i]--;
                i++;
            }
        }
    }
    return answer;
}