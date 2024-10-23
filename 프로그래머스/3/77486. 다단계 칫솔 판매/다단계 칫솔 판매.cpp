#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, string> m;
map<string, int> mc;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i=0;i<enroll.size();i++){
        m[enroll[i]] = referral[i];
    }
    
    for(int i=0;i<seller.size();i++){
        string k = seller[i];
        int price = amount[i]*100;
        while(k != "-"){
            int b = price / 10; // 추천인에게 전달할 금액
            int a = price - b;  // 자신이 갖는 금액
            mc[k] += a;
            if(b == 0){
                break;
            }
            price = b;
            k = m[k];
        }
    }
    
    for(int i=0;i<enroll.size();i++){
        answer.push_back(mc[enroll[i]]);
    }
    return answer;
}
