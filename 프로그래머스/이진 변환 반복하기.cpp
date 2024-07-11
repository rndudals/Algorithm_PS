#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
int zero_sum;
int cnt;

string changeBinary(int n){
    int on = 0;
    string s="";
    int div = pow(2, 20);
    while(div!=0){
        if(div<=n){
            if(n/div>=1){
                s+='1';
            }
            n = n%div;
            div=div/2;
            on=1;
        }
        else{
            if(on == 1){
                s+='0';
            }
            div=div/2;
        }
        
    }
    
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    while(1){
        cnt++;
        int zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zero++;
            }
        }
        s = changeBinary(s.size()-zero);
        zero_sum += zero;
        if(s.size()==1) break;
    }
    answer.push_back(cnt);
    answer.push_back(zero_sum);
    return answer;
}