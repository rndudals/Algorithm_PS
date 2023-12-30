#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> s;
    for(int i=0;i<commands.size();i++){
         int start = commands[i][0];
         int end = commands[i][1];
         int target = commands[i][2];
            
        s.push_back(array[start-1]);
        
        while(start!=end){
            start++;
            s.push_back(array[start-1]);
            
        }
            
        sort(s.begin(), s.end());
        
        answer.push_back(s[target-1]);
        s.clear();
    }
    
    
    
    
    
    return answer;
}