#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
     for(int i=0;i<participant.size();i++){
        m[participant[i]]++;
    }
    
    for(int i=0;i<completion.size();i++){
        m[completion[i]]--;
    }
    string answer = "";
    for(auto a : participant){
        if(m[a]==1){
            answer=a;
        }
    }
    
    return answer;
}