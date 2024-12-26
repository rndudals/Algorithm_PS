#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool alphabet[26];
int answer = 0;

void func(string skill, string st){
    for(int i=0;i<st.size();i++){
        if(skill[i]!=st[i]){
            return;
        }
    }
    answer++;
}

int solution(string skill, vector<string> skill_trees) {
   
    
    for(int i=0;i<skill.size();i++){
        alphabet[skill[i]-'A'] = true;
    }
    
    for(int i=0;i<skill_trees.size();i++){
        string st = skill_trees[i];
        string tmp = "";
        
        for(int j=0;j<st.size();j++){
            if(alphabet[st[j]-'A']){
                tmp+=st[j];
            }
        }
        skill_trees[i] = tmp;
    }
    
    for(int i=0;i<skill_trees.size();i++){
        string st = skill_trees[i];
        func(skill, st);
    }
    
    
    return answer;
}