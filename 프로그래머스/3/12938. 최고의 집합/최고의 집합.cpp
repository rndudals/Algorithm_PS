#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;    
    if(n>s){
        answer.push_back(-1); 
        return answer; 
    }  
    else{
       for(int i=0; i<n; i++) answer.push_back(s/n);   
        int T=s%n;
       int idx = 0;
        while(T--){
            answer[idx]++;
            idx= (idx+1)%n;
        }      
    }   
    sort(answer.begin(), answer.end());
    return answer;
}