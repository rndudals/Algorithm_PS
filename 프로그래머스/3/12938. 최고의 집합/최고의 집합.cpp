#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    while(n!=1){
        int k = s/n;
        if(k==0) break;
        n--;
        s-=k;
        answer.push_back(k);
    }
    
    if(n==1){
        answer.push_back(s);
    }
    if(answer.size()==0){
        answer.push_back(-1);
    }
    return answer;
}