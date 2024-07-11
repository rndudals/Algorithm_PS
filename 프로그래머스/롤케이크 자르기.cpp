#include <string>
#include <vector>
#include <iostream>
using namespace std;

int f_cnt[10001];
int r_cnt[10001];

int solution(vector<int> topping) {
    int answer = 0;
    f_cnt[topping[0]]++;
    int a=1, b=0;
    
    for(int i=1;i<topping.size();i++){
        if(r_cnt[topping[i]] == 0) b++;
        r_cnt[topping[i]]++;
    }
    
    for(int i=1;i<topping.size();i++){
        r_cnt[topping[i]]--;
        if(r_cnt[topping[i]]==0) b--;
        
        if(f_cnt[topping[i]]==0) a++;
        f_cnt[topping[i]]++;
        
        if(a==b) answer++;
    }
    
    return answer;
}